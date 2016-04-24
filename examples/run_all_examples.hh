<?hh

require_once dirname(__DIR__) . "/vendor/autoload.php";
require_once __DIR__ . "/options.hh";
require_once __DIR__ . "/lists.hh";
require_once __DIR__ . "/functor.hh";

use Md\CatHacks\Types\Kind;

function main(): void
{
    option_examples();
    list_examples();
    functor_examples();
}

function putStrLn<T>(Kind<T> $s): void
{
    echo "$s\n";
}

main();
