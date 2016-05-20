<?php

namespace spec\Md\CatHacks\Categories\Flatmap;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Categories\Functor;

class ListFlatmapSpec extends ObjectBehavior
{
    function it_is_initializable()
    {
        $this->shouldHaveType(Flatmap::class);
    }

    function it_is_also_a_functor()
    {
        $this->shouldHaveType(Functor::class);
    }

    function it_implements_flatmap_for_list()
    {
        $this->flatMap(ImmList(42), $x ==> Some($x + 1))->shouldBeLike(ImmList(43));
        $this->flatMap(ImmList(1,2,3), $x ==> Some($x + 1))->shouldBeLike(ImmList(2,3,4));
        $this->flatMap(ImmList(1,None(),3), $x ==> Some($x + 1))->shouldBeLike(ImmList(2,None(),4));
    }

    function it_implements_flatmap_for_empty()
    {
        $this->flatMap(ImmList(), $x ==> $x + 1)->shouldBeLike(ImmList());
    }

    function it_implements_flatmap_for_functions_returning_none()
    {
        $this->flatMap(ImmList(42), $x ==> None())->shouldBeLike(ImmList());
    }
}
