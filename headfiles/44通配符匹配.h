
#pragma once

import std;
using namespace std;

class Solution44 {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size(), pSize = p.size();
		// 前si个与前pi个能匹配
		vector<vector<int>> dp(sSize + 1, vector<int>(pSize + 1, 0));

		dp[0][0] = 1;
		// 如果s长度为0，只有p[pi]均为'*'时才可匹配
		for (int pi = 1; pi < pSize + 1 && p[pi - 1] == '*'; pi++)
			dp[0][pi] = 1;

		for (int si = 1; si < sSize + 1; si++)
		{
			for (int pi = 1; pi < pSize + 1; pi++)
			{
				// 普通匹配
				if (canMatch(s[si - 1], p[pi - 1]))
				{
					dp[si][pi] = dp[si - 1][pi - 1];
				}
				else if (p[pi - 1] == '*')
				{
					// 当遇到*时，可以匹配0次，1次，多于1次
					// 多于1次时，可以转换为先匹配1次，再看能不能匹配
					dp[si][pi] = dp[si][pi - 1] || dp[si - 1][pi - 1] || dp[si - 1][pi];
				}
			}
		}
		return dp[sSize][pSize];
	}

	bool canMatch(char sChar, char pChar)
	{
		return sChar == pChar || pChar == '?';
	}
};