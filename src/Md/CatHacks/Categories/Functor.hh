<?hh

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Kind;

interface Functor
{
    public function map<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f): Kind<TB>;
}
