<?hh // strict

use Md\CatHacks\Types\{Option,ImmList,Some,None,Function1};

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

function ImmList<T>(T... $values): ImmList<T>
{
    return new ImmList(new ImmVector($values));
}

function Function1<TA,TB>((function(TA):TB) $f): Function1<TA,TB>
{
    return new Function1($f);
}
