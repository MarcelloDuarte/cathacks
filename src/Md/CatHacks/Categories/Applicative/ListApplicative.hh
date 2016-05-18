<?hh

namespace Md\CatHacks\Categories\Applicative;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Categories\Functor\ListFunctor;
use Md\CatHacks\Types\{Kind,ImmList};

use BadMethodCallException;

class ListApplicative extends ListFunctor implements Applicative
{
    public function pure<TA>(TA $a): Kind<TA>
    {
        return ImmList($a);
    }

    public function apply<TA,TB>(Kind<TA> $fa, Kind<(function(TA):TB)> $f): Kind<TB>
    {
        switch(true) {
            case $f == None() : return None();
            case $fa->getKind() !== "F[+A]": throw new BadMethodCallException();
            case !$fa instanceof ImmList: throw new BadMethodCallException();
            case $f instanceof ImmList:
                $values = [];
                foreach ($f->values() as $callback) {
                    $values = array_merge($values, array_map($callback, $fa->values()));
                }
                return ImmList(...$values); break;
            default:
                return ImmList(...array_map($f->get(), $fa->values())); break;
        }
    }

    public function map2<TA,TB,TZ>(Kind<TA> $fa, Kind<TB> $fb, (function(TA,TB):TZ) $f): Kind<TZ>
    {
        return $this->apply($fa, $this->map($fb, $b ==> $a ==> $f($a, $b)));
    }

    public static function instance(): ListApplicative
    {
        return new ListApplicative();
    }
}
