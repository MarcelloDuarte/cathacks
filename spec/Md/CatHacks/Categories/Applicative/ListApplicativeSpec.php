<?php

namespace spec\Md\CatHacks\Categories\Applicative;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Applicative;
use BadMethodCallException;

class ListApplicativeSpec extends ObjectBehavior
{
    function it_is_an_applicative()
    {
        $this->shouldHaveType(Applicative::class);
    }

    function it_returns_an_empty_list_when_an_empty_list_is_applied()
    {
        $this->apply(ImmList(), Option($x ==> $x + 1))->shouldBeLike(ImmList());
    }

    function it_applies_the_result_of_the_function_to_a_List()
    {
        $this->apply(ImmList(1,2,3), Option($x ==> $x + 1))->shouldBeLike(ImmList(2,3,4));
    }

    function it_does_not_apply_to_a_different_kind()
    {
        $this->shouldThrow(BadMethodCallException::class)->duringApply(Option(1), Option($x ==> $x + 1));
    }
}
