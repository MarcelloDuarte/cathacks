<?hh // strict

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Kind;

interface Applicative extends Functor
{
    public function pure<TA>(TA $a): Kind<TA>;
    public function apply<TA,TB>(Kind<TA> $fa, Kind<(function(TA):TB)> $f): Kind<TB>;
    public function map2<TA,TB,TZ>(Kind<TA> $fa, Kind<TB> $fb, (function(TA,TB):TZ) $f): Kind<TZ>;
}
