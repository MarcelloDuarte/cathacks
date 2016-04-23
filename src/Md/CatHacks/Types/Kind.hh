<?hh // strict

namespace Md\CatHacks\Types;

interface Kind<T>
{
    public function getKind(): string;
    public function isKindOf(string $kind): bool;
}
