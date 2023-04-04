#!/usr/bin/perl

print "Enter a string: ";
$str = <STDIN>;
chomp($str);
$res = ($str cmp reverse($str)) ? "The string is not a palindrome.\n" : "The string is a palindrome!\n";
print $res;
