<?hh // strict

function flatmap_examples():void
{
    putStrLn(ImmList(1,2,3)->flatMap($x ==> Some($x + 1)));
    putStrLn(ImmList(1,2,3)->flatMap($x ==> $x % 2 === 0 ? None() : Some($x + 1)));
    putStrLn(ImmList(1,2,3)->flatMap($x ==> None()));
    putStrLn(ImmList(1,2,3)->flatMap($x ==> ImmList($x + 1, $x)));
    putStrLn(Some(1)->flatMap($x ==> Some($x + 1)));
    putStrLn(Some(1)->flatMap($x ==> None()));
    putStrLn(ImmList(1,2,3)->flatMap($x ==> ImmList(Some($x + 1))));
}
