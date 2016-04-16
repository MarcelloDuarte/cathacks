<?php

require_once "vendor/autoload.php";

echo Some(1);
echo None();

echo Some(1)->map($x ==> $x + 1);
echo None()->map($x ==> $x + 1);
