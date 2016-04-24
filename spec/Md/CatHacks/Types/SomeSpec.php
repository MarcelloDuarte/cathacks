<?php

namespace spec\Md\CatHacks\Types;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

class SomeSpec extends ObjectBehavior
{
    function let()
    {
        $this->beConstructedWith(42);
    }

    function it_is_an_option()
    {
        $this->shouldHaveType('Md\CatHacks\Types\Option');
    }

    function its_value_can_be_accessed()
    {
        $this->get()->shouldReturn(42);
    }

    function it_can_be_printed_nicely()
    {
        $this->__toString()->shouldReturn("Some(42)");
    }
}
