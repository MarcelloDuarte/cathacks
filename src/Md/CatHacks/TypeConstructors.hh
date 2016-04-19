<?hh

use Md\CatHacks\Types\{Some,None,Option};
use Md\CatHacks\Util\Kind;

function Some<T>(T $t): Kind<Option, T>
{
    return $t === null ? None::instance() : new Some($t);
}

function None<T>(): Kind<Option, T>
{
    return None::instance();
}

function Option<T>(T $t): Kind<Option, T>
{
    return Some($t);
}
