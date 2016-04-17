<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Util\Kind;

interface Option<T> extends Kind<Option, T>
{
    public function get(): T;
    public function getOrElse(T $other): T;
}
