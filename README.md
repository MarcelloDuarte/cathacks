CatHacks
========

A library of functional structures in HackLang

```hack
<?hh // strict

require_once "vendor/autoload.php";

echo Some(1);
echo None();

// option type contructors
echo Option(42);
echo Option(null);

// option functor
echo Some(1)->map($x ==> $x + 1);
echo None()->map($x ==> $x + 1);

// option apply with map2
echo Some(1)->map2(Some(2), ($x, $y) ==> $x + $y);
echo Some(1)->apply(Some($x ==> $x + 3));

$from = (new AccountService)->findAccount(1);
$to = (new AccountService)->findAccount(2);

echo $from;
echo $to;

$amountTotransfer = 50.0;

$from->map2($to, ($x, $y) ==> {
    $x -> withdrawal($amountTotransfer);
    $y -> deposit($amountTotransfer);
});

echo $from;
echo $to;

class Account {
    public function __construct(private int $id, private float $amount) {}
    public function deposit(float $money) { $this->amount += $money; }
    public function withdrawal(float $money) { $this->amount -= $money; }
    public function __toString() { return "Account: #" . $this->id . " £" . $this->amount; }
}

class AccountService {
    public function findAccount($id) {
        switch($id) {
            case 1:
                return Some(new Account($id, 300.0));
            case 2:
                return Some(new Account($id, 500.0));
            default:
                return None();
        }
    }
}

```
