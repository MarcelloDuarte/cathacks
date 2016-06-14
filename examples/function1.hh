<?hh // strict

function function1_examples(): void
{
    $f = Function1((string $x):int ==> strlen($x));
    $g = Function1((int $y):bool ==> $y % 2 === 0);

    $h = $f->andThen($g);
    putStrLn(Option($h));
}
