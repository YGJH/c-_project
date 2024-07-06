set -e
g++ ../problems/ac.cpp -o ac
g++ ../problems/wa.cpp -o wa
for ((i=0;;i++))
do
    echo "$i"
    ./gen_testcases > input
    ./ac < input > ac.out
    ./wa < input > wa.out
    diff ac.out wa.out || break
done