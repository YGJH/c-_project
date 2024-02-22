#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define cl(x) (x<<1)
#define cr(x) (x<<1)+1
#define N 400'500
#define mmax(a,b) (a>b)?a:b;
#define mmin(a,b) (a<b)?a:b;
int arr[N];
// The single update version
    int seg[4*N];
inline void pull_1(int id){
    seg[id]=seg[cl(id)]|seg[cr(id)];
}
inline void pull_2(int id) {
    seg[id]=seg[cl(id)]^seg[cr(id)];
}
void build(int id,int l,int r , int lay){
    if(l==r){
        seg[id]=arr[l];
        return ;
    }
    int mid=(l+r)>>1;
    if(lay){
        build(cl(id),l,mid,0);
        build(cr(id),mid+1,r,1);
        pull_2(id);
    }
    else{
        build(cl(id),l,mid,1);
        build(cr(id),mid+1,r,0);
        pull_1(id);
    }

}
void update(int id,int l,int r,int x,int v){
    if(l==r){
        seg[id]=v;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid){
        update(cl(id),l,mid,x,v);    
    }
    if(mid<x){
        update(cr(id),mid+1,r,x,v);  
    }
    // pull(id);
}
int query(int id,int l,int r,int sl,int sr , int lay){
    if(sl<=l&&r<=sr){//目前這個區間在查詢區間內
        return seg[id];
    }
    int mid=(l+r)>>1,res=0;
    if(lay) {
        if(sl<=mid){//左區間跟查詢區間有交集
            res^=query(cl(id),l,mid,sl,sr,1);
        }
        // else if(res == 0) {res = query(cl(id) , l , mid , sl , sr , 0);}
        if(mid<sr){//右區間跟查詢區間有交集
            res^=query(cr(id),mid+1,r,sl,sr,1);
        }
        // else if(res == 0) {res = query(cr(id) , mid + 1 , r , sl , sr , 0);}
 
    }
    else {
        if(l<=mid){//左區間跟查詢區間有交集
            res|=query(cl(id),l,mid,sl,sr,1);
        }
        // else if(res==0) res=query(cl(id) , l , mid , sl , sr , 1);
        if(mid<sr){//右區間跟查詢區間有交集
            res|=query(cr(id),mid+1,r,sl,sr,0);
        }
        // else if(res==0) res = query(cr(id) , mid + 1, r , sl , sr , 1);
    }
    return res;
}
inline int poww(int a , int b) {
    int ret = 1;
    for( ; b;  b>>= 1 , a*=a) {
        if(b&1) ret*=a;
    }
    return ret;
}

inline void re(int &a) {
    char c=getchar();
    bool w=0;
    a=0;
    int now = 1;
    while(c!='-'&&c<48) {c=getchar();}
    if(c=='-')w|=1,c=getchar();
    while(c>=48 && c <= 58) {
        a+=now*(c-'0');
        now*=10;
        c=getchar();
    }
    if(w)a=-a;
    return ;
}
inline void wr(int a) {
    int now = 0 , nu[50];
    if(a==0)putchar('0');
    if(a<0)putchar('-') , a=-a;
    while(a) {
        nu[now++] = a % 10 ; a/=10;
    }
    now--;
    while(now>=0){
        putchar(nu[now--]+'0');
    }
}
signed main() {
    int a , b;
    re(a);re(b);
    int k = poww(2 , a);

    for(int i = 1 ; i <= k ; i++ ) {
        re(arr[i]);
    }
    build(1 , 1 , k , 1);
    for(int i = 1 ; i <= 4 * k ; i++) {
        cerr << seg[i] << ' ';
    }
    cerr << endl;

    for(int i = 0 ; i < b ; i++) {
        int p , q ; re(p) , re(q);
        wr(query(1 , 1 , k , p , q , 0)),putchar('\n');
    }
    return 0;


}