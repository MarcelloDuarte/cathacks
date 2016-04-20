<?hh

namespace Md\CatHacks\Categories\Apply;

use Md\CatHacks\Categories\Apply;
use Md\CatHacks\Categories\Functor\OptionFunctor;
use Md\CatHacks\Types\Option;
use Md\CatHacks\Util\Kind;

class OptionApply<T> extends OptionFunctor<T> implements Apply<T>
{
    public function apply<TB>(Option<T> $fa, Option<(function(T):TB)> $f): Option<TB>
    {
        return $f == None() || $fa == None() ? None() : Some(($f->get())($fa->get()));
    }

    public function map2<TB, TZ>(Option<T> $fa, Option<TB> $fb, (function(T,TB):TZ) $f): Option<TZ>
    {
        return $fa == None() || $fb == None() ? None() : Some($f($fa->get(), $fb->get()));
    }
}
