<?hh // strict

namespace Md\CatHacks\Types;

final class Pair<+TA,+TB> implements Tuple
{
	private TA $first;
	private TB $second;

    public function __construct(TA $first, TB $second)
    {
    	$this->first = $first;
    	$this->second = $second;
    }

    public function getArity(): int
    {
    	return 2;
    }

    public function first(): TA
    {
    	return $this->first;
    }

    public function second(): TB
    {
    	return $this->second;
    }
}