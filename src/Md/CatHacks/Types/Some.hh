<?hh // strict

namespace Md\CatHacks\Types;

use Md\CatHacks\Categories\Functor\OptionMap;
use Md\CatHacks\Categories\Apply\OptionMap2;
use Md\CatHacks\Types\Option\KindOf;

final class Some<T> implements Option<T>
{
    use KindOf, OptionMap<T>, OptionMap2<T>;

    public function __construct(private T $t) {}

    public function get(): T
    {
        return $this->t;
    }

    public function getOrElse(T $other): T
    {
        return $this->t;
    }

    public function __toString(): string
    {
        return "Some(" . (string) $this->t . ")\n";
    }

    public function isEmpty(): bool
    {
        return false;
    }
}
