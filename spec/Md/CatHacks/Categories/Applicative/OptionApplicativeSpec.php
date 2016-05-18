<?hh // decl

namespace spec\Md\CatHacks\Categories\Applicative;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Categories\Applicative\OptionApplicative;
use BadMethodCallException;

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
        $this->apply(Some(42), Option($x ==> $x + 1))->shouldBeLike(Some(43));
    }

    public
    function it_does_not_apply_to_a_different_kind()
    {
        $this->shouldThrow(BadMethodCallException::class)->duringApply(ImmList(1), Option($x ==> $x + 1));
    }

    public
    function it_implements_map2()
    {
        $this->map2(Some(1), Some(42), ($x, $y) ==> $x + $y)
             ->shouldBeLike(Some(43));
    }

    public
    function it_returns_None_when_None_is_mapped_with_map2()
    {
        $this->map2(None(), Some(42), Option(($x, $y) ==> $x + $y))->shouldBeLike(None());
        $this->map2(Some(42), None(), Option(($x, $y) ==> $x + $y))->shouldBeLike(None());
    }

    public
    function it_implements_pure()
    {
        $this->pure(42)->shouldBeLike(Some(42));
    }
}
