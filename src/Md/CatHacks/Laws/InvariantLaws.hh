<?hh // decl

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Function1;

interface Invariant
{
    public function imap<TA,TB>((function(TA):TB) $f,(function(TB):TA) $g): Invariant;
}

trait InvariantLaws
{
    public function invariantIdentity(Invariant $fa): bool
    {
        return $fa == ($fa->imap(Function1::identity()->get(), Function1::identity()->get()));
    }

    public function invariantComposition<TA,TB,TC>(Invariant $fa, Function1<TA,TB> $f1, Function1<TB,TA> $f2, Function1<TB,TC> $g1, Function1<TC,TB> $g2): bool
    {
        return $fa->imap($f1->get(), $f2->get())->imap($g1->get(), $g2->get()) == $fa->imap($g1->compose($f1)->get(), $f1->compose($g2)->get());
    }
}
