set -e

cur_dir=$(pwd)
script_folder=$(dirname "${BASH_SOURCE[0]}")

g++ -o ${cur_dir}/$1 ${cur_dir}/$1.cpp -std=c++17 -O3 -I ${script_folder}/AlgoTemplate/ac-library
${cur_dir}/$1 < ${cur_dir}/input.txt
