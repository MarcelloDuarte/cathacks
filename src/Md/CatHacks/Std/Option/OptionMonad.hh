<?hh // strict

namespace Md\CatHacks\Std\Option;

use Md\CatHacks\Categories\Monad;
use Md\CatHacks\Types\Kind;

class OptionMonad extends OptionFlatmap implements Monad
{
    public function flatten<TA>(Kind<Kind<TA>> $ffa): Kind<TA>
    {
        return $this->flatMap($ffa, $x ==> $x);
    }

    <<__Override>>
    public static function instance(): OptionMonad
    {
        return new OptionMonad();
    }
}
