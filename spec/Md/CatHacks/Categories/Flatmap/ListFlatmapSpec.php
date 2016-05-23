<?php

namespace spec\Md\CatHacks\Categories\Flatmap;

use PhpSpec\ObjectBehavior;
use Prophecy\Argument;

use Md\CatHacks\Categories\Flatmap;
use Md\CatHacks\Categories\Functor;
use Md\CatHacks\Types\None;

use Eris\TestTrait;
use Eris\Generator\SequenceGenerator as SeqGen;
use Eris\Generator\IntegerGenerator as IntGen;
use Eris\Generator\ElementsGenerator as ElementsGen;

class ListFlatmapSpec extends ObjectBehavior
{
    use TestTrait;

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
        $this->forAll(
            new SeqGen(new IntGen())
        )->then($list ==>
            $this->flatMap(ImmList(...$list), $x ==> Some($x + 1))
                ->shouldBeLike(ImmList(...array_map($x ==> $x + 1, $list)))
        );
    }

    function it_keeps_none_when_none_is_passed()
    {
        $this->forAll(
            new SeqGen(ElementsGen::fromArray([None(), 1, 2, 3]))
        )->then($list ==>
            $this->flatMap(ImmList(...$list), $x ==> Some($x + 1))
                ->shouldBeLike(ImmList(
                ...array_map($x ==> ($x instanceof None) ? None() : ($x + 1), $list)
            ))
        );
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
