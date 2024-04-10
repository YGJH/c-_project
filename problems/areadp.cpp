#include <bits/stdc++.h>

using namespace std;

#define ishowspeed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int __int128
#define endl '\n'
#define mmin(a,b) (a<b)?a:b

inline void wr(int x) {
    char sta[300];
    if(x<0) putchar('-');
    int now = 0;
    while(x) {
        sta[now++] = x % 10 + 48;
        x/=10;
    }
    while(now) {
        putchar(sta[--now]);
    }
}

inline void re(int &x) {
    x = 0;
    bool w = 0;
    char c = getchar();
    while(c < 48 && c > 57) {
        w |= (c == '-') ; c=getchar();
    }
    while(c > 47 && c < 58) {
        x = (x << 1) + (x << 3) + (c & 15);
        c = getchar();
    }
    if(w) x=-x;
    return ;
}

class Linklist {
    int number;
    public:
    shared_ptr<Linklist> next;
    shared_ptr<Linklist> pre;
    Linklist(int x){
        number = x;
    }
    int getNumber();
    void setNumber(int x);
};
const int N = 402;
void Linklist::setNumber(int x) {
    number = x;
}

int Linklist::getNumber() {
    return number;
}
shared_ptr<Linklist> head;
shared_ptr<Linklist> tail;


int arr[N];

void makeList(int n) {
    head = make_shared<Linklist> (arr[0]);
    head->pre = nullptr;
    shared_ptr<Linklist> last = head;
    for(int i = 1 ; i < n ; i++) {
        shared_ptr<Linklist> nxt = make_shared<Linklist>(arr[i]);
        nxt->pre = last;
        last->next = nxt;
        nxt->next=nullptr;
        last=nxt;
        tail = nxt;
    }
}

// void printList() {
//     shared_ptr<Linklist> tmp = head;
//     while(tmp != nullptr)
//         cerr << tmp->getNumber() << ' ', tmp=tmp->next;
//     cerr << endl;
// }

void solve() {
    int n;
    re(n);

    for(int i = 0 ; i < n ; i++) {
        re(arr[i]);
    }
    makeList(n);
    int ANS = 0;
    // printList();
    while(n>2) {
        pair<int , shared_ptr<Linklist>> now;
        shared_ptr<Linklist> tmp = head -> next;
        int minn = tmp->getNumber() + tmp->pre->getNumber();
        now.first = minn ; now.second = tmp;
        tmp = tmp->next;
        while(tmp!=nullptr) {
            if(minn > tmp->getNumber() + tmp->pre->getNumber()) {
                minn = tmp->getNumber() + tmp->pre->getNumber();
                now.second = tmp;
            }
            tmp = tmp->next;
        }
        now.first = minn;
        ANS += now.first;
        if(now.second -> pre != nullptr) {
            if(now.second -> pre -> pre != nullptr) {
                now.second -> pre -> pre -> next = now.second;
                now.second -> pre = now.second -> pre -> pre;
            }
            else {
                now.second -> pre = nullptr;
                head = now.second;
            }
        }
        else {
            now.second -> pre = nullptr;
            head = now.second;
        }
        now.second ->setNumber(now.first);
        n--;
        // printList();
    }
    ANS += head->getNumber() + head->next->getNumber();
    // printList();
    // cout << ANS << endl;
    wr(ANS);

}



signed main() {
    ishowspeed

    solve();
    return 0;
}