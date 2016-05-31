<?hh // strict

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Kind;
use Md\CatHacks\Categories\Functor\Invariant;

interface Functor extends Invariant
{
    public function map<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f): Kind<TB>;
}
