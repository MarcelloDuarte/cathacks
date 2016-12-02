<?hh

describe("Tuple", () ==> {
	describe("Unit", () ==> {
		it("has arity zero", () ==> {
			expect(Unit()->getArity())->toBe(0);
		});

		it("is a tuples with values", () ==> {
			expect(method_exists(Unit(), "first"))->not->toBe(true);
		});
	});
	describe("Pair", () ==> {
		it("has arity two", () ==> {
			expect(Pair(1,2)->getArity())->toBe(2);
		});

		it("has a first and a second parameter", () ==> {
			expect(Pair(1,2)->first())->toBe(1);
			expect(Pair(1,2)->second())->toBe(2);
		});
	});
});