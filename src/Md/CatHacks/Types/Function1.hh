<?hh // strict

namespace Md\CatHacks\Types;

class Function1<TA,TB>
{
    public function __construct(private (function(TA):TB) $f) {}
    public function __invoke(TA $a):TB { return $this->run($a); }
    public function get():(function(TA):TB) { return $this->f; }

    public function andThen<TC>(Function1<TB,TC> $g): Function1<TA,TC>
    {
        return Function1($x ==> $g->run($this->run($x)));
    }

    public function compose(Function1<TB,TA> $g): Function1<TA,TB>
    {
        return Function1($x ==> $this->run($g->run($x)));
    }

    public static function identity(): Function1<TA,TB>
    {
        return Function1($x ==> $x);
    }

    private function run(TA $a):TB
    {
        return call_user_func($this->f, $a);
    }
}
