<?hh // strict

namespace Md\CatHacks\Types;

use Md\CatHacks\Util\Applicative\OptionApplicative;

abstract class Option<T> implements Kind<T>
{
    use OptionApplicative;
    public function getKind(): string { return "A"; }
}
