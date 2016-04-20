<?hh // strict

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Types\{None,Some,Option};
use Md\CatHacks\Util\Kind;

class OptionFunctor<T> implements Functor<T>
{
    public function map<TB>(Option<T> $fa, (function(T):TB) $f): Option<TB>
    {
        return $fa == None() ? None() : Some($f($fa->get()));
    }
}
