#!/bin/bash

./zenspeed.test 2 2 1000 32 >> reszenspeed.txt
./zenspeed.test 2 3 1000 64 >> reszenspeed.txt
./zenspeed.test 2 4 1000 64 >> reszenspeed.txt
./zenspeed.test 2 5 1000 64 >> reszenspeed.txt
./zenspeed.test 2 6 1000 64 >> reszenspeed.txt
./zenspeed.test 2 7 1000 64 >> reszenspeed.txt
./zenspeed.test 2 8 1000 64 >> reszenspeed.txt
./zenspeed.test 2 9 1000 64 >> reszenspeed.txt
./zenspeed.test 2 10 1000 64 >> reszenspeed.txt
./zenspeed.test 2 11 1000 64 >> reszenspeed.txt
./zenspeed.test 2 12 2000 64 >> reszenspeed.txt
./zenspeed.test 2 13 2000 32 >> reszenspeed.txt

./zenspeed.test 3 2 1000 32 >> reszenspeed.txt
./zenspeed.test 3 3 1000 64 >> reszenspeed.txt
./zenspeed.test 3 4 1000 64 >> reszenspeed.txt
./zenspeed.test 3 5 1000 64 >> reszenspeed.txt
./zenspeed.test 3 6 1000 64 >> reszenspeed.txt
./zenspeed.test 3 7 1000 64 >> reszenspeed.txt
./zenspeed.test 3 8 2000 64 >> reszenspeed.txt
./zenspeed.test 3 9 2000 32 >> reszenspeed.txt

./zenspeed.test 4 2 1000 32 >> reszenspeed.txt
./zenspeed.test 4 3 1000 64 >> reszenspeed.txt
./zenspeed.test 4 4 1000 64 >> reszenspeed.txt
./zenspeed.test 4 5 1000 64 >> reszenspeed.txt
./zenspeed.test 4 6 2000 64 >> reszenspeed.txt
./zenspeed.test 4 7 2000 64 >> reszenspeed.txt
