<?hh

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Types\{Kind,ImmList};

class ListFunctor implements Functor
{
    public function map<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f): Kind<TB>
    {
        switch(true) {
            case $fa == ImmList(): return ImmList(); break;
            case $fa->getKind() !== "F[+A]": throw BadMethodCallException();
            case !$fa instanceof ImmList: throw BadMethodCallException();
            default:
                return ImmList(...array_map($f, $fa->values())); break;
        }
    }

    public static function instance(): ListFunctor
    {
        return new ListFunctor();
    }
}
