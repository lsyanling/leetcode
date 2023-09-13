
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
			// ����height[left] < height[right]�������leftMax < rightMax
			// ��Ϊ�͵��Ǳ��ƶ�
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

	// ntд��
	//int trap(vector<int>& height) {
	//	int n = height.size();
	//	int left = 0, right = n - 1;
	//	// ���˴���0����ʼλ��
	//	while (left < n && height[left] == 0)
	//		left++;
	//	while (right >= 0 && height[right] == 0)
	//		right--;
	//	if (right - left - 1 <= 0)
	//		return 0;
	//	int minHeight = 0, previousMinHeight = 0, length, difference;
	//	// ����minHeight�õ�previousHeight�͵�ǰ��sum��minHeight��Ψһ��
	//	map<int, tuple<int, int>> m;
	//	while (left < right)
	//	{
	//		// �����͸߶ȱ�֮ǰ���ͣ����ı�
	//		if (minHeight > previousMinHeight)
	//			previousMinHeight = minHeight;
	//		length = right - left - 1;
	//		minHeight = min(height[left], height[right]);
	//		// ���left > 0 && right > 0
	//		if (minHeight) {
	//			// ��ȥ��ǰ�߶�ռ�ø��͸߶ȵ����
	//			for (auto& [h, value] : m)
	//			{
	//				// previousHeight, sum
	//				auto& [prev, s] = value;
	//				// ��ǰ�߶Ȳ�
	//				int diff = minHeight - prev;
	//				// �߶Ȳ����ԭ��͸߶ȣ���ȥռ�ݵ����
	//				if (diff > 0)
	//					s -= minHeight < h ? diff : h - prev;
	//			}
	//			if (minHeight > previousMinHeight)
	//			{
	//				// ��ǰ�߶��£��߶Ȳ�����������
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