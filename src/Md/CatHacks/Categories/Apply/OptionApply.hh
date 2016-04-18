<?hh

namespace Md\CatHacks\Categories\Apply;

use Md\CatHacks\Categories\Apply;
use Md\CatHacks\Categories\Functor\OptionFunctor;
use Md\CatHacks\Types\Option;
use Md\CatHacks\Util\Kind;

class OptionApply extends OptionFunctor implements Apply<Option>
{
    public function apply<TA,TB>(Kind<Option, TA> $fa, Kind<Option, (function(TA):TB)> $f): Kind<Option, TB>
    {
        return $f == None() || $fa == None() ? None() : Some(($f->get())($fa->get()));
    }

    public function map2<TA, TB, TZ>(Kind<Option, TA> $fa, Kind<Option, TB> $fb, (function(TA,TB):TZ) $f): Kind<Option, TZ>
    {
        return $fa == None() || $fb == None() ? None() : Some($f($fa->get(), $fb->get()));
    }
}
