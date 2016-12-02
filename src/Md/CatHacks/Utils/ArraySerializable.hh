<?hh // strict

namespace Md\CatHacks\Utils;

interface ArraySerializable<+T>
{
	public function toArray(): array<T>;
}