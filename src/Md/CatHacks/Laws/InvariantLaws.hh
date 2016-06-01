<?hh // strict

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Function1;

interface Invariant
{
    public function imap<TA,TB>((function(TA):TB) $f,(function(TB):TA) $g): Kind<TB>;
}

trait InvariantLaws
{
    public function invariantIdentity(Invariant $fa): bool
    {
        return $fa == ($fa->imap(Function1::identity(), Function1::identity()));
    }
}
