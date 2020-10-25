#!/bin/bash
mkdir build
cd build
if ! [ -z ${GITHUB_WORKSPACE+1} ]
then  
cmake ../src/ -DBoost_INCLUDE_DIR=$BOOST_ROOT_1_72_0/include
else
cmake ../src/ -DBoost_INCLUDE_DIR='/mnt/c/Program Files/Boost/boost_1_74_0/boost_1_74_0'
fi

make

for x in $(ls ../*.desc)
do
y=${x#../}
z=${y%.desc}
./main $x |dot -Tpng > ../imgs/${z}.png
done
