
#pragma once

import std;
using namespace std;

class Solution50 {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        double result = 1;
        long nn = n;
        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }
        bitset<32> bs = nn;
        vector<double> v(32.);
        v[0] = x;
        for (int i = 1; i < 32; i++)
            v[i] = v[i - 1] * v[i - 1];
        for (int i = 0; i < 32; i++)
            if (bs[i])
                result *= v[i];
        return result;
    }
};