#!/bin/bash

if [ -z $1 ]
  then    
    echo -e "\e[33mOops, you forgot to specify C++ file name"
    exit
  fi

# cat >> input.txt
# cat >> output.txt

# clear

# sed -i 's' input.txt
# sed -i 's' output.txt


argument=$1

# Paste your input in input.txt file in the folder you are working and output in output.txt

# to run ->      $ bash test.sh C++_file_name_to_be_executed_without_extension

cp input.txt iput1.txt
cp output.txt oput1.txt

if ! g++ -g -std=c++17 $argument.cpp; then
    exit
fi
iput_NAME=iput
oput_NAME=oput
MY_NAME=my_oput

for test_file in $iput_NAME*
do
    i=$((${#iput_NAME}))
    test_case=${test_file:$i}
    if ! `which time` -o time.out -f "(%es)" ./a.out < $iput_NAME$test_case > $MY_NAME$test_case; then
        echo [1m[31mSample test \#$test_case: Runtime Error[0m `cat time.out`
        echo ========================================
        echo Sample iput \#$test_case
        cat $iput_NAME$test_case
    else
        if diff --brief --ignore-space-change $MY_NAME$test_case $oput_NAME$test_case; then
            echo [1m[32mSample test \#$test_case: Accepted[0m `cat time.out`
        else
            echo [1m[31mSample test \#$test_case: Wrong Answer[0m `cat time.out`
            echo ========================================
            echo input \#:
            cat $iput_NAME$test_case
            echo
            echo ========================================
            echo expected \#:
            cat $oput_NAME$test_case
            echo
            echo ========================================
            echo output \#:
            cat $MY_NAME$test_case
            echo
            echo ========================================
        fi
    fi
done

