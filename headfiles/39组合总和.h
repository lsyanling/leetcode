
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
		// ����target��ֱ�ӷŽ�ȥ
		for (int i = 0; i < n; i++)
		{
			if (target == candidates[i]) {
				vector<int> result(1, target);
				results.push_back(result);
			}
		}
		set<vector<int>> s;
		// ������ѡ���飬��ȥÿ��ֵ���ݹ�
		for (int i = 0; i < n; i++)
		{
			int newTarget = target - candidates[i];
			if (newTarget >= candidates[i]) {
				auto tempResults = combinationSumRecursive(candidates, newTarget);
				for (auto& tempResult : tempResults) {
					// ���뱻��ȥ��ֵ
					tempResult.push_back(candidates[i]);
					// �����ֹ�ظ�
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