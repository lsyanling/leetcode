
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
		// ������ϻ򲻿����н�
		if (begin >= candidates.size() || target < candidates[begin])
			return {};
		for (int i = begin; i < candidates.size(); i++)
		{
			// ��֦����ѡ��������������ֵ��ͬ������һ������
			if (i > begin && candidates[i] == candidates[i - 1])
				continue;
			// �õ���
			if (target == candidates[i]) {
				results.push_back({ candidates[i] });
				continue;
			}
			// �ݹ飬ÿ�����в��뵱ǰѡ�е�ֵ
			auto tempResults = combinationSum2Recursive(candidates, target - candidates[i], i + 1);
			for (auto& tempResult : tempResults)
				tempResult.push_back(candidates[i]);
			// ����ϲ���results
			results.insert(results.end(), tempResults.begin(), tempResults.end());
		}
		return results;
	}
};