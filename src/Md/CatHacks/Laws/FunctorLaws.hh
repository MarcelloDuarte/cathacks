<?hh // strict

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Function1;

interface Covariant
{
    public function map<TA,TB>((function(TA):TB) $f): Kind<TB>;
}

trait FunctorLaws
{
    public function covariantIdentity(Covariant $fa): bool
    {
        return $fa == $fa->map(Function1::identity());
    }
}
