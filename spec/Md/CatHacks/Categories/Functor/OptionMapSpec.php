<?php

namespace spec\Md\CatHacks\Categories\Functor;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Types\Option;
use Md\CatHacks\Categories\Functor\{OptionMap,OptionFunctor};
use Md\CatHacks\Categories\Apply\OptionMap2;

class OptionMapSpec extends ObjectBehavior
{
    function it_delegates_mapping_to_a_OptionFunctor()
    {
        $f = $x ==> 'some function';
        $some = $this->optionWithOptionMapTrait('value');

        expect($some->map($f))
            ->toBeLike((new OptionFunctor)->map($some, $f));
    }

    private function optionWithOptionMapTrait($value)
    {
        return new class($value) implements Option {
            use OptionMap, OptionMap2;
            public function __construct(private $t) {}
            public function get() { return $this->t; }
            public function getOrElse($other) { return $this->t; }
            public function isEmpty() { return false; }
        };
    }
}
