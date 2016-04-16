<?hh

use Md\CatHacks\Types\{Some,None};

function Some<T>(T $t): Some<T>
{
    return new Some($t);
}

function None(): None
{
    return new None();
}
