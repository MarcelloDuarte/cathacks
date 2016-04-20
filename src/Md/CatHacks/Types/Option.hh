<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Util\Kind;

interface Option<T> extends Kind<Option, T>, OptionFunctor<T>, OptionApply<T>
{
    public function get(): T;
    public function getOrElse(T $other): T;
    public function isEmpty(): bool;
}
