<?php

function insecureCheck($input, $correct) {
    // Bad case: Leaks timing due to early exit
    for ($i = 0; $i < strlen($correct); $i++) {
        if ($input[$i] !== $correct[$i]) {
            return false; // Timing leak occurs here
        }
    }
    return true;
}

function secureCheck($input, $correct) {
    // Good case: Constant-time comparison
    $diff = 0;
    $len = strlen($correct);
    
    for ($i = 0; $i < $len; $i++) {
        $diff |= ord($input[$i]) ^ ord($correct[$i]);
    }
    
    return $diff === 0;
}

$correctPassword = "secure123";
$input = "secure123";

// Insecure check
$start = microtime(true);
$result = insecureCheck($input, $correctPassword);
$end = microtime(true);
echo "Insecure Check Time: " . (($end - $start) * 1e6) . " µs, Result: " . ($result ? "Match" : "No Match") . "\\n";

// Secure check
$start = microtime(true);
$result = secureCheck($input, $correctPassword);
$end = microtime(true);
echo "Secure Check Time: " . (($end - $start) * 1e6) . " µs, Result: " . ($result ? "Match" : "No Match") . "\\n";

?>
