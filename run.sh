set -e
g++ ac.cpp -o ac
g++ wa.cpp -o wa
for ((i = 0 ;; i ++))
do
    echo python3 gen.py > input
    echo ac < input > ac.out
    echo wa < input > wa.out
    diff ac.out wa.out || break
done