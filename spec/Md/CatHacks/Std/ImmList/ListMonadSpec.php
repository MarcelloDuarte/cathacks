<?hh // decl

namespace spec\Md\CatHacks\Std\ImmList;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Laws\MonadLaws;

use Md\CatHacks\Std\ImmList\ListMonad;
use Md\CatHacks\Std\ImmList\ListFlatmap;
use Md\CatHacks\Std\ImmList\ListFunctor;

use Eris\TestTrait;

use Md\PropertyTesting\Generator\RandomContainersGenerator;

class ListMonadSpec extends ObjectBehavior
{
    use RandomContainersGenerator;
    use TestTrait;
    use MonadLaws;

    public
    function it_is_initializable()
    {
        $this->shouldHaveType(ListMonad::class);
    }

    public
    function it_is_a_flatmap_and_a_functor()
    {
        $this->shouldHaveType(ListFlatmap::class);
        $this->shouldHaveType(ListFunctor::class);
    }

    public
    function it_obeys_the_flatmap_associativity_law()
    {
        $this->forAll(
            $this->genRandomList(),
            $this->genFunctionIntToFString('ImmList'),
            $this->genFunctionStringToFInt('ImmList')
        )->then(($fa, $f, $g) ==>
            expect($this->flapMapAssociativity($fa, $f->get(), $g->get()))->toBe(true)
        );
    }
}
