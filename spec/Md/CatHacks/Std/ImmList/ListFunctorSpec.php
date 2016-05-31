<?hh // decl

namespace spec\Md\CatHacks\Std\ImmList;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Categories\Functor\Invariant;
use Md\CatHacks\Laws\InvariantLaws;
use Md\CatHacks\Laws\FunctorLaws;

use BadMethodCallException;

use Eris\TestTrait;
use Eris\Generator\SequenceGenerator as SeqGen;
use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\ElementsGenerator as ElementsGen;

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
            new SeqGen(new IntGen)
        )->then($fa ==>
            expect($this->covariantIdentity(ImmList(...$fa)))->toBe(true)
        );
    }

    public
    function it_obeys_the_identity_law_of_invariance()
    {
        $this->forAll(
            new SeqGen(new IntGen)
        )->then($fa ==>
            expect($this->invariantIdentity(ImmList(...$fa)))->toBe(true)
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
            new SeqGen(new IntGen)
        )->then($list ==>
            $this->map(ImmList(...$list), $x ==> $x + 1)
                ->shouldBeLike(ImmList(...array_map($x ==> $x + 1, $list)))
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
}
