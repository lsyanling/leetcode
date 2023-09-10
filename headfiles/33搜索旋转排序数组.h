
#pragma once

import std;
using namespace std;

class Solution33 {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int result = -1;
		int left = 0, right = n - 1, middle;

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
};