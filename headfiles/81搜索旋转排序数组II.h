
#pragma once

#include "librarys.h"
using namespace std;

class Solution81 {
  public:
    bool search(vector<int> nums, int target) {
        int n = nums.size();
        // 二分
        int left = 0, right = n, middle;
        while (left < right) {
            middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                return true;
            }
            // 首先判断middle在旋转点的左侧还是右侧
            // 判断target在旋转点的左侧还是右侧
            // nums[middle] > nums[left] 说明middle在旋转点左侧
            // target > nums[middle] [middle, right]
            // target <= nums[middle] , target < nums[left] [middle, right]
            // target <= nums[middle] , target > nums[left] [left, middle]
            if (nums[middle] > nums[left]) {
                if (target > nums[middle])
                    left = middle + 1;
                else if (target < nums[left])
                    left = middle + 1;
                else if (target > nums[left])
                    right = middle;
                else
                    return true;
            }
            // nums[middle] < nums[left] 说明middle在旋转点右侧
            // target < nums[middle] [left, middle]
            // target >= nums[middle] , target > nums[left] [left, middle]
            // target >= nums[middle] , target < nums[left] [middle, right]
            else if (nums[middle] < nums[left]) {
                if (target < nums[middle])
                    right = middle;
                else if (target > nums[left])
                    right = middle;
                else if (target < nums[left])
                    left = middle + 1;
                else
                    return true;
            }
            else {
                left++;
            }
        }
        return false;
    }
};