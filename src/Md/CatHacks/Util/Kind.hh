<?hh // strict

namespace Md\CatHacks\Util;

interface Kind<T, TA>
{
    public function get(): TA;
}
