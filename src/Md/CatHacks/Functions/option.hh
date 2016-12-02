<?hh // decl

use Md\CatHacks\Types\Option;
use Md\CatHacks\Types\None;
use Md\CatHacks\Types\Some;

function Option<T>(...): Option<T>
{
	return Some(...func_get_args());
}

function Some<T>(...): Some<T>
{
	$value = func_get_args();
	switch(count($value)) {
		
		case 0: return new Some(Unit()); break; // <- this one is the reason for no strict mode here

		case 1: return new Some($value[0]); break;
		default: throw new \Exception(sprintf("Option must take exactly 1 argument, %d given", count($value))); break;
	}
}

function None<T>(...): None<T>
{
	if (func_num_args() > 0) {
		throw new \Exception("None does not take any parameters");
	}
	return None::instance();
}