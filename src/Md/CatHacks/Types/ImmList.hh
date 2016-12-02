<?hh // strict

namespace Md\CatHacks\Types;

use Md\CatHacks\Ops\ImmList\ImmListFunctorOps;
use Md\CatHacks\Ops\ImmList\ImmListOps;
use Md\CatHacks\Cats\Functor;
use Md\CatHacks\Utils\ArraySerializable;

abstract class ImmList<+T>
    implements Kind,
               HigherKindedType<T>,
               Functor,
               ArraySerializable<T>
{

	use ImmListFunctorOps<T>;
	use ImmListOps<T>;

	private array<T> $values = [];

    final public function __construct(T ...$values) { switch (get_class($this)) {
        case Cons::class: $this->constructCons(func_num_args(), func_get_args()); break;
        case Nil::class: $this->constructNil(func_num_args()); break;
        default: throw $this->listIsSealed(); }
    }

    public function toArray(): array<T>
    {
    	return $this->values;
    }

    private function constructCons(int $argc, array<T> $argv): void
    {
        if ($argc != 2) {
            throw new \Exception(($argc < 2 ? "not enough" : "too many") . " arguments for constructor List");
        }
        $head = $argv[0];
        $tail = $argv[1];
        if (!$tail instanceof ImmList) {
            throw new \Exception("type mismatch 2nd argument List: expected List, found " .
                ((gettype($tail) == "object") ? get_class($tail) : gettype($tail)));
        }
        $this->values = array_merge([$head], $tail->toArray());
    }

    private function constructNil(int $argc): void
    {
        if ($argc > 0) {
            throw new \Exception("too many arguments for constructor Nil");
        }
        $this->values = [];
    }

    private function listIsSealed(): \Exception
    {
        return new \Exception("List cannot be extended outside namespace");
    }
}