<?hh // strict

namespace Md\CatHacks\Util\Functor;

use Md\CatHacks\Types\{Kind,ImmList};
use Md\CatHacks\Std\ImmList\ListFunctor as Functor;

use BadMethodCallException;

trait ListFunctor
{
    public function map<TA,TB>((function(TA):TB) $f): Kind<TB>
    {
        if (!$this instanceof ImmList) {
            throw new BadMethodCallException();
        }
        return Functor::instance()->map($this, $f);
    }
}
