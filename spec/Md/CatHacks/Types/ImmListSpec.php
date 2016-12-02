<?hh

use Md\Cathacks\Utils\NoSuchElementException;

describe("ImmList", () ==> {
	describe("Nil", () ==> {
		it("is created empty", () ==> {
	         expect(ImmList()->isEmpty())->toBe(true);
	    });

	    it("creates a Nil object", () ==> {
	         expect(ImmList())->toEqual(Nil());
	    });
    });
    describe("Cons", () ==> {
    	it("creates a list with head only", () ==> {
    		expect(ImmList(42))->toEqual(Cons(42, Nil()));
    		expect(ImmList(42))->not->toEqual(Cons(43, Nil()));
    	});

    	it("creates a list with head and tail", () ==> {
    		expect(ImmList(1,2,3))->toEqual(Cons(1, ImmList(2,3)));
    	});
    });

    describe("map", () ==> {
    	it("maps to a lambda", () ==> {
	    	expect(ImmList(1,2,3)->map($x ==> $x + 1))->toEqual(ImmList(2,3,4));
    	});

    	it("returns an empty list, when an empty list is mapped", () ==> {
    		expect(Nil()->map($x ==> $x + 1))->toEqual(Nil());
    	});
    });

    describe("List operations", () ==> {
    	describe("head", () ==> {
    		it("gives you the head of a list", () ==> {
    			expect(ImmList(1,2,3)->head())->toBe(1);
    		});
    		it("complains when getting a head of an empty list", () ==> {
    			expect(() ==> Nil()->head())->toThrow(new NoSuchElementException("head of empty list"));
    		});
    	});
    	describe("tail", () ==> {
    		it("gives you the tail of a list", () ==> {
    			expect(ImmList(1,2,3)->tail())->toEqual(ImmList(2,3));
    		});
    		it("complains when getting a tail of an empty list", () ==> {
    			expect(() ==> Nil()->tail())->toThrow(new BadMethodCallException("tail of empty list"));
    		});
    	});
        describe("last", () ==> {
            it("gives you the last element of a list", () ==> {
                expect(ImmList(1,2,3)->last())->toBe(3);
            });
            it("complains when getting the last element of an empty list", () ==> {
                expect(() ==> Nil()->last())->toThrow(new NoSuchElementException("last of empty list"));
            });
        });
        describe("init", () ==> {
            it("gives you the list except the last element", () ==> {
                expect(ImmList(1,2,3)->init())->toEqual(ImmList(1,2));
            });
            it("complains when getting the init of an empty list", () ==> {
                expect(() ==> Nil()->init())->toThrow(new BadMethodCallException("empty init"));
            });
        });
    	describe("isEmpty", () ==> {
    		it("informs if a list is empty", () ==> {
    			expect(Nil()->isEmpty())->toBe(true);
    		});
    		it("informs if a list is not empty", () ==> {
    			expect(ImmList(1)->isEmpty())->not->toBe(true);
    		});
    	});
        describe("length", () ==> {
            it("informs the number of elements in a list", () ==> {
                expect(ImmList(1,2,3)->length())->toBe(3);
            });
        });
        describe("nth", () ==> {
            it("let you retrieve the nth element of a list", () ==> {
                expect(ImmList(1,2,3)->nth(2))->toEqual(Some(3));
                expect(ImmList(1,2,3)->nth(42))->toEqual(None());
            });
        });
        describe("drop", () ==> {
            it ("drops elements of a list and creates one with the remaining elements", () ==> {
                expect(ImmList(1,2,3)->drop(-2))->toEqual(ImmList(1,2,3));
                expect(ImmList(1,2,3)->drop(2))->toEqual(ImmList(3));
                expect(ImmList(1,2,3)->drop(3))->toEqual(Nil());
                expect(ImmList(1,2,3)->drop(4000))->toEqual(Nil());
            });
        });
        describe("take", () ==> {
            it ("creates a list with the first n given elements", () ==> {
                expect(ImmList(1,2,3)->take(-2))->toEqual(Nil());
                expect(ImmList(1,2,3)->take(1))->toEqual(ImmList(1));
                expect(ImmList(1,2,3)->take(2))->toEqual(ImmList(1,2));
                expect(ImmList(1,2,3)->take(3))->toEqual(ImmList(1,2,3));
                expect(ImmList(1,2,3)->take(3000))->toEqual(ImmList(1,2,3));
            });
        });
        describe("reverse", () ==> {
            it("constructs a list with the reversed order of elements", () ==> {
                expect(ImmList(1,2,3)->reverse())->toEqual(ImmList(3,2,1));
            });
            it("constructs an empty list when reversing an empty list", () ==> {
                expect(Nil()->reverse())->toEqual(Nil());
            });
        });
        describe("Cool list features", () ==> {
            describe("zip", () ==> {
                it("combines two lists into a list of pair of elements of each list", () ==> {

                    expect(ImmList(1,2,3)->zip(ImmList('a', 'b', 'c')))
                        ->toEqual(ImmList(Pair{1,'a'},Pair{2,'b'},Pair{3,'c'}));

                    expect(ImmList(1,2,3)->zip(ImmList('a', 'b')))
                        ->toEqual(ImmList(Pair{1,'a'},Pair{2,'b'}));

                    expect(ImmList(1,2)->zip(ImmList('a', 'b', 'c')))
                        ->toEqual(ImmList(Pair{1,'a'},Pair{2,'b'}));

                });
            });

            describe("splitAt", () ==> {
                it("converts a list into a pair of lists from the splited list", () ==> {
                    expect(ImmList(1,2)->splitAt(0))
                        ->toEqual(Pair{Nil(),ImmList(1,2)});

                    expect(ImmList(1,2)->splitAt(1))
                        ->toEqual(Pair{ImmList(1),ImmList(2)});

                    expect(ImmList(1,2)->splitAt(4))
                        ->toEqual(Pair{ImmList(1,2),Nil()});
                });
            });

            describe("partition", () ==> {
                it("partitions the list into a pair of lists based on a given function", () ==> {
                    expect(Immlist(1,2,3,4)->partition($x ==> $x % 2 == 0))
                        ->toEqual(Pair{ImmList(2,4), ImmList(1,3)});
                });
            });

            describe("mkString", () ==> {
                it("creates a string from a list", () ==> {
                    expect(ImmList('a','b','c')->mkString(""))->toBe("abc");
                });
                it("creates a string from a list of integers", () ==> {
                    expect(ImmList(1,2,3)->mkString(""))->toBe("123");
                });
                it("lets you start and end the string with a pattern", () ==> {
                    expect(ImmList('a','b','c')->mkString("<",":",">"))->toBe("<a:b:c>");
                });
            });
        });
    });
});
