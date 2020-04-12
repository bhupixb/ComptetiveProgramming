#!/bin/bash
mx=1000
i=1
g++ -std=c++11  gen.cpp -o in0 && ulimit -s 262144 && ulimit -v 1048576

g++ -std=c++11  -W -O2 1.cpp -o out11 && ulimit -s 262144 && ulimit -v 1048576

g++ -std=c++11  -W -O2 brute.cpp -o out12 && ulimit -s 262144 && ulimit -v 1048576

while [ $i -gt 0 ]
do
	echo "#$i"
	# cat in
	./in0 > in
	./out11 < in > out1 
	./out12 < in > out2	
	diff -w out1 out2 > temp || break
	cat out2>output.txt
	# printf " \n " >> output.txt
	i=$((i+1))
done
# if [ $i != 1001 ]
# then
	# clear
	echo "Failed"
	cat in > input.txt
	echo -n "Origi = " > output.txt
	cat out1 >> output.txt
	echo "" >> output.txt
	echo -n "brute = "	>> output.txt
	cat out2 >> output.txt
	echo ""
# fi