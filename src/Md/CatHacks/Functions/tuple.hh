<?hh // strict

use Md\CatHacks\Types\Unit;
use Md\CatHacks\Types\Tuple;
use Md\CatHacks\Types\Pair;

function Unit(): Tuple
{
    return new Unit();
}

function Pair<TA,TB>(TA $first, TB $second): Md\CatHacks\Types\Pair<TA,TB>
{
    return new Md\CatHacks\Types\Pair($first, $second);
}