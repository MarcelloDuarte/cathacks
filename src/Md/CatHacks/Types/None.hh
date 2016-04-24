<?hh

namespace Md\CatHacks\Types;

use BadMethodCallException, HH\ImmVector;

final class None<T> extends Option<T>
{
    private static ?None<T> $instance;
    private function __construct() {}
    private function __clone() {}
    public static function instance(): None<T> {
        return self::$instance ?: new None();
    }
    public function get(): T { throw new BadMethodCallException(); }
    public function values(): ImmVector<T> { throw new BadMethodCallException(); }
    public function __toString(): string
    {
        return "None";
    }
}
