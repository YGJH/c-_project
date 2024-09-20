#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld eps = 1e-8;
int dcmp(ld x)
{
    if (abs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
struct Pt
{
    ld x, y;
    Pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
    Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
    Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
    Pt operator*(const ld &a) const { return Pt(x * a, y * a); }
    Pt operator/(const ld &a) const { return Pt(x / a, y / a); }
    ld operator*(const Pt &a) const { return x * a.x + y * a.y; }
    ld operator^(const Pt &a) const { return x * a.y - y * a.x; }
    bool operator<(const Pt &a) const
    {
        return x < a.x || (x == a.x && y < a.y);
    }
    // return dcmp(x-a.x) < 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0); }
    bool operator==(const Pt &a) const
    {
        return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0;
    }
};
ld norm2(const Pt &a) { return a * a; }
ld norm(const Pt &a) { return sqrt(norm2(a)); }
Pt perp(const Pt &a) { return Pt(-a.y, a.x); }
Pt rotate(const Pt &a, ld ang)
{
    return Pt(a.x * cos(ang) - a.y * sin(ang), a.x * sin(ang) + a.y * cos(ang));
}
struct Line
{
    Pt s, e, v; // start, end, end-start
    ld ang;
    Line(Pt _s = Pt(0, 0), Pt _e = Pt(0, 0)) : s(_s), e(_e)
    {
        v = e - s;
        ang = atan2(v.y, v.x);
    }
    bool operator<(const Line &L) const { return ang < L.ang; }
};
struct Circle
{
    Pt o;
    ld r;
    Circle(Pt _o = Pt(0, 0), ld _r = 0) : o(_o), r(_r) {}
};

// for point or line solution, change > to >=
bool onleft(Line L, Pt p)
{
    return dcmp(L.v ^ (p - L.s)) > 0;
} // segment should add Counterclockwise
// assume that Lines intersect
vector<Pt> HPI(vector<Line> &L)
{
    sort(L.begin(), L.end()); // sort by angle
    int n = L.size(), fir, las;
    Pt *p = new Pt[n];
    Line *q = new Line[n];
    q[fir = las = 0] = L[0];
    for (int i = 1; i < n; i++)
    {
        while (fir < las && !onleft(L[i], p[las - 1]))
            las--;
        while (fir < las && !onleft(L[i], p[fir]))
            fir++;
        q[++las] = L[i];
        if (dcmp(q[las].v ^ q[las - 1].v) == 0)
        {
            las--;
            if (onleft(q[las], L[i].s))
                q[las] = L[i];
        }
        if (fir < las)
            p[las - 1] = LLIntersect(q[las - 1], q[las]);
    }
    while (fir < las && !onleft(q[fir], p[las - 1]))
        las--;
    if (las - fir <= 1)
        return {};
    p[las] = LLIntersect(q[las], q[fir]);
    int m = 0;
    vector<Pt> ans(las - fir + 1);
    for (int i = fir; i <= las; i++)
        ans[m++] = p[i];
    return ans;
}

int32_t main()
{
    /*傳入每條方程式的兩點方程式*/
    vector<Pt> HPI(vector<Line> & L)
}