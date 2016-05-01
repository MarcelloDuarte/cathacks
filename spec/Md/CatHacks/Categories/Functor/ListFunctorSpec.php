<?php

namespace spec\Md\CatHacks\Categories\Functor;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Functor;

class ListFunctorSpec extends ObjectBehavior
{
    function it_is_a_functor()
    {
        $this->shouldHaveType(Functor::class);
    }

    function it_maps_empty_list_to_empty_list()
    {
        $this->map(ImmList(), $x ==> 42)->shouldBeLike(ImmList());
    }

    function it_maps_the_result_of_the_function_to_each_member()
    {
        $this->map(ImmList(1,2,3), $x ==> $x + 1)->shouldBeLike(ImmList(2,3,4));
    }
}
