<?hh

namespace Md\PropertyTesting\Generator;

use Md\PropertyTesting\Generator\ImmListGenerator as ListGen;

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

    private function genOption()
    {
        return new MapGen($x ==> Option($x), new IntGen());
    }
}
