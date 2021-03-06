<?hh

require_once dirname(__DIR__) . "/vendor/autoload.php";
require_once __DIR__ . "/options.hh";
require_once __DIR__ . "/lists.hh";
require_once __DIR__ . "/functor.hh";
require_once __DIR__ . "/applicative.hh";
require_once __DIR__ . "/function1.hh";
require_once __DIR__ . "/flatmap.hh";

use Md\CatHacks\Types\Kind;

function main(): void
{
    option_examples();
    list_examples();
    functor_examples();
    applicative_examples();
    function1_examples();
    flatmap_examples();
}

function putStrLn<T>(Kind<T> $s): void
{
    echo "$s\n";
}

main();
