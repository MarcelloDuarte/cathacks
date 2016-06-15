<?hh // strict

namespace Md\CatHacks\Util\Monad;

use Md\CatHacks\Std\Option\OptionMonad as Monad;
use Md\CatHacks\Types\Kind;
use Md\CatHacks\Types\Option;

use BadMethodCallException;

trait OptionMonad
{
    public function flatMap<TA,TB>((function(TA):Kind<TB>) $f): Kind<TB>
    {
        if (!$this instanceof Option) {
            throw new BadMethodCallException();
        }
        return Monad::instance()->flatMap($this, $f);
    }


    public function flatten<TA>(): Kind<TA>
    {
        if (!$this instanceof Option) {
            throw new BadMethodCallException();
        }
        return Monad::instance()->flatten($this);
    }
}
