#!/bin/sh
a=0

while [ $a -lt 10 ]
do
		../tetriminos_generator/./tetri-gen -v -f 26
	   time ./fillit sample.fillit
done

