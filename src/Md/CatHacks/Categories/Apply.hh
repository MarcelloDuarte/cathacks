<?hh // strict

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Option;

interface Apply<T> extends Functor<T>
{
    public function apply<TB>(Option<T> $fa, Option<(function(T):TB)> $f): Option<TB>;

    public function map2<TB, TZ>(Option<T> $fa, Option<TB> $fb, (function(T,TB):TZ) $f): Option<TZ>;
}
