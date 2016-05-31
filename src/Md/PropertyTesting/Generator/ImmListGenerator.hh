<?hh

namespace Md\PropertyTesting\Generator;

use DomainException;

use Eris\Generator;
use Eris\Generator\VectorGenerator;
use Eris\Generator\GeneratedValue;
use Eris\Generator\BooleanGenerator;

class ImmListGenerator implements Generator
{
    public function __construct(private Generator $valueGenerator) {}

    public function __invoke($size)
    {
        $sequenceLength = rand(0, $size);
        return GeneratedValue::fromJustValue(ImmList(...$this->vector($sequenceLength)->__invoke($size)->unbox()));
    }

    private function vector($size)
    {
        return new VectorGenerator($size, $this->valueGenerator);
    }

    public function shrink(GeneratedValue $sequence)
    {
        if (!$this->contains($sequence)) {
            throw new DomainException(
                'Cannot shrink {' . var_export($sequence, true) . '} because ' .
                'it does not belong to the domain of this sequence'
            );
        }

        $willShrinkInSize = (new BooleanGenerator())->__invoke(1);
        if ($willShrinkInSize) {
            return $this->shrinkInSize($sequence);
        }
        if (!$willShrinkInSize) {
            return $this->shrinkTheElements($sequence);
        }
    }

    public function contains(GeneratedValue $sequence)
    {
        return $this->vector(count($sequence->unbox()))->contains($sequence);
    }

    private function shrinkInSize($sequence)
    {
        if (count($sequence->unbox()) === 0) {
            return $sequence;
        }

        $input = $sequence->input();
        $indexOfElementToRemove = array_rand($input);
        unset($input[$indexOfElementToRemove]);
        $input = array_values($input);
        return GeneratedValue::fromValueAndInput(
            array_map(
                function($element) { return $element->unbox(); },
                $input
            ),
            $input,
            'sequence'
        );
    }

    private function shrinkTheElements($sequence)
    {
        return $this->vector(count($sequence))->shrink($sequence);
    }
}
