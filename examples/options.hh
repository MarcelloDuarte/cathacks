<?hh // strict

use Md\CatHacks\Types\Option;

function option_examples(): void
{
    // option type contructors
    echo Some(1); // --> prints Some(1)
    echo None();  // --> prints None

    echo Option(42);   // --> prints Some(42)
    echo Option(null); // --> prints None


    $f = (Option<int> $x): Option<int> ==> $x->isEmpty() ? None() : Some($x->get() * 2);
    $x = ():Option<int> ==> None();
    // $y = ():Option<string> ==> None();
    /*
     * examples/options.hh:17:13,18: Invalid argument (Typing[4110])
     * examples/options.hh:15:18,20: This is an int
     * examples/options.hh:17:20,25: It is incompatible with a string
     * examples/options.hh:15:18,20: Considering that this type argument is invariant with respect to Md\CatHacks\Types\Option
     */

    echo $f($x()); // --> prints None
    // echo $f($y()); // --> prints None
}
