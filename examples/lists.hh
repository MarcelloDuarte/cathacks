<?hh

function list_examples(): void
{
    putStrLn(ImmList(2,3,4)); // --> List(1,2,3)
    putStrLn(ImmList(Some(1), None(), Some(3))); // --> List(Some(1),None,Some(3))
}
