<?hh // strict

namespace Md\CatHacks\Ops\ImmList;

use Md\CatHacks\Types\ImmList;
use Md\CatHacks\Types\HigherKindedType;
use function Functor;

trait ImmListFunctorOps<+TA>
{
	public function map<TB>((function(TA):TB) $f): HigherKindedType<TB>
	{
		if (!$this instanceof ImmList) {
			throw new \BadMethodCallException();
		}
		return Functor(ImmList::class)->map($this, $f);
	}
}