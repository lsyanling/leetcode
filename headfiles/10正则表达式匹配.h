
#pragma once

import std;
using namespace std;

class Solution10 {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size(), pSize = p.size();
		// 前si个与前pi个能匹配
		vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));

		dp[0][0] = 1;
		// 如果s长度为0，只有p长度为偶数且p[2n-1]均为'*'时才可匹配
		for (int pi = 2; pi < pSize && p[pi - 1] == '*'; pi += 2)
		{
			dp[0][pi] = true;
		}
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
					// 当*前面的字符可以匹配时，可以匹配0次，1次，多于1次
					// 多于1次时，可以转换为先匹配1次，再看能不能匹配
					if (canMatch(s[si - 1], p[pi - 2]))
					{
						dp[si][pi] = dp[si][pi - 2] || dp[si - 1][pi - 2] || dp[si - 1][pi];
					}
					// 当*前面的字符不能匹配时，可以考虑匹配0次
					else
					{
						dp[si][pi] = dp[si][pi - 2];
					}
				}
			}
		}
		return dp[sSize][pSize];
	}

	bool canMatch(char sChar, char pChar)
	{
		return sChar == pChar || pChar == '.';
	}
};