<?hh // strict

namespace Md\CatHacks\Types;

interface OptionApply<T>
{
    public function apply<TB>(Option<(function(T):TB)> $f): Option<TB>;
    public function map2<TB, TZ>(Option<TB> $fb, (function(T,TB):TZ) $f): Option<TZ>;
}
