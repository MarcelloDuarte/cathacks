<?hh // decl

namespace Md\CatHacks\Laws;

use Md\CatHacks\Types\Kind;

trait ApplicativeLaws
{
    public function applicativeIdentity<TA>(Kind<TA> $fa): bool
    {
        return $fa->apply($fa->pure($a ==> $a)) == $fa;
    }
}
