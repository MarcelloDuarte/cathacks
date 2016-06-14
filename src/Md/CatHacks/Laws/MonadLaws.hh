<?hh // decl

namespace Md\CatHacks\Laws;

trait MonadLaws
{
    public function flapMapAssociativity<TA,TB,TC>(Kind<TA> $fa, (function(TA):Kind<TB>) $f, (function(TB):Kind<TC>) $g): bool
    {
        return $fa->flatMap($f)->flatMap($g) == $fa->flatMap( $a ==> $f($a)->flatMap( $b ==> $g($b)) );
    }

    public function leftIdentity<TA,TB>(Kind<TA> $fa, TA $a, (function(TA):Kind<TB>) $f): bool
    {
        return $fa->pure($a)->flatMap($f) == $f($a);
    }

    public function rightIdentity<TA,TB>(Kind<TA> $fa): bool
    {
        return $fa->flatMap($a ==> $fa->pure($a)) == $fa;
    }
}
