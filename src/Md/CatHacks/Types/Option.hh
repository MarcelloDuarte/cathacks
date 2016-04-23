<?hh // strict

namespace Md\CatHacks\Types;

interface Option<T> extends Kind<T>, OptionFunctor<T>, OptionApply<T>
{
    public function get(): T;
    public function getOrElse(T $other): T;
    public function isEmpty(): bool;
}
