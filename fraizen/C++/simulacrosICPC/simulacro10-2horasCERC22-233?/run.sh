# g++ -x c++ -g -O2 -std=gnu++20 -static $1.cpp -o $1
g++ --std=gnu++17 $1.cpp -o $1
./$1