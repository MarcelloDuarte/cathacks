<?hh // strict

function functor_examples(): void
{
    // option functor
    echo Some(1)->map($x ==> $x + 1); // --> prints Some(2)
    echo None()->map($x ==> $x + 1);  // --> prints None
}
