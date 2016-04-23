<?hh // strict

namespace Md\CatHacks\Types\Option;

trait KindOf
{
    public function getKind(): string
    {
        return "Option";
    }

    public function isKindOf(string $kind): bool
    {
        return $kind === "Option";
    }
}
