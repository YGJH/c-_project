#include <iostream>
#include <vector>
using namespace std;

#define lowbit(x)  x&-x
struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;

    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;
void range_update(int l,int r,int v){// 區間加值
    BIT.update(l,v);
    BIT.update(r+1,-v);
}

signed main() {
    return 0;
}
