<?hh // decl

use Md\CatHacks\Types\Nil;
use Md\CatHacks\Types\Cons;
use Md\CatHacks\Types\ImmList;

function ImmList<T>(T ...$values): ImmList<T> { switch(count($values)) {
    case 0: return Nil();
    case 1: return Cons($values[0], Nil());
    default: return Cons($values[0], ImmList(...array_slice($values, 1))); }
}

function Nil<T>(): ImmList<T>
{
    return new Nil();
}

function Cons<T>(T $head, ImmList<T> $tail): ImmList<T>
{
    return new Cons($head, $tail);
}