#!/bin/bash
i=1
g++ -std=c++17 gen.cpp -o generator -O2
g++ -std=c++17 1.cpp -o original -O2
g++ -std=c++17 brute.cpp -o brute -O2
mx=10000
while [ $i -le $mx ]
do
	# Generate input
	./generator > input1.txt
	./original < input1.txt > original_output.txt
	./brute < input1.txt > brute_output.txt
	# diff -w original_output.txt brute_output.txt || break
  if diff --brief --ignore-space-change original_output.txt brute_output.txt; then
    echo \#$i:[1m[32m$test_case Accepted[0m       
	else
		echo [1m[31mSample test \#$test_case: Wrong Answer[0m 
		break
	fi

	i=$((i+1))
done
# echo "I is $i"
if [ $i != $mx ]
then
	cat input1.txt > input.txt
	echo -n "Origi = " > output.txt
	cat original_output.txt >> output.txt
	echo "" >> output.txt
	echo -n "brute = "	>> output.txt
	cat brute_output.txt >> output.txt
	echo ""
fi