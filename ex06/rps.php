<?php
$str = (string)readline("Choose rock, paper, or scissors: ");
$arr = array("rock", "paper", "scissors");
while (!in_array($str, $arr))
{
	echo "please chose one of those [rock, paper,scissors]\n";
	$str = (string)readline("Choose rock, paper, or scissors: ");
}

$x = rand(0, 2);

if ($arr[$x] == $str)
	echo "Tie\n";
else if (($str == "rock" && $arr[$x] == "scissors") ||
			($str == "paper" && $arr[$x] == "rock") || 
			($str == "scissors" && $arr[$x] == "paper"))
	echo "Congratulations! You won! The computer chose $arr[$x].\n";
else
	echo "Sorry, you lost. The computer chose $arr[$x].\n";

?>