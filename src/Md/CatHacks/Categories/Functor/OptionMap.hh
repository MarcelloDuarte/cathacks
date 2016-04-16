<?hh

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Types\Option;

trait OptionMap
{
    public function map<TA,TB>((function(TA):TB) $f): Option<TB>
    {
        return (new OptionFunctor())->map($this, $f);
    }
}
