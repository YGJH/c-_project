#include <bits/stdc++.h>
using namespace std;
template<typename T>
ostream &operator<<(ostream& os , vector<T> &v) {
    for(auto &c : v) {
        os << c << ' ';
    }
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &a : v)
        is >> a;
    return is;
}
int32_t main() {
    vector<int> v(10);
    cin >> v;
    cout << v << endl;
    nth_element(v.begin() , v.begin() + 4 , v.end());
    cout << "4th element : " << v[3];
    sort(v.begin() , v.end());
    cout << v[3] << endl;
    return 0;
}