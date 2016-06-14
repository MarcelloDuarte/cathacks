<?hh // decl

namespace spec\Md\CatHacks\Std\Option;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Laws\MonadLaws;

use Md\CatHacks\Std\Option\OptionMonad;
use Md\CatHacks\Std\Option\OptionFlatmap;
use Md\CatHacks\Std\Option\OptionFunctor;

use Eris\TestTrait;

use Md\PropertyTesting\Generator\RandomContainersGenerator;

class OptionMonadSpec extends ObjectBehavior
{
    use RandomContainersGenerator;
    use TestTrait;
    use MonadLaws;

    public
    function it_is_initializable()
    {
        $this->shouldHaveType(OptionMonad::class);
    }

    public
    function it_is_a_flatmap_and_a_functor()
    {
        $this->shouldHaveType(OptionFlatmap::class);
        $this->shouldHaveType(OptionFunctor::class);
    }

    public
    function it_obeys_the_flatmap_associativity_law()
    {
        $this->forAll(
            $this->genOption(),
            $this->genFunctionIntToFString('Option'),
            $this->genFunctionStringToFInt('Option')
        )->then(($fa, $f, $g) ==>
            expect($this->flapMapAssociativity($fa, $f->get(), $g->get()))->toBe(true)
        );
    }
}
