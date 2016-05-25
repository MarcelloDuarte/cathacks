<?hh // strict

namespace Md\CatHacks\Util\Applicative;

use Md\CatHacks\Types\{Kind,Option};
use Md\CatHacks\Std\Option\OptionApplicative as Applicative;
use Md\CatHacks\Util\Functor\OptionFunctor;

use BadMethodCallException;

trait OptionApplicative
{
    use OptionFunctor;

    public function apply<TA,TB>(Kind<(function(TA):TB)> $f): Kind<TB>
    {
        if (!$this instanceof Option) {
            throw new BadMethodCallException();
        }
        return Applicative::instance()->apply($this, $f);
    }

    public function map2<TA,TB,TZ>(Kind<TB> $fb, (function(TA,TB):TZ) $f): Kind<TZ>
    {
        if (!$this instanceof Option) {
            throw new BadMethodCallException();
        }
        return Applicative::instance()->map2($this, $fb, $f);
    }
}
