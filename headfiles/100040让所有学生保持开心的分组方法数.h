
#pragma once

import std;
using namespace std;

class Solution100040 {
public:
	int countWays(vector<int>& nums) {
		int result = 0;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		// 不选
		if (0 < nums[0])
			result++;
		int selected = 1;
		while (selected < n) {
			// 不同选法
			for (int i = selected; i < n; i++)
			{
				if (selected > nums[i - 1] && selected < nums[i])
					result++;
				else break;
			}
			selected++;
		}
		// 全选
		if (n > nums[n - 1])
			result++;
		return result;
	}
};