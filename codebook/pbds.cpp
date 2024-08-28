#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using pbds_no_equal   = tree<T, null_type, less<T>, 	   rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> using pbds_with_equal = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

pbds_no_equal<int> s;

// hash table
gp_hash_table<int , bool> mp1;
cc_hash_table<int , bool> mp2;


// rope
rope<int> rp;
crope cp = "abcdef";// equal rope<char> cp
/*
r.push_back(x);orr+=x; //在最後加上 x
r.pop_back(); //去掉最後一個元素
r.insert(pos, x); //在 pos 位置加入 x
r.erase(pos, x); //從 pos 位置刪除 x 個元素
r.copy(pos, len, x); //從 pos 開始的 len 個元素用 x 代替
r.replace(pos, x); //從 pos 開始的元素全部換成 x
r.substr(pos, x); //取得以 pos 開始的 x 個元素
r.at(i);orr[i]; //詢問第 i 個元素
以上有任何進行區間操作或是刪除的行為，複雜度皆為 \(O(\log n)\)。
要注意的是如果進行 r.insert(int pos,crope x)的操作，
最壞複雜度會到 \(O(n)\)。
*/
// if not exist return false
template<typename T>
bool check_x_exist(T x){
    return (s.find(x) != s.end());
}

int main(){
    // Insert some entries into s.
    s.insert(12); s.insert(505);
    // The order of the keys should be: 12, 505.
    assert(*s.find_by_order(0) == 12);
    assert(*s.find_by_order(3) == 505);
    // The order of the keys should be: 12, 505.
    assert(s.order_of_key(12) == 0);
    assert(s.order_of_key(505) == 1);
    // Erase an entry.
    s.erase(12);
    // The order of the keys should be: 505.
    assert(*s.find_by_order(0) == 505);
    // The order of the keys should be: 505.
    assert(s.order_of_key(505) == 0);


    // 查詢名次 k 是那個人的成績
    int rank=s.size()-s.order_of_key(k);


    cout << s.size() << endl;
}