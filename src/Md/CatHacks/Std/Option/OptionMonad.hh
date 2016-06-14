<?hh // strict

namespace Md\CatHacks\Std\Option;

use Md\CatHacks\Categories\Monad;

class OptionMonad extends OptionFlatmap implements Monad
{
    <<__Override>>
    public static function instance(): OptionMonad
    {
        return new OptionMonad();
    }
}
