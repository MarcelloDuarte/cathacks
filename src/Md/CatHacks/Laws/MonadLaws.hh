<?hh // decl

namespace Md\CatHacks\Laws;

trait MonadLaws
{
    public function flapMapAssociativity<TA,TB,TC>(Kind<TA> $fa, (function(TA):Kind<TB>) $f, (function(TB):Kind<TC>) $g): bool
    {
        return $fa->flatMap($f)->flatMap($g) == $fa->flatMap( $a ==> $f($a)->flatMap( $b ==> $g($b)) );
    }
}
