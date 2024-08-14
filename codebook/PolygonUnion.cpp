#include <bits/stdc++.h>
using namespace std;

inline double segP(Pt &p, Pt &p1, Pt &p2)
{
    if (dcmp(p1.x - p2.x) == 0)
        return (p.y - p1.y) / (p2.y - p1.y);
    return (p.x - p1.x) / (p2.x - p1.x);
}
ld tri(Pt o, Pt a, Pt b) { return (a - o) ^ (b - o); }
double polyUnion(vector<vector<Pt>> py)
{ // py[0~n-1] must be filled
    int n = py.size();
    int i, j, ii, jj, ta, tb, r, d;
    double z, w, s, sum = 0, tc, td, area;
    vector<pair<double, int>> c;
    for (i = 0; i < n; i++)
    {
        area = py[i][py[i].size() - 1] ^ py[i][0];
        for (int j = 0; j < py[i].size() - 1; j++)
            area += py[i][j] ^ py[i][j + 1];
        if ((area /= 2) < 0)
            reverse(py[i].begin(), py[i].end());
        py[i].push_back(py[i][0]);
    }
    for (i = 0; i < n; i++)
    {
        for (ii = 0; ii + 1 < py[i].size(); ii++)
        {
            c.clear();
            c.emplace_back(0.0, 0);
            c.emplace_back(1.0, 0);
            for (j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                for (jj = 0; jj + 1 < py[j].size(); jj++)
                {
                    ta = dcmp(tri(py[i][ii], py[i][ii + 1], py[j][jj]));
                    tb = dcmp(tri(py[i][ii], py[i][ii + 1], py[j][jj + 1]));
                    if (ta == 0 && tb == 0)
                    {
                        if ((py[j][jj + 1] - py[j][jj]) *
                                    (py[i][ii + 1] - py[i][ii]) >
                                0 &&
                            j < i)
                        {
                            c.emplace_back(
                                segP(py[j][jj], py[i][ii], py[i][ii + 1]), 1);
                            c.emplace_back(
                                segP(py[j][jj + 1], py[i][ii], py[i][ii + 1]),
                                -1);
                        }
                    }
                    else if (ta >= 0 && tb < 0)
                    {
                        tc = tri(py[j][jj], py[j][jj + 1], py[i][ii]);
                        td = tri(py[j][jj], py[j][jj + 1], py[i][ii + 1]);
                        c.emplace_back(tc / (tc - td), 1);
                    }
                    else if (ta < 0 && tb >= 0)
                    {
                        tc = tri(py[j][jj], py[j][jj + 1], py[i][ii]);
                        td = tri(py[j][jj], py[j][jj + 1], py[i][ii + 1]);
                        c.emplace_back(tc / (tc - td), -1);
                    }
                }
            }
            sort(c.begin(), c.end());
            z = min(max(c[0].first, 0.0), 1.0);
            d = c[0].second;
            s = 0;
            for (j = 1; j < c.size(); j++)
            {
                w = min(max(c[j].first, 0.0), 1.0);
                if (!d)
                    s += w - z;
                d += c[j].second;
                z = w;
            }
            sum += (py[i][ii] ^ py[i][ii + 1]) * s;
        }
    }
    return sum / 2;
}

// Area[i] : area covered by at least i polygon
vector<double> PolyUnion(const vector<vector<Pt>> &P)
{
    const int n = P.size();
    vector<double> Area(n + 1);
    vector<Line> Ls;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < P[i].size(); j++)
            Ls.push_back({P[i][j], P[i][(j + 1) % P[i].size()]});
    auto cmp = [&](Line &l, Line &r) {
        Pt u = l.b - l.a, v = r.b - r.a;
        if (argcmp(u, v))
            return true;
        if (argcmp(v, u))
            return false;
        return PtSide(l.a, r) < 0;
    };
    sort(all(Ls), cmp);
    for (int l = 0, r = 0; l < Ls.size(); l = r)
    {
        while (r < Ls.size() and !cmp(Ls[l], Ls[r]))
            r++;
        Line L = Ls[l];
        vector<pair<Pt, int>> event;
        for (auto [c, d] : Ls)
        {
            if (sgn((L.a - L.b) ^ (c - d)) != 0)
            {
                int s1 = PtSide(c, L) == 1;
                int s2 = PtSide(d, L) == 1;
                if (s1 ^ s2)
                    event.emplace_back(LineInter(L, {c, d}), s1 ? 1 : -1);
            }
            else if (PtSide(c, L) == 0 and sgn((L.a - L.b) * (c - d)) > 0)
            {
                event.emplace_back(c, 2);
                event.emplace_back(d, -2);
            }
        }
        sort(all(event), [&](auto i, auto j) {
            return (L.a - i.ff) * (L.a - L.b) < (L.a - j.ff) * (L.a - L.b);
        });
        int cov = 0, tag = 0;
        Pt lst{0, 0};
        for (auto [p, s] : event)
        {
            if (cov >= tag)
            {
                Area[cov] += lst ^ p;
                Area[cov - tag] -= lst ^ p;
            }
            if (abs(s) == 1)
                cov += s;
            else
                tag += s / 2;
            lst = p;
        }
    }
    for (int i = n - 1; i >= 0; i--)
        Area[i] += Area[i + 1];
    for (int i = 1; i <= n; i++)
        Area[i] /= 2;
    return Area;
};

// P, Q, R(return) are counterclockwise order convex polygon
vector<Pt> minkowski(vector<Pt> P, vector<Pt> Q)
{
    auto cmp = [&](Pt a, Pt b) { return Pt{a.y, a.x} < Pt{b.y, b.x}; };
    auto reorder = [&](auto &R) {
        rotate(R.begin(), min_element(all(R), cmp), R.end());
        R.push_back(R[0]), R.push_back(R[1]);
    };
    reorder(P), reorder(Q);
    vector<Pt> R;
    for (int i = 0, j = 0, s; i < P.size() || j < Q.size();)
    {
        R.push_back(P[i] + Q[j]);
        s = dcmp((P[i + 1] - P[i]) ^ (Q[j + 1] - Q[j]));
        if (s >= 0)
            i++;
        if (s <= 0)
            j++;
    }
    rotate(R.begin(), min_element(all(R)), R.end());
    return R;
}

int32_t main()
{
    /*傳入多個多邊形，每個多邊形為一個 vector<Pt> 回傳值為多邊形的聯集面積*/
    double polyUnion(vector<vector<Pt>> py);
    /*
    把多邊形 p 和 q 丟進去 minkowski，回傳的 vector 為組成的凸多邊形。
    丟進去的多邊形要保證為照逆時針順序給，出來的也是逆時針順序的。
    */
    vector<Pt> minkowski(vector<Pt> P, vector<Pt> Q)
}