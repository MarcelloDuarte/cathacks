<?hh // strict

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Option;

interface Functor<T>
{
    public function map<TB>(Option<T> $fa, (function(T):TB) $f): Option<TB>;
}
