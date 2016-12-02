<?hh

describe("Option", () ==> {
	describe("Some", () ==> {
		it("creates a Some", () ==> {
			expect(Option(42))->toEqual(Some(42));
			expect(Option(43))->not->toEqual(Some(42));
		});

		it("lets get you the enveloped value", () ==> {
			expect(Some(42)->get())->toBe(42);
		});

		it("implements getOrElse", () ==> {
            expect(Some(42)->getOrElse(45))->toBe(42);
		});

		it("implements isEmpty", () ==> {
            expect(Some(42)->isEmpty())->toBe(false);
		});

		it("implements isDefined", () ==> {
            expect(Some(42)->isDefined())->toBe(true);
		});

		it("creates a Some(Unit) when no arguments are given", () ==> {
			expect(Option())->toEqual(Some(Unit()));
		});
	});

	describe("None", () ==> {
		it("creates a singleton None", () ==> {
			expect(None())->toBe(None());
		});

		it("implements getOrElse", () ==> {
            expect(None()->getOrElse(45))->toBe(45);
		});

        it("implements isEmpty", () ==> {
		    expect(None()->isEmpty())->toBe(true);
		});

		it("implements isDefined", () ==> {
            expect(None()->isDefined())->toBe(false);
		});
	});
});