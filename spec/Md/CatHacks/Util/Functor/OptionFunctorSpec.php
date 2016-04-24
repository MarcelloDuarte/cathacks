<?php

namespace spec\Md\CatHacks\Util\Functor;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Types\Option;
use Md\CatHacks\Categories\Functor\OptionFunctor;
use Md\CatHacks\Util\Functor\OptionFunctor as OptionFunctorTrait;

class OptionFunctorSpec extends ObjectBehavior
{
    function let()
    {
        $this->beAnInstanceOf(OptionFunctorTraitSpec::class);
    }

    function it_delegates_mapping_to_a_OptionFunctor()
    {
        $f = $x ==> 'some function';
        $some = $this->optionWithOptionMapTrait('value');

        expect($some->map($f))
            ->toBeLike(OptionFunctor::instance()->map($some, $f));
    }

    private function optionWithOptionMapTrait($value)
    {
        return new class($value) extends Option {
            use OptionFunctorTrait;
            public function __construct(private $t) {}
            public function __toString() { return ""; }
            public function get() { return $this->t; }
            public function values() { throw new \Exception(); }
        };
    }
}

class OptionFunctorTraitSpec
{
    use OptionFunctorTrait;
}
