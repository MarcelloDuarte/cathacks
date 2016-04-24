<?php

namespace spec\Md\CatHacks\Types;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

class NoneSpec extends ObjectBehavior
{
    function let()
    {
        $this->beConstructedThrough('instance');
    }

    function it_is_an_option()
    {
        $this->shouldHaveType('Md\CatHacks\Types\Option');
    }

    function its_illegal_to_access_the_unit_in_None()
    {
        $this->shouldThrow("BadMethodCallException")->duringGet();
    }

    function it_should_be_printed_as_None()
    {
        $this->__toString()->shouldReturn("None");
    }
}
