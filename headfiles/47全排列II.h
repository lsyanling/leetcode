
#pragma once

import std;
using namespace std;

class Solution47 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return permuteUniqueRecursive(nums, 0);
	}
	vector<vector<int>> permuteUniqueRecursive(vector<int>& nums, int begin) {
		int n = nums.size();
		if (begin == n)
			return { nums };
		vector<vector<int>> results;
		set<int> s;
		for (int i = begin; i < n; i++)
		{
			//// 不能使用该剪枝的原因：swap已经破坏了顺序
			//if (i > begin && nums[i] == nums[i - 1])
			//	continue;
			if (addValueForSet(s, nums[i]))
				continue;
			auto permutation{ nums };
			swap(permutation[begin], permutation[i]);
			auto tempResult = permuteUniqueRecursive(permutation, begin + 1);
			results.insert(results.end(), tempResult.begin(), tempResult.end());
			swap(permutation[begin], permutation[i]);
		}
		return results;
	}
	bool addValueForSet(set<int>& s, int value) {
		if (s.find(value) != s.end())
			return true;
		else
			s.insert(value);
		return false;
	}
};