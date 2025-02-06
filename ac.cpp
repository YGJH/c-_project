#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool w = 0; char c ;
template<typename T>
inline void re(T &a) {
c = getchar();a = 0; while(c < '0' || c > '9') w|=(c=='-') , c=getchar();
while(c >= '0' && c <= '9') a = (a<<1) + (a<<3) + (c&15) , c = getchar();
if(w) a=-a;
return ;}
char st[30] ; int kkkk = 0;
template<typename T>
inline void wr(T a) {
if(a==0) { putchar('0') ; return ;}
if(a<0)putchar('-') , a=-a;
while(a) { st[kkkk++] = a % 10 + '0' , a/=10;}
while(kkkk) { putchar(st[--kkkk]);}
return ;}

struct A{
    uint a : 2;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    A a;
    a.a = 15;
    // a = 1;
    cout << a.a << endl;
    
    
    
    return 0;
}
