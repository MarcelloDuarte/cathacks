<?hh // strict

namespace Md\CatHacks\Std\ImmList;

use Md\CatHacks\Categories\Monad;
use Md\CatHacks\Types\Kind;

class ListMonad extends ListFlatmap implements Monad
{
    public function flatten<TA>(Kind<Kind<TA>> $ffa): Kind<TA>
    {
        return $this->flatMap($ffa, $x ==> $x);
    }

    <<__Override>>
    public static function instance(): ListMonad
    {
        return new ListMonad();
    }
}
