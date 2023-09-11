
#pragma once

import std;
using namespace std;

class Solution39 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return combinationSumRecursive(candidates, target);
	}
	vector<vector<int>> combinationSumRecursive(vector<int>& candidates, int target) {
		vector<vector<int>> results;
		if (target < candidates[0])
			return results;
		int n = candidates.size();
		// 等于target的直接放进去
		for (int i = 0; i < n; i++)
		{
			if (target == candidates[i]) {
				vector<int> result(1, target);
				results.push_back(result);
			}
		}
		set<vector<int>> s;
		// 遍历候选数组，减去每个值并递归
		for (int i = 0; i < n; i++)
		{
			int newTarget = target - candidates[i];
			if (newTarget >= candidates[i]) {
				auto tempResults = combinationSumRecursive(candidates, newTarget);
				for (auto& tempResult : tempResults) {
					// 插入被减去的值
					tempResult.push_back(candidates[i]);
					// 排序防止重复
					sort(tempResult.begin(), tempResult.end());
					s.insert(tempResult);
				}
			}
		}
		for (auto& result : s)
			results.push_back(move(result));
		return results;
	}
};