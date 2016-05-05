<?hh

namespace Md\CatHacks\Categories\Applicative;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Categories\Functor\OptionFunctor;
use Md\CatHacks\Types\{Kind,Option};

use BadMethodCallException;

class OptionApplicative extends OptionFunctor implements Applicative
{
    public function apply<TA,TB>(Kind<TA> $fa, Kind<(function(TA):TB)> $f): Kind<TB>
    {
        switch(true) {
            case $fa == None(): return None(); break;
            case $f == None(): return None(); break;
            case $fa->getKind() !== "A": throw new BadMethodCallException();
            case !$fa instanceof Option: throw new BadMethodCallException();
            default: return Some( ($f->get()) ($fa->get()) ); break;
        }
    }

    public function map2<TA,TB,TZ>(Kind<TA> $fa, Kind<TB> $fb, (function(TA,TB):TZ) $f): Kind<TZ>
    {
        return $this->apply($fa, $this->map($fb, $b ==> $a ==> $f($a, $b)));
    }

    public static function instance(): OptionApplicative
    {
        return new OptionApplicative();
    }
}
