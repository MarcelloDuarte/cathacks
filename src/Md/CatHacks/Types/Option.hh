<?hh

namespace Md\CatHacks\Types;

use Md\CatHacks\Util\Functor\OptionFunctor;

abstract class Option<T> implements Kind<T>
{
    use OptionFunctor;
    public function getKind(): string { return "A"; }
}
