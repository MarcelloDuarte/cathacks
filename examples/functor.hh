<?hh // strict

function functor_examples(): void
{
    // option functor
    putStrLn(Some(1)->map($x ==> $x + 1)); // --> prints Some(2)
    putStrLn(None()->map($x ==> $x + 1));  // --> prints None

    // list function
    putStrLn(ImmList(1,2,3)->map($x ==> $x + 1)); // --> prints List(2,3,4)
}
