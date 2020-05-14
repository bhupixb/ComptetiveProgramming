if [ -z $1 ]
  then    
    echo -e "\e[33mOops, you forgot to specify C++ file name"
    exit
  fi

g++ -std=c++17 $1.cpp -O2 -o main
echo "input plz: "
./main

echo
