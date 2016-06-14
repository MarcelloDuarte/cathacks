<?hh // strict

namespace Md\CatHacks\Std\ImmList;

use Md\CatHacks\Categories\Monad;

class ListMonad extends ListFlatmap implements Monad
{
    <<__Override>>
    public static function instance(): ListMonad
    {
        return new ListMonad();
    }
}
