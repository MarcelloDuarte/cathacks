<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Util\Applicative\ListApplicative;

use HH\ImmVector, BadMethodCallException;

final class ImmList<T> implements Kind<T>
{
    use ListApplicative;
    public function __construct(private ImmVector<T> $values) { }
    public function getKind(): string { return "F[+A]"; }
    public function values(): ImmVector<T> { return $this->values; }
    public function get(): T { throw new BadMethodCallException(); }
    public function __toString()
    {
        return sprintf("List(%s)", implode(",", $this->values->map($x ==> (string) $x)));
    }
}
