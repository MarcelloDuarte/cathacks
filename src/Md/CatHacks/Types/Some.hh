<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Categories\Functor\OptionMap;

final class Some<T> implements Option<T>
{
    use OptionMap;

    public function __construct(private T $t) {}

    public function get(): T
    {
        return $this->t;
    }

    public function getOrElse(T $other): T
    {
        return $this->t;
    }

    public function __toString()
    {
        return "Some(" . (string) $this->t . ")\n";
    }
}
