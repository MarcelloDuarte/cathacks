<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Categories\Functor\OptionMap;

final class None<T> implements Option<T>
{
    use OptionMap;

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
