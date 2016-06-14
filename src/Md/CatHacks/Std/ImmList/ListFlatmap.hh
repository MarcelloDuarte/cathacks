<?hh // strict

namespace Md\CatHacks\Std\ImmList;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Std\ImmList\ListFunctor;
use Md\CatHacks\Types\{Kind,None,Option,ImmList};

class ListFlatmap extends ListFunctor implements Flatmap
{
    public function flatMap<TA,TB>(Kind<TA> $fa, (function(TA):Kind<TB>) $f): Kind<TB>
    {
        $b = [];
        foreach ($fa->values() as $a) {
            $tmp = $f($a);
            switch (true) {
                case $f instanceof None:
                case $tmp instanceof None:
                    break;
                case $tmp instanceof ImmList:
                    foreach ($tmp->values() as $value) $b[] = $value;
                    break;
                case $tmp instanceof Option:
                    $b[] = $tmp->get();
                    break;
                default:
                    throw new \BadMethodCallException("Type mismatch");
            }
        }

        return ImmList(...$b);
    }
}
