set -e
g++ ac.cpp -o ac --std=c++20
g++ wa.cpp -o wa --std=c++20
for ((i = 1;  ; i++))
do
    echo "$i"
    python3 gen.py > input
    ./ac < input > ac.out
    ./wa < input > wa.out
    diff ac.out wa.out || break
done