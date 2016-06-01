<?hh // decl

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Function1;

interface Covariant
{
    public function map<TA,TB>((function(TA):TB) $f): Covariant;
}

trait FunctorLaws
{
    public function covariantIdentity(Covariant $fa): bool
    {
        return $fa == $fa->map(Function1::identity()->get());
    }

     public function covariantComposition<TA,TB,TC>(Covariant $fa, Function1<TA,TB> $f, Function1<TB,TC> $g): bool
     {
         return $fa->map($f->get())->map($g->get()) == $fa->map($f->andThen($g));
     }
}
