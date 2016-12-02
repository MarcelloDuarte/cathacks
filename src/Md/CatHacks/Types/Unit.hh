<?hh // strict

namespace Md\CatHacks\Types;

final class Unit implements Tuple
{
    public function getArity(): int
    {
    	return 0;
    }
}