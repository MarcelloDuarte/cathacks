<?hh // strict

namespace Md\CatHacks\Types;

final class Some<T> extends Option<T>
{
	private T $value;

	public function __construct(T $value)
	{
		$this->value = $value;
	}

	public function get(): T
	{
		return $this->value;
	}

    public function getOrElse(T $ignored): T
    {
    	return $this->value;
    }
}