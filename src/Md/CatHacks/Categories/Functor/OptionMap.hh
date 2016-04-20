<?hh // strict

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Types\Option;
use Md\CatHacks\Util\Kind;

trait OptionMap<T>
{
    public function map<TB>((function(T):TB) $f): Option<TB>
    {
        if ($this instanceof Option) {
            return (new OptionFunctor())->map($this, $f);
        }

        throw new \BadMethodCallException(
            "OptionMap requires implementing the Option interface"
        );
    }
}
