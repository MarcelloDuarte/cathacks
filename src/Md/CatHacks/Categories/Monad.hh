<?hh // strict

namespace Md\CatHacks\Categories;

use Md\CatHacks\Types\Kind;

interface Monad extends Flatmap
{
    public function flatten<TA>(Kind<Kind<TA>> $ffa): Kind<TA>;
}
