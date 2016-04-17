<?hh

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Types\Option;
use Md\CatHacks\Util\Kind;

trait OptionMap
{
    public function map<TA,TB>((function(TA):TB) $f): Kind<Option, TB>
    {
        if ($this instanceof Option) {
            return (new OptionFunctor())->map($this, $f);
        }

        throw new \BadMethodCallException(
            "OptionMap requires implementing the Option interface"
        );
    }
}
