
#pragma once

import std;
using namespace std;

class Solution33 {
public:
	int search(vector<int>& nums, int target) {
		return search1(nums, target);
		return search2(nums, target);
	}

	int search1(vector<int>& nums, int target) {
		int n = nums.size();
		int left = 0, right = n - 1, middle;
		int result = -1;

		// ����Сֵ������
		while (left < right)
		{
			middle = (left + right) / 2;
			if (nums[middle] > nums[n - 1])
				left = middle + 1;
			else
				right = middle;
		}

		// target����Сֵ���ı�
		int minIndex = (left + right) / 2;
		left = 0, right = n - 1;
		if (target > nums[n - 1])
			right = minIndex - 1;
		else
			left = minIndex;

		// ��target��2logҲ��log
		while (left < right)
		{
			middle = (left + right) / 2;
			if (target > nums[middle])
				left = middle + 1;
			else
				right = middle;
		}
		middle = (left + right) / 2;
		if (nums[middle] == target)
			result = middle;
		return result;
	}

	int search2(vector<int>& nums, int target) {
		int n = nums.size();
		int left = 0, right = n - 1, middle;

		while (left <= right) {
			middle = (left + right) / 2;
			if (nums[middle] == target)
				return middle;
			// ��������ұ�˳��
			if (nums[left] > nums[middle]) {
				if (nums[middle] <= target && nums[right] >= target)
					left = middle + 1;
				else
					right = middle;
			}
			// �ұ��������˳��
			else
			{
				if (nums[left] <= target && nums[middle] >= target)
					right = middle;
				else
					left = middle + 1;
			}
		}
		return -1;
	}
};