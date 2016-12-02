<?hh

use Md\CatHacks\Types\ImmList;

describe("Functor", () ==> {
	describe("ImmList", () ==> {
		it("maps over a list", () ==> {
			$listFunctor = Functor(ImmList::class);
			expect($listFunctor->map(ImmList(1,2,3), $x ==> $x + 1))
			    ->toEqual(ImmList(2,3,4));
		});		
	});
});