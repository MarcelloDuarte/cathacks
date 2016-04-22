<?hh // strict

use Md\CatHacks\Types\Option;

type Amount = float;
type Account = (int, Amount);
type AccountPair = Option<(Option<Account>, Option<Account>)>;

function withdrawal(Option<Account> $account, Amount $amount): Option<Account>
{
    return $account->map($x ==> tuple($x[0], $x[1] - $amount));
}

function deposit(Option<Account> $account, Amount $amount): Option<Account>
{
    return $account->map($x ==> tuple($x[0], $x[1] + $amount));
}

function transfer(Option<Account> $account, Option<Account> $another, Amount $amount): AccountPair
{
    return $account->map2($another, ($x, $y) ==>
        tuple(withdrawal(Option($x), $amount), deposit(Option($y), $amount))
    );
}

function show(Option<Account> $a): void
{
    switch ($a) {
        case None(): echo "None\n"; break;
        default: $a->map($a ==> { echo sprintf("Account #%d £%.2f\n", $a[0], $a[1]); });
    }
}

function apply_examples(): void
{
    $account = Some(tuple(1, 40.0));
    show($account); // --> prints Account #1 £40.00
    $account = withdrawal($account, 20.0);
    show($account); // --> prints Account #1 £20.00
    $account = deposit($account, 30.0);
    show($account); // --> prints Account #1 £50.00

    $another = Some(tuple(2, 0.0));
    show($another); // --> prints Account #2 £0.00

    list($account, $another) = transfer($account, $another, 10.0)->get();

    show($account); // --> prints Account #1 £40.00
    show($another); // --> prints Account #2 £10.00
}
