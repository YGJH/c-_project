#include <bits/stdc++.h>
using namespace std;

struct Binary_index_tree {
    vector<int> bit;
    inline int lowbit(int x) {return x&-x;}
    void init(int _n){
        int n = _n+1;
        bit.resize(n, 0);
    }
    void update(int value , int index) {
        for(;index;index += lowbit(index))  {
            bit[index]+=value;
        }
    }
    void query(int index){
        int ret = 0;
        for(; index ; index ^= lowbit(index)) {
            ret += bit[index];
        }
    }
};
int main(){

}