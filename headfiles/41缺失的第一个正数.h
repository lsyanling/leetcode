
#pragma once

import std;
using namespace std;

class Solution41 {
public:
	// �ڳ���Ϊ n �������У���С������������� n + 1
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		// ȫ�����������
		for (auto& i : nums)
			if (i <= 0)
				i = n + 1;
		// ��� 0 < nums[i] <= n���� nums[nums[i] - 1] ���Ϊ��
		for (int i = 0; i < n; i++) {
			int index = abs(nums[i]);
			if (index <= n) {
				nums[index - 1] = -abs(nums[index - 1]);
			}
		}
		// �������׸���������Ϊ i���� i + 1 ��ȱʧ����С������
		for (int i = 0; i < n; i++)
			if (nums[i] > 0)
				return i + 1;
		// ������鲻����������˵��ԭ��������� [1, n]
		return n + 1;
	}
};