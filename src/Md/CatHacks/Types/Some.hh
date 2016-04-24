<?hh

namespace Md\CatHacks\Types;

use BadMethodCallException, HH\ImmVector;

final class Some<T> extends Option<T>
{
    public function __construct(private T $t) {}
    public function get(): T { return $this->t; }
    public function values(): ImmVector<T> { throw new BadMethodCallException(); }
    public function __toString(): string
    {
        return sprintf("Some(%s)", (string) $this->t);
    }
}
