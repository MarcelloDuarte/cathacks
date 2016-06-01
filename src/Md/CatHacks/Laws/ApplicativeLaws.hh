<?hh // decl

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;

trait ApplicativeLaws
{
    public function applicativeIdentity<TA>(Kind<TA> $fa): bool
    {
        return $fa->apply($fa->pure($a ==> $a)) == $fa;
    }

    public function applicativeHomomorphism<TA, TB>(Kind<TA> $fa, A $a, (function(TA):TB) $f): bool
    {
        return $fa->pure($a)->apply($fa->pure($f)) == $fa->pure($f($a));
    }
}
