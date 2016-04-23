<?hh // strict

namespace Md\CatHacks\Types;

use Md\CatHacks\Categories\Functor\OptionMap;
use Md\CatHacks\Categories\Apply\OptionMap2;
use Md\CatHacks\Types\Option\KindOf;

final class None<T> implements Option<T>
{
    private static ?None<T> $instance;
    use KindOf, OptionMap<T>, OptionMap2<T>;

    private function __construct() {}
    private function __clone(): void {}
    public static function instance(): None<T>
    {
        return self::$instance ?: new None();
    }

    public function __toString(): string
    {
        return "None\n";
    }

    public function get(): T
    {
        throw new \BadMethodCallException();
    }

    public function getOrElse(T $other): T
    {
        return $other;
    }

    public function isEmpty(): bool
    {
        return true;
    }
}
