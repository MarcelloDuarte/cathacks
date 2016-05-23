<?hh // decl

namespace spec\Md\CatHacks\Categories\Applicative;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Categories\Applicative\OptionApplicative;
use BadMethodCallException;

use Eris\TestTrait;
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
class OptionApplicativeSpec extends ObjectBehavior
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
        $this->shouldHaveType(OptionApplicative::class);
    }

    public
    function it_returns_None_when_None_is_applied()
    {
        $this->apply(None(), Option($x ==> $x + 1))->shouldBeLike(None());
    }

    public
    function it_applies_the_result_of_the_function_to_Some()
    {
        $this->forAll(
            new IntGen()
        )->then($number ==>
            $this->apply(Some($number), Option($x ==> $x + 1))->shouldBeLike(Some($number + 1))
        );
    }

    public
    function it_does_not_apply_to_a_different_kind()
    {
        $this->forAll(
            ElementsGen::fromArray(["ImmList"]),
            new IntGen
        )->then(($kind, $value) ==> {
            $this->shouldThrow(BadMethodCallException::class)->duringApply($kind($value), Option($x ==> $x + 1));
        });
    }

    public
    function it_implements_map2()
    {
        $this->forAll(
            new IntGen(), new IntGen
        )->then(($x1, $x2) ==>
            $this->map2(Some($x1), Some($x2), ($x, $y) ==> $x + $y)
                 ->shouldBeLike(Some($x1 + $x2))
        );
    }

    public
    function it_returns_None_when_None_is_mapped_with_map2()
    {
        $this->forAll(
            new IntGen()
        )->then($number ==> {
            $this->map2(None(), Some($number), Option(($x, $y) ==> $x + $y))->shouldBeLike(None());
            $this->map2(Some($number), None(), Option(($x, $y) ==> $x + $y))->shouldBeLike(None());
        });
    }

    public
    function it_implements_pure()
    {
        $this->forAll(
            new IntGen()
        )->then($number ==>
            $this->pure($number)->shouldBeLike(Some($number))
        );
    }
}
