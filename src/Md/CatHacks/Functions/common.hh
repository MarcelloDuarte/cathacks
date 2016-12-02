<?php

namespace {
    array_map (function($file) { require_once $file; }, glob(__DIR__ .'/*'));
}