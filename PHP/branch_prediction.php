<?php
$arr = array_fill(0, 1000000, 0); // Predictable sequence
$sum = 0;

$start = microtime(true);
foreach ($arr as $val) {
    if ($val == 0) {
        $sum++;
    }
}
$end = microtime(true);

echo "Execution Time: " . ($end - $start) . " sec\n";
?>
