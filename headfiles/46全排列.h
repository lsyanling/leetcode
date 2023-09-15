
#pragma once

import std;
using namespace std;

class Solution46 {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		return permuteRecursive(nums, 0);
	}
	vector<vector<int>> permuteRecursive(vector<int>& nums, int begin) {
		int n = nums.size();
		if (begin == n)
			return { nums };
		vector<vector<int>> results;
		for (int i = begin; i < n; i++)
		{
			auto permutation{ nums };
			swap(permutation[begin], permutation[i]);
			auto tempResult = permuteRecursive(permutation, begin + 1);
			results.insert(results.end(), tempResult.begin(), tempResult.end());
			swap(permutation[begin], permutation[i]);
		}
		return results;
	}
};