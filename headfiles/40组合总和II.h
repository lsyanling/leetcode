
#pragma once

import std;
using namespace std;

class Solution40 {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return combinationSum2Recursive(candidates, target, 0);
	}
	vector<vector<int>> combinationSum2Recursive(vector<int>& candidates, int target, int begin) {
		vector<vector<int>> results;
		// 查找完毕或不可能有解
		if (begin >= candidates.size() || target < candidates[begin])
			return {};
		for (int i = begin; i < candidates.size(); i++)
		{
			// 剪枝，候选数组中连续两个值相同，在上一层查过了
			if (i > begin && candidates[i] == candidates[i - 1])
				continue;
			// 得到解
			if (target == candidates[i]) {
				results.push_back({ candidates[i] });
				continue;
			}
			// 递归，每个解中插入当前选中的值
			auto tempResults = combinationSum2Recursive(candidates, target - candidates[i], i + 1);
			for (auto& tempResult : tempResults)
				tempResult.push_back(candidates[i]);
			// 将解合并到results
			results.insert(results.end(), tempResults.begin(), tempResults.end());
		}
		return results;
	}
};