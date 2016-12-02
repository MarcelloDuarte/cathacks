<?hh

use Md\CatHacks\Cats\Functor\FunctorComposite;
use Md\CatHacks\Cats\Functor\ListFunctor;

use const Md\CatHacks\ImmList;


function Functor(string $kind): FunctorComposite
{
    return FunctorComposite::listFunctor();
}