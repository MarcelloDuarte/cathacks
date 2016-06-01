<?hh // decl

namespace spec\Md\CatHacks\Std\ImmList;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Categories\Functor\Invariant;
use Md\CatHacks\Laws\InvariantLaws;
use Md\CatHacks\Laws\FunctorLaws;

use Md\PropertyTesting\Generator\ImmListGenerator as ListGen;
use Md\PropertyTesting\Generator\Function1Generator as FuncGen;

use BadMethodCallException;

use Eris\TestTrait;
use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\StringGenerator as StringGen;
use Eris\Generator\ElementsGenerator as ElementsGen;
use Eris\Generator\OneOfGenerator as OneOfGen;

class ListFunctorSpec extends ObjectBehavior
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
            $this->genRandomList()
        )->then($fa ==>
            expect($this->covariantIdentity($fa))->toBe(true)
        );
    }

    public
    function it_obeys_the_identity_law_of_invariance()
    {
        $this->forAll(
            $this->genRandomList()
        )->then($fa ==>
            expect($this->invariantIdentity($fa))->toBe(true)
        );
    }

    public
    function it_obeys_the_composition_law_of_invariance()
    {
        $this->forAll(
            $this->genRandomList(),
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
            $this->genRandomList(),
            $this->genFunctionIntToString(),
            $this->genFunctionStringToInt()
        )->then(($fa, $f, $g) ==>
            expect($this->covariantComposition($fa, $f, $g))->toBe(true)
        );
    }

    public
    function it_maps_empty_list_to_empty_list()
    {
        $this->map(ImmList(), $x ==> 42)->shouldBeLike(ImmList());
    }

    public
    function it_maps_the_result_of_the_function_to_each_member()
    {
        $this->forAll(
            new ListGen(new IntGen)
        )->then($list ==>
            $this->map($list, $x ==> $x + 1)
                ->shouldBeLike(ImmList(...array_map($x ==> $x + 1, $list->values())))
        );
    }

    public
    function it_does_not_map_through_a_different_kind()
    {
        $this->forAll(
            ElementsGen::fromArray(["Option"]),
            new IntGen
        )->then(($kind, $value) ==>
            $this->shouldThrow(BadMethodCallException::class)->duringMap($kind($value), $x ==> $x + 1)
        );
    }

    private function genRandomList(): ListGen
    {
        return new ListGen(new OneOfGen([new IntGen, new StringGen]));
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
}
