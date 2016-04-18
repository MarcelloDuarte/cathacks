<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Categories\Functor\OptionMap;
use Md\CatHacks\Categories\Apply\OptionMap2;

final class None<T> implements Option<T>
{
    private static $instance;
    use OptionMap, OptionMap2;

    private function __construct() {}
    private function __clone() {}
    public static function instance()
    {
        return self::$instance ?: new None();
    }

    public function __toString()
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
}
