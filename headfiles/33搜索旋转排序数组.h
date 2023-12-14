
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

		// 查最小值的索引
		while (left < right)
		{
			middle = (left + right) / 2;
			if (nums[middle] > nums[n - 1])
				left = middle + 1;
			else
				right = middle;
		}

		// target在最小值的哪边
		int minIndex = (left + right) / 2;
		left = 0, right = n - 1;
		if (target > nums[n - 1])
			right = minIndex - 1;
		else
			left = minIndex;

		// 查target，2log也是log
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
			// 左边乱序，右边顺序
			if (nums[left] > nums[middle]) {
				if (nums[middle] <= target && nums[right] >= target)
					left = middle + 1;
				else
					right = middle;
			}
			// 右边乱序，左边顺序
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