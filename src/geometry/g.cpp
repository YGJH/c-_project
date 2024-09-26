#include <bits/stdc++.h>
using namespace std;
#define int long long 
# define ld long double
// #define int __int128
struct Pt {
	int x, y;
    Pt operator*(const Pt &a) {
        return Pt(x+a.x , y+a.y);
    }
    Pt operator-(const Pt &a) {
        return Pt(x-a.x , y-a.y);
    }
	bool operator==(const Pt &a) const { return x == a.x && y == a.y; }
	bool operator<(const Pt &a) const {
		if (x == a.x) {
			return y < a.y;
		} else {
			return x < a.x;
		}
	}
	friend long double cross(Pt &a, Pt &b, Pt &c) {
		Pt tmp1 = a - b;
		Pt tmp2 = c - b;
		return tmp1.x * tmp2.y - tmp1.y * tmp2.x;
	}
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt(int _x, int _y) : x(_x), y(_y){};
	Pt(){};
	long double len() { return hypot(x, y); }
	long double operator^(const Pt &a) { return (x * a.y - y * a.x); }
};
// void convex_hull(vector<Pt> &a, vector<Pt> &b) {
// 	if (a.size() < 3) {
// 		b = a;
// 		return;
// 	}
// 	int con = 0;
// 	for (int i = 0; i < a.size(); i++) {
// 		while (con >= 2 && cross(b[con - 2], b[con - 1], a[i]) <= 0) {
// 			con--;
// 			b.pop_back();
// 		}
// 		b.push_back(a[i]);
// 		con++;
// 	}
// 	for (int i = a.size() - 2, t = con + 1; i >= 0; i--) {
// 		while (con >= 2 && cross(b[con - 2], b[con - 1], a[i]) <= 0) {
// 			con--;
// 			b.pop_back();
// 		}
// 		b.push_back(a[i]);
// 		con++;
// 	}
// 	b.pop_back();
// 	return;
// }
// long double area(vector<Pt> &a) {
// 	long double ret = 0;
// 	if (a.size() <= 2) {
// 		return 0;
// 	}
// 	a.push_back(*(a.begin()));
// 	Pt base = a[0];
// 	for (int i = 0; i < a.size(); i++) {
// 		if (i >= 2)
// 			ret += cross(a[i], base, a[i - 1]);
// 	}
// 	a.pop_back();
// 	return fabs(ret);
// }
// #define __int128 long long
int areAA(vector<Pt> &arr) {
    int area = 0;
    int n = arr.size();
    for (int i =0 ;  i< n ; i++) {
        area += ((arr[i].x * arr[(i+1)%n].y) - arr[(i+1)%n].x * arr[i].y);
    }
    area = abs(area);
    return area;
}
long long ARS;
int FarthestPair(vector<Pt> &arr) {
    __int128 ret = 1e28;
    int n = arr.size();
    __int128 now = 0;
    for(int i = 0 , j = 0 ; i < n ; i++) {
        if(i>0) now-=(arr[i-1]^arr[i]), now -=(arr[j]^arr[i-1]);
        now += (arr[j]^arr[i]);
        __int128 curr = now - (arr[j] ^ arr[i]);
        curr += (arr[(j+1)%n] ^ arr[i]) + (arr[j] ^ arr[(j+1) % n]);
        while(abs(ARS - 4 *abs(now)) >= abs(ARS - 4 * abs(curr))) {
            now = curr;
            j = (j+1) % n;
            if(j == i) break;
            curr = now - (arr[j] ^ arr[i]);
            curr += (arr[(j+1)%n] ^ arr[i]) + (arr[j] ^ arr[(j+1)%n]);
        }
        ret = min(ret ,  abs(ARS - 4 * abs(now)));
    }
    return ret;
}

// constexpr long double eps = 1e-9;
// int sgn(double x) {
// 	if (fabs(x) < eps)
// 		return 0;
// 	if (x < 0)
// 		return -1;
// 	return 1;
// }
// pair<Pt, Pt> kake(vector<Pt> &v) { //旋转卡壳
// 	int v_len = v.size();
// 	double ans = 1e15;
// 	int idx = 1;
// 	v[v_len] = v[0];
// 	pair<Pt, Pt> ret;
// 	for (int i = 0; i < v_len; ++i) {
// 		while (fabs(cross(v[i + 1], v[i], v[idx + 1])) >
// 			   fabs(cross(v[i + 1], v[i], v[idx]))) {
// 			if (idx >= v_len)
// 				idx -= v_len;
// 			else
// 				idx += 1;
// 		}
// 		double now =
// 			fabs(cross(v[i + 1], v[i], v[idx])) / (v[i] - v[i + 1]).len();

// 		if (sgn(now - ans) == -1) {
// 			ans = now;
// 			ret.first.x = v[idx].x, ret.first.y = v[idx].y;
// 			ret.second.x = v[i].x, ret.second.y = v[i].y;
// 		}
// 	}
// 	// printf("%.16f\n", ans);
// 	return ret;
// }
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<Pt> V(n);
	for (auto &a : V) {
		cin >> a.x >> a.y;
	}
	// sort(V.begin(), V.end());
	// vector<Pt> tuboo;
	// convex_hull(V, tuboo);

	// long double a = area(tuboo) / 2;
	// auto pp = kake(tuboo);
	// vector<Pt> tmp1;
	// for (int i = 0; i < tuboo.size(); i++) {
	// 	if (tuboo[i] == pp.second) {
	// 		tmp1.push_back(tuboo[i]);
	// 		for (int j = i + 1; j < tuboo.size(); j++) {
	// 			tmp1.push_back(tuboo[j]);
	// 			if (tuboo[j] == pp.first) {
	// 				goto fin;
	// 			}
	// 		}
	// 	} else if (tuboo[i] == pp.first) {
	// 		tmp1.push_back(tuboo[i]);
	// 		for (int j = i + 1; j < tuboo.size(); j++) {
	// 			tmp1.push_back(tuboo[j]);
	// 			if (tuboo[j] == pp.second) {
	// 				goto fin;
	// 			}
	// 		}
	// 	}
	// }
// fin:
	// for(auto &ab : tmp1) {
	//     cout << ab.x << ' ' << ab.y << endl;
	// }
	// cout << pp.first.x << ' ' << pp.first.y << '\n' << pp.second.x << ' ' <<
	// pp.second.y << '\n';
	// long double aa = area(tmp1) / 2;
	// long double bb = a - aa;
	// aa = min(aa, bb);
	// cerr << aa << endl;
	// a /= 4;
    ARS = areAA(V);
    int diss = FarthestPair(V);
	cout << diss << '\n';
	return 0;
}