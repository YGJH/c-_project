#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()

struct Convex
{
    int n;
    vector<Pt> A, V, L, U;
    Convex(const vector<Pt> &_A) : A(_A), n(_A.size())
    { // n >= 3
        auto it = max_element(all(A));
        L.assign(A.begin(), it + 1);
        U.assign(it, A.end()), U.push_back(A[0]);
        for (int i = 0; i < n; i++)
        {
            V.push_back(A[(i + 1) % n] - A[i]);
        }
    }
    int PtSide(Pt p, Line L) { return dcmp((L.b - L.a) ^ (p - L.a)); }
    int inside(Pt p, const vector<Pt> &h, auto f)
    {
        auto it = lower_bound(all(h), p, f);
        if (it == h.end())
            return 0;
        if (it == h.begin())
            return p == *it;
        return 1 - dcmp((p - *prev(it)) ^ (*it - *prev(it)));
    }
    // 1. whether a given point is inside the CH
    // ret 0: out, 1: on, 2: in
    int inside(Pt p)
    {
        return min(inside(p, L, less{}), inside(p, U, greater{}));
    }
    static bool cmp(Pt a, Pt b) { return dcmp(a ^ b) > 0; }
    // 2. Find tangent points of a given vector
    // ret the idx of far/closer tangent point
    int tangent(Pt v, bool close = true)
    {
        assert(v != Pt{});
        auto l = V.begin(), r = V.begin() + L.size() - 1;
        if (v < Pt{})
            l = r, r = V.end();
        if (close)
            return (lower_bound(l, r, v, cmp) - V.begin()) % n;
        return (upper_bound(l, r, v, cmp) - V.begin()) % n;
    }
    // 3. Find 2 tang pts on CH of a given outside point
    // return index of tangent points
    // return {-1, -1} if inside CH
    array<int, 2> tangent2(Pt p)
    {
        array<int, 2> t{-1, -1};
        if (inside(p) == 2)
            return t;
        if (auto it = lower_bound(all(L), p); it != L.end() and p == *it)
        {
            int s = it - L.begin();
            return {(s + 1) % n, (s - 1 + n) % n};
        }
        if (auto it = lower_bound(all(U), p, greater{});
            it != U.end() and p == *it)
        {
            int s = it - U.begin() + L.size() - 1;
            return {(s + 1) % n, (s - 1 + n) % n};
        }
        for (int i = 0; i != t[0]; i = tangent((A[t[0] = i] - p), 0))
            ;
        for (int i = 0; i != t[1]; i = tangent((p - A[t[1] = i]), 1))
            ;
        return t;
    }
    int find(int l, int r, Line L)
    {
        if (r < l)
            r += n;
        int s = PtSide(A[l % n], L);
        return *ranges::partition_point(views::iota(l, r), [&](int m) {
            return PtSide(A[m % n], L) == s;
        }) - 1;
    };
    // 4. Find intersection point of a given line
    // intersection is on edge (i, next(i))
    vector<int> intersect(Line L)
    {
        int l = tangent(L.a - L.b), r = tangent(L.b - L.a);
        if (PtSide(A[l], L) == 0)
            return {l};
        if (PtSide(A[r], L) == 0)
            return {r};
        if (PtSide(A[l], L) * PtSide(A[r], L) > 0)
            return {};
        return {find(l, r, L) % n, find(r, l, L) % n};
    }
};
/*
Given point p return two point denote the tangent line from point p to convex
hull.
 */
array<int, 2> tangent2(Pt p)
    /*return the idx of far/closer tangent point v (min cross value)*/
    int tangent(Pt v, bool close = true)

/*
sign1 傳入 1 求外公切線
sign1 傳入 -1 求內公切線

回傳值為 vector<Line>，對於每條切線
Line 第一個點為第一個圓切點位置
Line 第二個點為第二個圓切點位置
*/
vector<Line> go( const Cir& c1 , const Cir& c2 , int sign1 ){
  // sign1 = 1 for outer tang, -1 for inter tang
  vector<Line> ret;
  double d_sq = norm2( c1.O - c2.O );
  if( d_sq < eps ) return ret;
  double d = sqrt( d_sq );
  Pt v = ( c2.O - c1.O ) / d;
  double c = ( c1.R - sign1 * c2.R ) / d;
  if( c * c > 1 ) return ret;
  double h = sqrt( max( 0.0 , 1.0 - c * c ) );
  for( int sign2 = 1 ; sign2 >= -1 ; sign2 -= 2 ){
    Pt n = { v.X * c - sign2 * h * v.Y ,
             v.Y * c + sign2 * h * v.X };
    Pt p1 = c1.O + n * c1.R;
    Pt p2 = c2.O + n * ( c2.R * sign1 );
    if( fabs( p1.X - p2.X ) < eps and
        fabs( p1.Y - p2.Y ) < eps )
      p2 = p1 + perp( c2.O - c1.O );
    ret.push_back( { p1 , p2 } );
  }
  return ret;
}
        int32_t main()
{

    return 0;
}