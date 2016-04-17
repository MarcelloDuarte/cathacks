<?hh

namespace Md\CatHacks\Categories;

use Md\CatHacks\Util\Kind;

interface Functor<T>
{
    public function map<TA,TB>(Kind<T,TA> $fa, (function(TA):TB) $f): Kind<T,TB>;
}
