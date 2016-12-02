<?hh // strict

namespace Md\CatHacks\Types;

use Md\CatHacks\Cats\Show;
use function Md\CatHacks\Functions\show\get_value_to_show;

abstract class Option<+T>
{
    use Show;

	public function isDefined(): bool
	{
		return get_class($this) == Some::class;
	}

	public function isEmpty(): bool
	{
		return !$this->isDefined();
	}

    abstract public function get(): T;

    public function toString(): string
    {
        return $this->isEmpty() ? "None" : "Some(" . get_value_to_show($this->get()) . ")";
    }
}