#include <bits/stdc++.h>
using namespace std;
const int MXN = 2e5;

int failure[MXN]; //儲存以第i個為結尾的次長相同前綴後綴
void KMP(string s, string w)
{
	// i 為字串 s 當前 index, j 為字串 w 以匹配到的 index
	for (int i = 0, j = -1; i < s.size(); ++i)
	{
		while (j >= 0 && s[i] != w[j + 1])
		{ // 當匹配失敗找到次長相同前綴後綴，移動字串W
			j = failure[j];
		}
		if (s[i] == w[j + 1])
		{ // 當字元相等
			++j;
		}
		if (j + 1 == w.size())
		{									 //  當字串完全匹配
			ans.push_back(i - w.size() + 1); // 加進答案
			j = failure[j];					 // 移動字串W
		}
	}
}
void build_failer(string &w)
{
	for (int i = 1, j = failure[0] = -1; i < w.size(); i++)
	{
		while (j >= 0 && w[i] != w[j + 1])
		{
			j = failure[j];
		}
		if (w[i] == w[j + 1])
		{
			j++;
		}
		failure[i] = j;
	}
}