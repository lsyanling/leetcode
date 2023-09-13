
#pragma once

import std;
using namespace std;

class Solution44 {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size(), pSize = p.size();
		// ǰsi����ǰpi����ƥ��
		vector<vector<int>> dp(sSize + 1, vector<int>(pSize + 1, 0));

		dp[0][0] = 1;
		// ���s����Ϊ0��ֻ��p[pi]��Ϊ'*'ʱ�ſ�ƥ��
		for (int pi = 1; pi < pSize + 1 && p[pi - 1] == '*'; pi++)
			dp[0][pi] = 1;

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
					// ������*ʱ������ƥ��0�Σ�1�Σ�����1��
					// ����1��ʱ������ת��Ϊ��ƥ��1�Σ��ٿ��ܲ���ƥ��
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