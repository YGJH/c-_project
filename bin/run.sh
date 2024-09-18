set -e
for((i=0;;i++))
do
    echo "$i"
    python3 gen.py > in
    ./test.exe < in > ac.out
    ./a.exe < in > wa.out
    diff ac.out  wa.out || break
done