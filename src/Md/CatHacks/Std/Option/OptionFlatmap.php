<?hh // strict

namespace Md\CatHacks\Std\Option;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Std\Option\OptionFunctor;
use Md\CatHacks\Types\Kind;

class OptionFlatmap extends OptionFunctor implements Flatmap
{
    public function flatMap<TA,TB>(Kind<TA> $fa, (function(TA):Kind<TB>) $f): Kind<TB>
    {
        return $fa == None() ? None() : ($f($fa->get()) ?: None());
    }
}
