<?hh // strict

namespace Md\CatHacks\Cats\Functor;

use Md\CatHacks\Types\HigherKindedType;
use Md\CatHacks\Types\ImmList;
use function ImmList;

class ListFunctor extends FunctorComposite
{
	public function map<TA,TB>(HigherKindedType<TA> $fa, (function(TA):TB) $f): HigherKindedType<TB>
	{
		if (!$fa instanceof ImmList) {
			throw new \BadMethodCallException();
		}
		return ImmList(...array_map($f, $fa->toArray()));
	}
}