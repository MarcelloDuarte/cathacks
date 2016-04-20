<?hh // strict

use Md\CatHacks\Types\Option;

class Account {
    public function __construct(private int $id, private float $amount) {}
    public function deposit(float $money): void { $this->amount += $money; }
    public function withdrawal(float $money): void { $this->amount -= $money; }
    public function __toString(): string { return "Account: #" . $this->id . " £" . $this->amount; }
}

class AccountService {
    public function findAccount(int $id): Option<Account> {
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

function apply_examples(): void
{
    // option apply with map2
    echo Some(1)->map2(Some(2), ($x, $y) ==> $x + $y);
    echo Some(1)->apply(Some($x ==> $x + 3));

    $from = (new AccountService())->findAccount(1);
    $to = (new AccountService())->findAccount(2);

    echo $from;
    echo $to;

    $amountTotransfer = 50.0;

    $from->map2($to, ($x, $y) ==> {
        $x -> withdrawal($amountTotransfer);
        $y -> deposit($amountTotransfer);
    });

    echo $from;
    echo $to;
}
