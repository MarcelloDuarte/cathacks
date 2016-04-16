<?hh

namespace Md\CatHacks\Types;

final class None<T> implements Option<T>
{
    public function __toString()
    {
        return "None\n";
    }

    public function get(): T
    {
        throw new \BadMethodCallException();
    }

    public function getOrElse(T $other): T
    {
        return $other;
    }
}
