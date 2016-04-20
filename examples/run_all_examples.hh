<?hh

require_once dirname(__DIR__) . "/vendor/autoload.php";
require_once "options.hh";
require_once "functor.hh";
require_once "apply.hh";

function main():void
{
    option_examples();
    functor_examples();
    apply_examples();
}
main();
