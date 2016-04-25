<?hh

use Md\CatHacks\Types\{Option,ImmList,Some,None};

function Some<T>(T $value): Option<T>
{
    return new Some($value);
}

function None<T>(): Option<T>
{
    return None::instance();
}

function Option<T>(T $value): Option<T>
{
    return $value === null ? None() : Some($value);
}

function ImmList<T>(...$values): ImmList<T>
{
    return new ImmList(new ImmVector($values));
}
