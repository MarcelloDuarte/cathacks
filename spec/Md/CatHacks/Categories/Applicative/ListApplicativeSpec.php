<?hh // decl

namespace spec\Md\CatHacks\Categories\Applicative;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Categories\Applicative\ListApplicative;
use BadMethodCallException;

use Eris\TestTrait;
use Eris\Generator\SequenceGenerator as SeqGen;
use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\ElementsGenerator as ElementsGen;

/**
 * Had to declared file `decl` and use the `public` for methods
 * as hh_client needed this to validate the spec.
 *
 * The reason this spec is has a <?hh openning tag to begin with
 * is that lambda functions with 2 arguments won't be parsed properly
 * without it.
 */
 class ListApplicativeSpec extends ObjectBehavior
{
    use TestTrait;

    public
    function it_is_an_applicative()
    {
        $this->shouldHaveType(Applicative::class);
    }

    public
    function it_can_be_constructed_with_instance()
    {
        $this->beConstructedThrough('instance');
        $this->shouldHaveType(ListApplicative::class);
    }

    public
    function it_returns_an_empty_list_when_an_empty_list_is_applied()
    {
        $this->apply(ImmList(), Option($x ==> $x + 1))->shouldBeLike(ImmList());
    }

    public
    function it_applies_the_result_of_the_function_to_a_List()
    {
        $this->forAll(
            new SeqGen(new IntGen())
        )->then($list ==> {
            $this->apply(ImmList(...$list), Option($x ==> $x + 1))
                ->shouldBeLike(ImmList(...array_map($x ==> $x + 1, $list)));
        });
    }

    public
    function it_does_not_apply_to_a_different_kind()
    {
        $this->forAll(
            ElementsGen::fromArray(["Option"]),
            new IntGen
        )->then(($kind, $value) ==> {
            $this->shouldThrow(BadMethodCallException::class)->duringApply($kind($value), Option($x ==> $x + 1));
        });
    }

    public
    function it_implements_map2()
    {
        $this->forAll(
            new IntGen(), new IntGen()
        )->then(($x1, $x2) ==>
            $this->map2(ImmList($x1), ImmList($x2), ($x, $y) ==> $x + $y)
                 ->shouldBeLike(ImmList($x1 + $x2))
        );

    }

    public
    function it_returns_Empty_when_Empty_is_mapped_with_map2()
    {
        $this->forAll(
            new IntGen()
        )->then($int ==> {
            $this->map2(ImmList(), ImmList(), Option(($x, $y) ==> $x + $y))->shouldBeLike(ImmList());
            $this->map2(ImmList($int), ImmList(), Option(($x, $y) ==> $x + $y))->shouldBeLike(ImmList());
            $this->map2(ImmList(), ImmList($int), Option(($x, $y) ==> $x + $y))->shouldBeLike(ImmList());
        });
    }

    public
    function it_implements_pure()
    {
        $this->forAll(
            new IntGen()
        )->then($int ==>
            $this->pure($int)->shouldBeLike(ImmList($int))
        );
    }
}
