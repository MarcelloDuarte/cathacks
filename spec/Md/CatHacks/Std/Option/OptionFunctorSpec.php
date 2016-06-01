<?hh //decl

namespace spec\Md\CatHacks\Std\Option;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Categories\Functor\Invariant;
use Md\CatHacks\Laws\InvariantLaws;
use Md\CatHacks\Laws\FunctorLaws;

use BadMethodCallException;

use Eris\TestTrait;
use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\ElementsGenerator as ElementsGen;
use Eris\Generator\MapGenerator as MapGen;

class OptionFunctorSpec extends ObjectBehavior
{
    use TestTrait;
    use InvariantLaws;
    use FunctorLaws;

    public
    function it_is_a_functor()
    {
        $this->shouldHaveType(Functor::class);
    }

    public
    function it_is_a_invariant()
    {
        $this->shouldHaveType(Invariant::class);
    }

    public
    function it_obeys_the_identity_law_of_covariance()
    {
        $this->forAll(
            new IntGen()
        )->then($fa ==>
            expect($this->covariantIdentity(Option($fa)))->toBe(true)
        );
    }

    public
    function it_obeys_the_identity_law_of_invariance()
    {
        $this->forAll(
            new IntGen()
        )->then($fa ==>
            expect($this->invariantIdentity(Option($fa)))->toBe(true)
        );
    }

    public
    function it_obeys_the_composition_law_of_invariance()
    {
        $this->forAll(
            $this->genOption(),
            $this->genFunctionIntToString(),
            $this->genFunctionStringToInt(),
            $this->genFunctionStringToBool(),
            $this->genFunctionBoolToString()
        )->then(($fa, $f1, $f2, $g1, $g2) ==>
            expect($this->invariantComposition($fa, $f1, $f2, $g1, $g2))->toBe(true)
        );
    }

    public
    function it_obeys_the_composition_law_of_covariance()
    {
        $this->forAll(
            $this->genOption(),
            $this->genFunctionIntToString(),
            $this->genFunctionStringToInt()
        )->then(($fa, $f, $g) ==>
            expect($this->covariantComposition($fa, $f, $g))->toBe(true)
        );
    }
    public
    function it_maps_None_to_None()
    {
        $this->map(None(), $x ==> 42)->shouldBeLike(None());
    }

    public
    function it_maps_the_result_of_the_function_to_Some()
    {
        $this->forAll(
            new IntGen()
        )->then($number ==>
            $this->map(Some($number), $x ==> $x + 1)->shouldBeLike(Some($number + 1))
        );
    }

    public
    function it_does_not_map_through_a_different_kind()
    {
        $this->forAll(
            ElementsGen::fromArray(["ImmList"]),
            new IntGen()
        )->then(($kind, $value) ==>
            $this->shouldThrow(BadMethodCallException::class)->duringMap($kind($value), $x ==> $x + 1)
        );
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
