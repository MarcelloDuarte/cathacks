<?hh

namespace Md\CatHacks\Types;

interface Option<T>
{
    public function get(): T;
    public function getOrElse(T $other): T;
}
