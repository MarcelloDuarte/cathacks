<?hh // strict

namespace Md\CatHacks\Cats;

trait Show
{
    abstract public function toString(): string;

    public function show(): string
    {
        return $this->toString();
    }
}