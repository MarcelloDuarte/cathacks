<?hh // strict

namespace Md\CatHacks\Types;

use Stringish,HH\ImmVector;

interface Kind<+T> extends Stringish
{
    public function getKind(): string;
    public function get(): T;
    public function values(): ImmVector<T>;
}
