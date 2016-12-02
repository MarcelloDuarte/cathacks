<?hh

use function Md\CatHacks\Functions\show\get_value_to_show as show;

describe("show", () ==> {
    it("prints integers", () ==> {
        expect(show(1))->toBe("1");
    });
    it("prints strings", () ==> {
        expect(show("abc"))->toBe('"abc"');
    });
    it("prints booleans", () ==> {
        expect(show(true))->toBe("true");
        expect(show(false))->toBe("false");
    });
    it("prints null", () ==> {
        expect(show(null))->toBe("null");
    });
    it("prints arrays", () ==> {
        expect(show([1,2,3]))->toBe("[1, 2, 3]");
    });
    it("prints associative arrays", () ==> {
        expect(show(["a" => 1,"b" => 2,"c" => 3]))->toBe('["a" => 1, "b" => 2, "c" => 3]');
    });
    it("prints doubles and floats", () ==> {
        expect(show((float)1.0))->toBe("1.0");
        expect(show((double)1.0))->toBe("1.0");
    });
    it("prints resources", () ==> {
        expect(show(STDIN))->toMatch("/(Resource id \#)\d+/");
    });
    it("prints Options", () ==> {
        expect(show(Option(42)))->toBe("Some(42)");
    });
});