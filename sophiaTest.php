<?php
    $url = 'https://api.sunrisesunset.io/json?lat=33.951935&lng=-83.357567';                           // Update this with an API website
    $response = file_get_contents($url);
    $data = json_decode($response, true);

    print "<pre>";
    print_r($data);
    print "</pre>";

    $result1 = $data['val1'];               // Update this with a value from the array
    $result2 = $data['val2'];               // Update this with a value from the array
    echo "Result 1: $result1 <br>";         // Echo the value of the first result
    echo "Result 2: $result2 <br>";         // Echo the value of the second result

?>