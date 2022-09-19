#!/bin/sh

# Map Generation for Tests

make all

perl resources/board_generator.pl 15 15 10
./bsq

perl resources/board_generator.pl 9 9 4
./bsq

perl resources/board_generator.pl 7 9 3
./bsq

perl resources/board_generator.pl 5 9 5
./bsq

perl resources/board_generator.pl 10 10 3
./bsq

perl resources/board_generator.pl 10 7 5
./bsq

perl resources/board_generator.pl 10 5 5
./bsq

perl resources/board_generator.pl 3 3 1
./bsq

perl resources/board_generator.pl 3 5 1
./bsq

perl resources/board_generator.pl 15 15 9
./bsq

perl resources/board_generator.pl 15 15 8
./bsq

perl resources/board_generator.pl 15 15 7
./bsq

perl resources/board_generator.pl 15 15 6
./bsq

perl resources/board_generator.pl 15 15 5
./bsq

perl resources/board_generator.pl 15 15 4
./bsq

perl resources/board_generator.pl 15 15 3
./bsq

perl resources/board_generator.pl 15 15 2
./bsq

perl resources/board_generator.pl 15 15 1
./bsq

perl resources/board_generator.pl 15 15 50
./bsq

make clean