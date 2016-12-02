<?hh

namespace Md\CatHacks\Types;

final class None<T> extends Option<T>
{
	private static ?None<T> $instance;

    private function __construct()
    {
    }

    private function __clone(): void
    {
    }

    public static function instance(): None<T>
    {
        return self::$instance ?: self::$instance = new None();
    }

    public function get()
    {
        throw new \BadMethodCallException("get on None");
    }

    public function getOrElse(T $default): T
    {
    	return $default;
    }
}