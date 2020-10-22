#!/bin/bash
mkdir build
cd build
cmake ../src/ -DBOOST='/mnt/c/Program Files/Boost/boost_1_74_0/boost_1_74_0'
make

for x in $(ls ../*.desc)
do
y=${x#../}
z=${y%.desc}
./main $x |dot -Tpng > ../imgs/${z}.png
done
