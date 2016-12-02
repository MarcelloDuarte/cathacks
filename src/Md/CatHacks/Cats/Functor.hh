<?hh // strict

namespace Md\CatHacks\Cats;

use Md\CatHacks\Types\HigherKindedType;

interface Functor
{
    public function map<T,TB>((function(T):TB) $f): HigherKindedType<TB>;
}