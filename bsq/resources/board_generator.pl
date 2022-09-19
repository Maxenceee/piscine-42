#!/usr/bin/perl

use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
open(DES,'>', 'board_test.txt') or die $!;
print DES "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print DES "o";
		}
		else {
			print DES ".";
		}
	}
	print DES "\n";
}
close(DES);