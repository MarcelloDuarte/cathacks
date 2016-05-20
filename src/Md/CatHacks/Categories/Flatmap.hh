<?hh // strict

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Kind;

interface Flatmap extends Functor
{
    public function flatMap<TA,TB>(Kind<TA> $fa, (function(TA):Kind<TB>) $f): Kind<TB>;
}
