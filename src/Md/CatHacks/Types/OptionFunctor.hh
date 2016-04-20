<?hh // strict

namespace Md\CatHacks\Types;

interface OptionFunctor<T>
{
    public function map<TB>((function(T):TB) $f): Option<TB>;
}
