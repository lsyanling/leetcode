
#pragma once

import std;
using namespace std;

class Solution41 {
public:
	// 在长度为 n 的数组中，最小的正整数最大是 n + 1
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		// 全部变成正整数
		for (auto& i : nums)
			if (i <= 0)
				i = n + 1;
		// 如果 0 < nums[i] <= n，把 nums[nums[i] - 1] 标记为负
		for (int i = 0; i < n; i++) {
			int index = abs(nums[i]);
			if (index <= n) {
				nums[index - 1] = -abs(nums[index - 1]);
			}
		}
		// 数组中首个正数索引为 i，则 i + 1 是缺失的最小正整数
		for (int i = 0; i < n; i++)
			if (nums[i] > 0)
				return i + 1;
		// 如果数组不存在正数，说明原数组包含了 [1, n]
		return n + 1;
	}
};