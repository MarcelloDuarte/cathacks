<?hh // strict

namespace Md\CatHacks\Types;

use Md\CatHacks\Util\Applicative\OptionApplicative;
use Md\CatHacks\Util\Monad\OptionMonad;

abstract class Option<T> implements Kind<T>
{
    use OptionApplicative, OptionMonad;
    public function getKind(): string { return "A"; }
}
