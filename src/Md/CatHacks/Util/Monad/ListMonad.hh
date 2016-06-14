<?hh // strict

namespace Md\CatHacks\Util\Monad;

use Md\CatHacks\Std\ImmList\ListMonad as Monad;
use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\ImmList;

use BadMethodCallException;

trait ListMonad
{
    public function flatMap<TA,TB>((function(TA):Kind<TB>) $f): Kind<TB>
    {
        if (!$this instanceof ImmList) {
            throw new BadMethodCallException();
        }
        return Monad::instance()->flatMap($this, $f);
    }
}
