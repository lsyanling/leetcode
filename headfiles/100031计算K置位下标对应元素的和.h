
#pragma once

import std;
using namespace std;

class Solution100031 {
public:
	int sumIndicesWithKSetBits(vector<int>& nums, int k) {
		// 查表，题目条件最多1000个
		vector allSetBits(1001, 0);
		for (int i = 0; i < allSetBits.size(); i++)
		{
			int j = i;
			int bits = 0;
			while (j > 0)
			{
				if (j && j % 2 == 0)
					j /= 2;
				else {
					j--;
					bits++;
				}
			}
			allSetBits[i] = bits;
		}
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
			if (allSetBits[i]==k)
				result += nums[i];
		return result;
	}
};