<?hh // decl

namespace spec\Md\CatHacks\Categories\Flatmap;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Categories\Functor;

use Eris\TestTrait;
use Eris\Generator\IntegerGenerator as IntGen;

class OptionFlatmapSpec extends ObjectBehavior
{
    use TestTrait;

    public
    function it_is_initializable()
    {
        $this->shouldHaveType(Flatmap::class);
    }

    public
    function it_is_also_a_functor()
    {
        $this->shouldHaveType(Functor::class);
    }

    public
    function it_implements_flatmap_for_some()
    {
        $this->forAll(
            new IntGen()
        )->then($number ==>
            $this->flatMap(Some($number), $x ==> Some($x + 1))->shouldBeLike(Some($number + 1))
        );
    }

    public
    function it_implements_flatmap_for_none()
    {
        $this->flatMap(None(), $x ==> $x + 1)->shouldBeLike(None());
    }

    public
    function it_implements_flatmap_for_functions_returning_none()
    {
        $this->forAll(
            new IntGen()
        )->then($anyNumber ==>
            $this->flatMap(Some($anyNumber), $x ==> None())->shouldBeLike(None())
        );
    }
}
