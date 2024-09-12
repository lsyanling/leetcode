
#pragma once

#include "librarys.h"
using namespace std;

class Solution78 {
  public:
    vector<vector<int>> combine(int n, int k) {
        return backtrack(n, 0, k);
    }

    vector<vector<int>> backtrack(int n, int left, int k) {
        if (left + k > n)
            return {};

        if (k == 0)
            return {{}};

        if (left + k == n) {
            vector<int> result(k);
            for (auto i = 0; i < k; i++) {
                result[i] = left + i + 1;
            }
            return {result};
        }
        auto results1 = backtrack(n, left + 1, k - 1);
        auto results2 = backtrack(n, left + 1, k);
        for (auto &result : results1) {
            result.push_back(left + 1);
        }
        results1.insert(results1.end(), results2.begin(), results2.end());
        return results1;
    }
};