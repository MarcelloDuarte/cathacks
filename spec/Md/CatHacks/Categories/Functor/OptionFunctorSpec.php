<?hh //decl

namespace spec\Md\CatHacks\Categories\Functor;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Functor;
use BadMethodCallException;

use Eris\TestTrait;
use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\ElementsGenerator as ElementsGen;

class OptionFunctorSpec extends ObjectBehavior
{
    use TestTrait;

    public
    function it_is_a_functor()
    {
        $this->shouldHaveType(Functor::class);
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
            new IntGen
        )->then($number ==>
            $this->map(Some($number), $x ==> $x + 1)->shouldBeLike(Some($number + 1))
        );
    }

    public
    function it_does_not_map_through_a_different_kind()
    {
        $this->forAll(
            ElementsGen::fromArray(["ImmList"]),
            new IntGen
        )->then(($kind, $value) ==>
            $this->shouldThrow(BadMethodCallException::class)->duringMap($kind($value), $x ==> $x + 1)
        );
    }
}
