<?hh

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Function1;

trait FunctorLaws
{
    public function covariantIdentity<TA>(Kind<TA> $fa): bool
    {
        return $fa == $fa->map(Function1::identity());
    }
}
