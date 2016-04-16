<?hh

namespace Md\CatHacks\Categories;

interface Functor<T>
{
    public function map<TA,TB>(T<A> $fa, (function(TA):TB) $f): T<TB>;
}
