<?hh // strict

namespace Md\CatHacks\Util\Functor;

use Md\CatHacks\Types\{Kind,Option};
use Md\CatHacks\Std\Option\OptionFunctor as Functor;

use BadMethodCallException;

trait OptionFunctor
{
    public function map<TA,TB>((function(TA):TB) $f): Kind<TB>
    {
        if (!$this instanceof Option) {
            throw new BadMethodCallException();
        }
        return Functor::instance()->map($this, $f);
    }
}
