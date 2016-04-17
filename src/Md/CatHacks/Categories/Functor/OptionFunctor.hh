<?hh

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Types\{None,Some,Option};
use Md\CatHacks\Util\Kind;

final class OptionFunctor implements Functor<Option>
{
    public function map<TA,TB>(Kind<Option, TA> $fa, (function(TA):TB) $f): Kind<Option, TB>
    {
        return $fa == None() ? None() : Some($f($fa->get()));
    }
}
