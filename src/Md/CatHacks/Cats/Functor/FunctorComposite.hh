<?hh // strict

namespace Md\CatHacks\Cats\Functor;

use Md\CatHacks\Types\HigherKindedType;
use Md\CatHacks\Types\ImmList;

abstract class FunctorComposite
{
	abstract public function map<TA,TB>(HigherKindedType<TA> $fa, (function(TA):TB) $f): HigherKindedType<TB>;

	public static function listFunctor(): FunctorComposite
    {
    	return new ListFunctor(); 
    }
}