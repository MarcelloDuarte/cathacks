<?hh

namespace Md\CatHacks\Categories\Apply;

use Md\CatHacks\Util\Kind;
use Md\CatHacks\Types\Option;

trait OptionMap2
{
    public function apply<TA,TB>(Kind<Option, (function(TA):TB)> $f): Kind <Option, TB>
    {
        if ($this instanceof Option) {
            return (new OptionApply())->apply($this, $f);
        }

        throw new \BadMethodCallException(
            "OptionApply::apply requires implementing the Option interface"
        );
    }

    public function map2<TA, TB, TZ>(Kind<Option, TB> $fb, (function(TA,TB):TZ) $f): Kind<Option, TZ>
    {
        if ($this instanceof Option) {
            return (new OptionApply())->map2($this, $fb, $f);
        }

        throw new \BadMethodCallException(
            "OptionApply::map2 requires implementing the Option interface"
        );
    }

}
