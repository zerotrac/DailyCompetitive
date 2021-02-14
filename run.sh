set -e

cur_dir=$(pwd)

g++ -o ${cur_dir}/$1 ${cur_dir}/$1.cpp -std=c++17 -O3
${cur_dir}/$1 < ${cur_dir}/input.txt
