
#pragma once

#include "librarys.h"
using namespace std;

class Solution80 {
  public:
    int removeDuplicates(vector<int> &nums) {
        auto n = nums.size();
        auto left = 0, right = 1, times = 1;
        while(right < n){
            if(left == 0){
                if(nums[right] == nums[right-1])
                    times++;
                else
                    times = 1;
                if(times > 2)
                    left = right;
            }
            else{
                if(nums[right] == nums[right-1])
                    times++;
                else 
                    times = 1;
                if(times <= 2){
                    nums[left] = nums[right];
                    left++;
                }
            }
            right++;
        }
        return left ? left : n;
    }
};