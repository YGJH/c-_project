#include <bits/stdc++.h>
using namespace std;

template <typename T>
concept Printable = requires(T x) {
    {cout << x} -> same_as < ostream&>;
}

template <Printable T>
void print(const T& value) {
    cout << value << endl;
}

int main() {


    return 0;
}