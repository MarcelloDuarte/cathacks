<?hh // strict

namespace Md\CatHacks\Types;

class Function1<TA,TB> {
    public function __construct(private (function(TA):TB) $f) {}
    public function __invoke(TA $a):TB { return ($this->f)($a); }

    public function andThen<TC>(Function1<TB,TC> $g): Function1<TA,TC>
    {
        $f = $this->f;
        return Function1($x ==> $g($f($x)));
    }

    public function compose(Function1<TB,TC> $g)
    {
        return Function1($x ==> ($this->f)($g($x)));
    }

    public static function identity()
    {
        return Function1($x ==> $x);
    }
}
