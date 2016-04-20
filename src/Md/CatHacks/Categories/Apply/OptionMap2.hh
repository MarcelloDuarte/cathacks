<?hh

namespace Md\CatHacks\Categories\Apply;

use Md\CatHacks\Util\Kind;
use Md\CatHacks\Types\Option;

trait OptionMap2<T>
{
    public function apply<TB>(Option<(function(T):TB)> $f): Option<TB>
    {
        if ($this instanceof Option) {
            return (new OptionApply())->apply($this, $f);
        }

        throw new \BadMethodCallException(
            "OptionApply::apply requires implementing the Option interface"
        );
    }

    public function map2<TB, TZ>(Option<TB> $fb, (function(T,TB):TZ) $f): Option<TZ>
    {
        if ($this instanceof Option) {
            return (new OptionApply())->map2($this, $fb, $f);
        }

        throw new \BadMethodCallException(
            "OptionApply::map2 requires implementing the Option interface"
        );
    }

}
