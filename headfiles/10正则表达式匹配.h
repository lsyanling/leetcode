
#pragma once

import std;
using namespace std;

class Solution10 {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size(), pSize = p.size();
		// ǰsi����ǰpi����ƥ��
		vector<vector<bool>> dp(sSize + 1, vector<bool>(pSize + 1, false));

		dp[0][0] = 1;
		// ���s����Ϊ0��ֻ��p����Ϊż����p[2n-1]��Ϊ'*'ʱ�ſ�ƥ��
		for (int pi = 2; pi < pSize && p[pi - 1] == '*'; pi += 2)
		{
			dp[0][pi] = true;
		}
		for (int si = 1; si < sSize + 1; si++)
		{
			for (int pi = 1; pi < pSize + 1; pi++)
			{
				// ��ͨƥ��
				if (canMatch(s[si - 1], p[pi - 1]))
				{
					dp[si][pi] = dp[si - 1][pi - 1];
				}
				else if (p[pi - 1] == '*')
				{
					// ��*ǰ����ַ�����ƥ��ʱ������ƥ��0�Σ�1�Σ�����1��
					// ����1��ʱ������ת��Ϊ��ƥ��1�Σ��ٿ��ܲ���ƥ��
					if (canMatch(s[si - 1], p[pi - 2]))
					{
						dp[si][pi] = dp[si][pi - 2] || dp[si - 1][pi - 2] || dp[si - 1][pi];
					}
					// ��*ǰ����ַ�����ƥ��ʱ�����Կ���ƥ��0��
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