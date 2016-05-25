<?hh // strict

namespace Md\CatHacks\Std\Option;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Std\Option\OptionFunctor;
use Md\CatHacks\Types\{Kind,Option};

use BadMethodCallException;

class OptionApplicative extends OptionFunctor implements Applicative
{
    public function pure<TA>(TA $a): Kind<TA>
    {
        return Option($a);
    }

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

    <<__Override>>
    public function map<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f): Kind<TB>
    {
        return $this->apply($fa, $this->pure($f));
    }

    public static function instance(): OptionApplicative
    {
        return new OptionApplicative();
    }
}
