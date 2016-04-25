<?hh // strict

function applicative_examples(): void
{
    // option apply
    putStrLn(Some(1)->apply(Some($x ==> $x + 1))); // --> prints Some(2)
    putStrLn(None()->apply(Some($x ==> $x + 1)));  // --> prints None

    // option map2
    putStrLn(Some(1)->map2(Some(2), ($x, $y) ==> $x + $y)); // --> prints Some(3)
    putStrLn(None()->map2(Some(2), ($x, $y) ==> $x + $y));  // --> prints None

    // list apply
    putStrLn(ImmList(1,2,3)->apply(Some($x ==> $x + 1))); // --> prints List(2,3,4)

    // list map2
    putStrLn(ImmList(1,2,3)->map2(ImmList(4,5,6), ($x, $y) ==> $x + $y)); // --> prints List(5,6,7,6,7,8,7,8,9)
}
