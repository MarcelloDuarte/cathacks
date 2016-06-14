<?hh // decl

namespace Md\PropertyTesting\Generator;

use Md\PropertyTesting\Generator\ImmListGenerator as ListGen;

use Md\CatHacks\Types\Kind;

use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\StringGenerator as StringGen;
use Eris\Generator\ElementsGenerator as ElementsGen;
use Eris\Generator\OneOfGenerator as OneOfGen;
use Eris\Generator\MapGenerator as MapGen;

trait RandomContainersGenerator
{
    private function genRandomList(): ListGen
    {
        return new ListGen(new OneOfGen([new IntGen(), new StringGen()]));
    }

    private function genFunctionIntToString(): ElementsGen
    {
        return ElementsGen::fromArray([Function1((int $x):string ==> (string)$x)]);
    }

    private function genFunctionStringToInt(): ElementsGen
    {
        return ElementsGen::fromArray([Function1((string $x) ==> strlen($x))]);
    }

    private function genFunctionStringToBool(): ElementsGen
    {
        return ElementsGen::fromArray([Function1((string $x) ==> strlen($x) % 2 === 0)]);
    }

    private function genFunctionBoolToString(): ElementsGen
    {
        return ElementsGen::fromArray([Function1((bool $x) ==> strlen($x) % 2 === 0)]);
    }

    private function genFunctionIntToFString(mixed $f): mixed
    {
        if (is_callable($f)) {
            return ElementsGen::fromArray([Function1((int $x):Kind<string> ==> \call_user_func_array($f, [(string)$x]))]);
        }
    }

    private function genFunctionStringToFInt(mixed $f): mixed
    {
        if (is_callable($f)) {
            return ElementsGen::fromArray([Function1((string $x):Kind<int> ==> \call_user_func_array($f, [strlen($x)]))]);
        }
    }

    private function genOption()
    {
        return new MapGen($x ==> Option($x), new IntGen());
    }
}
