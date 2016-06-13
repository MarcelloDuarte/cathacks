<?hh // decl

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;

trait ApplicativeLaws
{
    public function applicativeIdentity<TA>(Kind<TA> $fa): bool
    {
        return $fa->apply($fa->pure($a ==> $a)) == $fa;
    }

    public function applicativeHomomorphism<TA, TB>(Kind<TA> $fa, TA $a, (function(TA):TB) $f): bool
    {
        return $fa->pure($a)->apply($fa->pure($f)) == $fa->pure($f($a));
    }

    public function applicativeInterchange<TA,TB>(Kind<TA> $fa, TA $a, Kind<(function(TA):TB)> $ff): bool
    {
        return $fa->pure($a)->apply($ff) == $ff->apply($fa->pure($f ==> $f($a)));
    }

    public function applicativeMap<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f): bool
    {
        return $fa->map($f) == $fa->apply($fa->pure($f));
    }
}
