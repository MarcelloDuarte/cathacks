<?hh // strict

namespace Md\CatHacks\Functions\show;

use Md\CatHacks\Cats\Show;

function show(...): void
{
    array_map($x ==> { echo get_value_to_show($x); }, func_get_args());
}

function get_value_to_show(...): string
{
    $value = func_get_arg(0);
    switch(true) {
        case is_showable($value): return $value->show();
        case is_int($value): return (string)$value;
        case is_string($value): return '"' . $value . '"';
        case is_bool($value): return $value ? "true" : "false";
        case is_null($value): return "null";
        case is_float($value): return ($value == floor($value)) ? sprintf("%.01f", $value) : $value;
        case is_resource($value): return (string)$value;
        case is_array($value):
            if (is_array($value) && is_assoc($value)) {
                $valueToShow = [];
                foreach ($value as $key => $elem) {
                    $valueToShow[] = (is_string($key) ? '"' . $key . '"' : $key) . " => " . get_value_to_show($elem);
                }
                return '[' . implode(", ", $valueToShow) . ']';
            }
            return "[" . implode(", ", array_map($e ==> get_value_to_show($e), $value)) . "]";
        
    }
    return gettype($value);
}

function is_assoc(array<mixed> $value): bool
{
    if (!is_array($value)) {
        return false;
    }
    return array() !== array_diff_key($value, array_keys(array_keys($value)));
}

function is_showable(mixed $value): bool
{
    return !is_object($value) ? false : object_class_uses_trait($value, Show::class);
}

function object_class_uses_trait(mixed $object, string $trait): bool
{
    $usesTrait = $c ==> in_array($trait, class_uses($c));

    $classAndParents = array_merge([get_class($object)], class_parents($object));

    $allParentsAndTraits = $classAndParents;
    array_map($x ==> {
        $allParentsAndTraits = array_merge($allParentsAndTraits, class_uses($x));
    }, $classAndParents);

    $countOfShowTraitUsage = array_sum(array_map($usesTrait, $allParentsAndTraits));

    return (bool)$countOfShowTraitUsage;
}