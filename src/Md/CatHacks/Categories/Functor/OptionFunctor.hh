<?hh

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Types\{None,Some,Option};

final class OptionFunctor implements Functor<Option>
{
    public function map<TA,TB>(Option<TA> $fa, (function(TA):TB) $f): Option<TB>
    {
        return $fa instanceof None ? None() : Some($f($fa->get()));
    }
}
