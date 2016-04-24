<?hh

namespace Md\CatHacks\Util\Applicative;

use Md\CatHacks\Types\{Kind,ImmList};
use Md\CatHacks\Categories\Applicative\ListApplicative as Applicative;
use Md\CatHacks\Util\Functor\ListFunctor;

use BadMethodCallException;

trait ListApplicative
{
    use ListFunctor;
    public function apply<TA,TB>(Kind<(function(TA):TB)> $f): Kind<TB>
    {
        if (!$this instanceof ImmList) {
            throw new BadMethodCallException();
        }
        return Applicative::instance()->apply($this, $f);
    }

    public function map2<TA,TB,TZ>(Kind<TB> $fb, (function(TA,TB):TZ) $f): Kind<TZ>
    {
        if (!$this instanceof ImmList) {
            throw new BadMethodCallException();
        }
        return Applicative::instance()->map2($this, $fb, $f);
    }
}
