<?hh

namespace Md\CatHacks\Types;

final class Some<T> implements Option<T>
{
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
