CatHacks
========

A library of functional structures in HackLang

Options
-------

```bash
$ hhvm -d hhvm.force_hh=true -a
hphpd> require_once "vendor/autoload.php"
hphpd> echo Some(1)
Some(1)
hphpd> echo None()
None
hphpd> echo Option(42)
Some(42)
```

Lists
-----

```bash
hphpd> echo ImmList(2,3,4)
List(1,2,3)
hphpd> echo ImmList(Some(1), None(), Some(3))
List(Some(1),None,Some(3))
```

Functor
-------

```bash
hphpd> echo Some(1)->map($x ==> $x + 1)
Some(2)
hphpd> echo None()->map($x ==> $x + 1)
None
hphpd> echo ImmList(1,2,3)->map($x ==> $x + 1)
List(2,3,4)
```

Applicative
-----------

```bash
hphpd> echo Some(1)->apply(Some($x ==> $x + 3))
Some(4)
hphpd> echo None()->apply(Some($x ==> $x + 1))
None
hphpd> echo Some(1)->map2(Some(2), ($x, $y) ==> $x + $y)
Some(3)
hphpd> echo None()->map2(Some(2), ($x, $y) ==> $x + $y)
None
hphpd> echo ImmList(1,2,3)->apply(Some($x ==> $x + 1))
List(2,3,4)
hphpd> echo ImmList(1,2,3)->map2(ImmList(4,5,6), ($x, $y) ==> $x + $y)
List(5,6,7,6,7,8,7,8,9)
```

Monad
-----

```bash
hphpd> echo ImmList(1,2,3)->flatMap($x ==> Some($x + 1))
List(2,3,4)
hphpd> echo ImmList(1,2,3)->flatMap($x ==> $x % 2 === 0 ? None() : Some($x + 1))
List(2,4)
hphpd> echo ImmList(1,2,3)->flatMap($x ==> None())
List()
hphpd> echo ImmList(1,2,3)->flatMap($x ==> ImmList($x + 1, $x))
List(2,1,3,2,4,3)
hphpd> echo Some(1)->flatMap($x ==> Some($x + 1))
Some(2)
hphpd> echo Some(1)->flatMap($x ==> None())
None
hphpd> echo ImmList(1,2,3)->flatMap($x ==> ImmList(Some($x + 1)))
List(Some(2),Some(3),Some(4))
```
