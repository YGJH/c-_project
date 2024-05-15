#include <iostream>
using namespace std;
#define ld long double
// 點
struct Pt {
  ld x, y;
  Pt(ld _x=0, ld _y=0):x(_x), y(_y) {}
  
  Pt operator+(const Pt &a){
    return Pt(x+a.x, y+a.y);
  }
  Pt operator-(const Pt &a){
    return Pt(x-a.x, y-a.y);
  }
  Pt operator*(const ld &a){
    return Pt(x*a, y*a);
  }
  Pt operator/(const ld &a){
    return Pt(x/a, y/a);
  }
  ld operator*(const Pt &a){ //計算幾何程式碼中內積通常用*表示
    return x*a.x + y*a.y;
  }
  ld operator^(const Pt &a){ //計算幾何程式碼中外積通常用^表示
    return x*a.y - y*a.x;
  }
  bool operator<(const Pt &a) const { // 判斷兩點座標 先比 x 再比 y
    return x < a.x || (x == a.x && y < a.y);
  }
};

int main(){
    Pt a(1, 3), b(3, 19);
    Pt c = a+b;
}
// 線
struct Line{ 
    Pt st, ed; 
};
//圓
struct Circle{ 
    Pt o; // 圓心
    ld r; // 半徑
};
//多邊形
struct poly{
    int n; // n 邊形
    vector<Pt> pts; 
};


int main(){
    Pt a(1, 3), b(3, 19);
    Pt c = a+b;
}

// 判斷點在不在線上
// 整數點判斷
bool inLine(const Pt& p, const Line& li){
    return collinearity(li.st, li.ed, p) && (li.st-p)*(li.ed-p) < 0;
}

//小數點判斷
bool inLine(const Pt& p, const Line& li){
    return collinearity(li.st, li.ed, p) && (li.st-p)*(li.ed-p) < EPS;
}

//三點是否共線
//整數點判斷
bool collinearity(const Pt& a, const Pt& b, const Pt& c){
    return (b-a)^(c-a) == 0;
}
//小數點判斷
bool collinearity(const Pt& a, const Pt& b, const Pt& c){
    return (b-a)^(c-a) < EPS;
}