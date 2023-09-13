
#pragma once

import std;
using namespace std;

class Solution42 {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int left = 0, right = n - 1;
		int leftMax = height[0], rightMax = height[n - 1];
		int result = 0;
		while (left < right)
		{
			// 由于height[left] < height[right]，则必有leftMax < rightMax
			// 因为低的那边移动
			if (height[left] < height[right]) {
				if (height[left] < leftMax)
					result += leftMax - height[left];
				else
					leftMax = height[left];
				left++;
			}
			else {
				if (height[right] < rightMax)
					result += rightMax - height[right];
				else
					rightMax = height[right];
				right--;
			}
		}
		return result;
	}

	// nt写法
	//int trap(vector<int>& height) {
	//	int n = height.size();
	//	int left = 0, right = n - 1;
	//	// 两端大于0的起始位置
	//	while (left < n && height[left] == 0)
	//		left++;
	//	while (right >= 0 && height[right] == 0)
	//		right--;
	//	if (right - left - 1 <= 0)
	//		return 0;
	//	int minHeight = 0, previousMinHeight = 0, length, difference;
	//	// 根据minHeight得到previousHeight和当前的sum，minHeight是唯一的
	//	map<int, tuple<int, int>> m;
	//	while (left < right)
	//	{
	//		// 如果最低高度比之前还低，不改变
	//		if (minHeight > previousMinHeight)
	//			previousMinHeight = minHeight;
	//		length = right - left - 1;
	//		minHeight = min(height[left], height[right]);
	//		// 如果left > 0 && right > 0
	//		if (minHeight) {
	//			// 减去当前高度占用更低高度的面积
	//			for (auto& [h, value] : m)
	//			{
	//				// previousHeight, sum
	//				auto& [prev, s] = value;
	//				// 当前高度差
	//				int diff = minHeight - prev;
	//				// 高度差大于原最低高度，减去占据的面积
	//				if (diff > 0)
	//					s -= minHeight < h ? diff : h - prev;
	//			}
	//			if (minHeight > previousMinHeight)
	//			{
	//				// 当前高度下，高度差带来的总面积
	//				difference = minHeight - previousMinHeight;
	//				int sum = length * difference;
	//				m[minHeight] = { previousMinHeight, sum };
	//			}
	//		}
	//		if (height[left] <= height[right])
	//			left++;
	//		else
	//			right--;
	//	}
	//	int result = 0;
	//	for (auto& [h, value] : m)
	//	{
	//		auto& [prev, s] = value;
	//		result += s;
	//	}
	//	return result;
	//}
};