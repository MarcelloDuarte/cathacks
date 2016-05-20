<?php

namespace spec\Md\CatHacks\Categories\Flatmap;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Categories\Functor;

class OptionFlatmapSpec extends ObjectBehavior
{
    function it_is_initializable()
    {
        $this->shouldHaveType(Flatmap::class);
    }

    function it_is_also_a_functor()
    {
        $this->shouldHaveType(Functor::class);
    }

    function it_implements_flatmap_for_some()
    {
        $this->flatMap(Some(42), $x ==> Some($x + 1))->shouldBeLike(Some(43));
    }

    function it_implements_flatmap_for_none()
    {
        $this->flatMap(None(), $x ==> $x + 1)->shouldBeLike(None());
    }

    function it_implements_flatmap_for_functions_returning_none()
    {
        $this->flatMap(Some(42), $x ==> None())->shouldBeLike(None());
    }
}
