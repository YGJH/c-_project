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

ld PCIntersect(vector<Pt> v, Circle cir)
{
    for (int i = 0; i < (int)v.size(); ++i)
        v[i] = v[i] - cir.o;
    ld ans = 0, r = cir.r;
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        Pt pa = v[i], pb = v[(i + 1) % n];
        if (norm(pa) < norm(pb))
            swap(pa, pb);
        if (dcmp(norm(pb)) == 0)
            continue;
        ld s, h, theta;
        ld a = norm(pb), b = norm(pa), c = norm(pb - pa);
        ld cosB = (pb * (pb - pa)) / a / c, B = acos(cosB);
        if (cosB > 1)
            B = 0;
        else if (cosB < -1)
            B = PI;
        ld cosC = (pa * pb) / a / b, C = acos(cosC);
        if (cosC > 1)
            C = 0;
        else if (cosC < -1)
            C = PI;
        if (a > r)
        {
            s = (C / 2) * r * r;
            h = a * b * sin(C) / c;
            if (h < r && B < PI / 2)
                s -= (acos(h / r) * r * r - h * sqrt(r * r - h * h));
        }
        else if (b > r)
        {
            theta = PI - B - asin(sin(B) / r * a);
            s = 0.5 * a * r * sin(theta) + (C - theta) / 2 * r * r;
        }
        else
            s = 0.5 * sin(C) * a * b;
        ans += abs(s) * dcmp(v[i] ^ v[(i + 1) % n]);
    }
    return abs(ans);
}
vector<Pt> interCircle(Pt o1, D r1, Pt o2, D r2)
{
    if (norm(o1 - o2) > r1 + r2)
        return {};
    if (norm(o1 - o2) < max(r1, r2) - min(r1, r2))
        return {};
    D d2 = (o1 - o2) * (o1 - o2);
    D d = sqrt(d2);
    if (d > r1 + r2)
        return {};
    Pt u = (o1 + o2) * 0.5 + (o1 - o2) * ((r2 * r2 - r1 * r1) / (2 * d2));
    D A = sqrt((r1 + r2 + d) * (r1 - r2 + d) * (r1 + r2 - d) * (-r1 + r2 + d));
    Pt v = Pt(o1.Y - o2.Y, -o1.X + o2.X) * A / (2 * d2);
    return {u + v, u - v};
}

int32_t main()
{
    ld PCIntersect(vector<Pt> v, Circle cir);
    return 0;
}