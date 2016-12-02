<?hh // strict

// namespace Md\CatHacks\Laws;

// use const Md\CatHacks\Functions\function1\identity;
// use Md\CatHacks\Cats\Functor;
// use Md\CatHacks\Types\Option;

// trait FunctorLaws
// {
//     public function covariantIdentity<T>(Functor $fa, Option<T> $forArg): bool
//     {
//         return $fa->eqv($fa->map(identity), $forArg);
//     }

//     public function covariantComposition(Functor $fa, Function1 $f, Function1 $g): bool
//     {
//         return $fa->map($f)->map($g)->eqv($fa->map($f->andThen($g)), Some(42));
//     }
// }