<?hh

namespace Md\CatHacks\Categories;

use Md\CatHacks\Util\Kind;

interface Apply<T> extends Functor<T>
{
    public function apply<TA,TB>(Kind <T, TA> $fa, Kind<T, (function(TA):TB)> $f): Kind <T, TB>;

    public function map2<TA, TB, TZ>(Kind<T, TA> $fa, Kind<T, TB> $fb, (function(TA,TB):TZ) $f): Kind<T, TZ>;
}
