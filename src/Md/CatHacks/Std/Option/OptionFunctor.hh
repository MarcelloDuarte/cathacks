<?hh // strict

namespace Md\CatHacks\Std\Option;

use Md\CatHacks\Types\{Kind,Option};
use Md\CatHacks\Categories\Functor;

use BadMethodCallException;

class OptionFunctor implements Functor
{
    public function map<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f): Kind<TB>
    {
        switch(true) {
            case $fa == None(): return None(); break;
            case $fa->getKind() !== "A": throw new BadMethodCallException();
            case !$fa instanceof Option: throw new BadMethodCallException();
            default: return Some($f($fa->get())); break;
        }
    }

    public function imap<TA,TB>(Kind<TA> $fa, (function(TA):TB) $f, (function(TB):TA) $g): Kind<TB>
    {
        return $this->map($fa, $f);
    }

    public static function instance(): OptionFunctor
    {
        return new OptionFunctor();
    }
}
