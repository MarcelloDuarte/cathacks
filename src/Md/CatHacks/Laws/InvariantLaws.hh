<?hh // strict

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Function1;

trait InvariantLaws
{
    public function invariantIdentity<TA>(Kind<TA> $fa): bool
    {
        return $fa == ($fa->imap(Function1::identity(), Function1::identity()));
    }
}
