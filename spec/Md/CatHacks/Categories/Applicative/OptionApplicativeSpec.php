<?hh // strict

namespace spec\Md\CatHacks\Categories\Applicative;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Applicative;
use Md\CatHacks\Categories\Applicative\OptionApplicative;
use BadMethodCallException;

class OptionApplicativeSpec extends ObjectBehavior
{
    function it_is_an_applicative()
    {
        $this->shouldHaveType(Applicative::class);
    }

    function it_returns_None_when_None_is_applied()
    {
        $this->apply(None(), Option($x ==> $x + 1))->shouldBeLike(None());
    }

    function it_applies_the_result_of_the_function_to_Some()
    {
        $this->apply(Some(42), Option($x ==> $x + 1))->shouldBeLike(Some(43));
    }

    function it_does_not_apply_to_a_different_kind()
    {
        $this->shouldThrow(BadMethodCallException::class)->duringApply(ImmList(1), Option($x ==> $x + 1));
    }

    function it_can_be_constructed_with_instance()
    {
        $this->beConstructedThrough('instance');
        $this->shouldHaveType(OptionApplicative::class);
    }

    function it_returns_None_when_None_is_mapped_with_map2()
    {
        $this->map2(None(), Some(42), Option(($x, $y) ==> $x + $y))->shouldBeLike(None());
        $this->map2(Some(42), None(), Option(($x, $y) ==> $x + $y))->shouldBeLike(None());
    }
}
