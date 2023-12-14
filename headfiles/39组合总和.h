
#pragma once

import std;
using namespace std;

class Solution39 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return combinationSumRecursive(candidates, target, 0);
	}
	vector<vector<int>> combinationSumRecursive(vector<int>& candidates, int target, int begin) {
		vector<vector<int>> results;
		// 查找完毕或不可能有解
		if (begin >= candidates.size() || target < candidates[begin])
			return {};
		// 遍历候选数组，减去每个值并递归
		for (int i = begin; i < candidates.size(); i++)
		{
			// 得到解
			if (target == candidates[i]) {
				results.push_back({ candidates[i] });
				continue;
			}
			// 递归，每个解中插入当前选中的值；剪枝，从第 i 个开始查找，前面的在前一棵子树查过了
			auto tempResults = combinationSumRecursive(candidates, target - candidates[i], i);
			for (auto& tempResult : tempResults)
				tempResult.push_back(candidates[i]);
			// 将解合并到results
			results.insert(results.end(), tempResults.begin(), tempResults.end());
		}
		return results;
	}
};