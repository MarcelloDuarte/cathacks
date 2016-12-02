<?hh // strict

namespace Md\CatHacks\Ops\ImmList;

use Md\CatHacks\Utils\ArraySerializable;
use Md\CatHacks\Utils\NoSuchElementException;
use Md\CatHacks\Types\ImmList;
use Md\CatHacks\Types\Option;
use function ImmList;
use HH\ImmVector;

trait ImmListOps<+T>
{
	require implements ArraySerializable<T>;

	public function head(): T
	{
		if ($this->isEmpty()) {
			throw new NoSuchElementException("head of empty list");
		}

		return $this->toArray()[0];
	}

	public function tail(): ImmList<T>
	{
		if ($this->isEmpty()) {
			throw new \BadMethodCallException("tail of empty list");
		}

		return ImmList(...array_slice($this->toArray(), 1));
	}

	public function last(): T
	{
        if ($this->isEmpty()) {
            throw new NoSuchElementException("last of empty list");
        }

		return $this->toArray()[$this->length() - 1];
	}

    public function init(): ImmList<T>
    {
        if ($this->isEmpty()) {
            throw new \BadMethodCallException("empty init");
        }

        return ImmList(...array_slice($this->toArray(), 0, $this->length() - 1));
    }

	public function isEmpty(): bool
    {
    	return $this->length() == 0;
    }

    public function length(): int
    {
        return count($this->toArray());
    }

    public function nth(int $index): Option<T>
    {
        return array_key_exists($index, $this->toArray()) ? Some($this->toArray()[$index]) : None();
    }

    public function drop(int $n): ImmList<T>
    {
        return ImmList(...array_slice($this->toArray(), $n < 0 ? 0 : $n));
    }

    public function take(int $n): ImmList<T>
    {
        return ImmList(...array_slice($this->toArray(), 0, $n < 0 ? 0 : $n));
    }

    public function reverse(): ImmList<T>
    {
        return ImmList(...array_reverse($this->toArray()));
    }

    public function zip<TB>(ImmList<TB> $list): ImmList<Pair<T,TB>>
    {
        $one = new ImmVector($this->toArray());
        $another = new ImmVector($list->toArray());
        return ImmList(...$one->zip($another)->toArray());
    }

    public function splitAt(int $index): Pair<ImmList<T>,ImmList<T>>
    {
        if (!$this instanceof ImmList) {
            throw new \BadMethodCallException();
        }

        switch (true) {
            case $index == 0: return Pair{Nil(), clone $this};
            case $index >= $this->length(): return Pair{clone $this, Nil()}; 
            default:
                return Pair{
                    ImmList(...array_slice($this->toArray(), 0, $index)),
                    ImmList(...array_slice($this->toArray(), $index))
                };
        }
    }

    public function partition((function(T):bool) $condition): Pair<ImmList<T>,ImmList<T>>
    {
        $trues = $falses = [];
        foreach ($this->toArray() as $value) { switch ($result = call_user_func($condition, $value)) {
            case true: $trues[] = $value; break;
            case false: $falses[] = $value; break;
            default: throw $this->callableMustReturnBoolean($result); }
        }
        return Pair{ImmList(...$trues), ImmList(...$falses)};
    }

    public function mkString(...): string
    {
        array_map(($arg) ==> {
            if (!is_string($arg)) {
                throw new \BadMethodCallException("mkString only take string arguments");
            }
        }, func_get_args());

        if (func_num_args() === 1) {
            return implode(func_get_arg(0), $this->toArray());
        } elseif (func_num_args() === 3) {
            return func_get_arg(0) . implode(func_get_arg(1), $this->toArray()) . func_get_arg(2);
        }
        
        throw new \BadMethodCallException("wrong number of arguments for mkString, should be 1 or 3, " . func_num_args() . " given");
    }

    private function callableMustReturnBoolean(mixed $result): \Exception
    {
        return new \BadMethodCallException(sprintf("partition must be passed a callable that returns a boolean, %s returned",
            gettype($result)));
    }
}