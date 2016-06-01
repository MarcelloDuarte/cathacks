<?hh // strict

namespace Md\CatHacks\Categories\Functor;

use Md\CatHacks\Types\Kind;

interface Invariant
{
    public function imap<TA,TB>(Kind<TA> $fa,(function(TA):TB) $f,(function(TB):TA) $g): Kind<TB>;
}
