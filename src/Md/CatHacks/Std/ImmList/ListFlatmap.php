<?hh // strict

namespace Md\CatHacks\Std\ImmList;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Std\ImmList\ListFunctor;
use Md\CatHacks\Types\{Kind,None};

class ListFlatmap extends ListFunctor implements Flatmap
{
    public function flatMap<TA,TB>(Kind<TA> $fa, (function(TA):Kind<TB>) $f): Kind<TB>
    {
        $b = [];
        foreach ($fa->values() as $a) {
            if (!$a instanceof None && ($tmp = $f($a)) == None()) {
                return ImmList();
            }
            $b[] = $a instanceof None ? None() : ($tmp == None() ? $tmp : $tmp->get());
        }

        return ImmList(...$b);
    }
}
