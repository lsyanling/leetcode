
#pragma once

import std;
using namespace std;

class Solution29 {
public:
	int divide(int dividend, int divisor) {
		int intMin = numeric_limits <int>::min();
		int intMax = numeric_limits <int>::max();
		int intMinHalf = -1;
		for (int i = 0; i < 30; i++)
		{
			intMinHalf += intMinHalf;
		}

		bool signReversal = false;
		if (dividend > 0) {
			dividend = -dividend;
			signReversal = !signReversal;
		}
		if (divisor > 0) {
			divisor = -divisor;
			signReversal = !signReversal;
		}
		// 被除数为0或被除数(负)大于除数(负)，商为0
		if (dividend == 0 || dividend > divisor)
		{
			return 0;
		}

		// 商不为0的情况
		int quotient = 0;
		for (int times = -1, tempDividend = dividend, tempDivisor = divisor; tempDividend <= tempDivisor;)
		{
			// 保存超出临时被除数（或最小整数的一半）之前的临时除数
			int previousDivisor = tempDivisor;
			while (tempDivisor > intMinHalf && tempDividend < tempDivisor)
			{
				previousDivisor = tempDivisor;
				tempDivisor += tempDivisor;
				if (tempDivisor > intMinHalf && tempDividend < tempDivisor)
				{
					times += times;
				}
			}
			quotient += times;
			times = -1;
			tempDividend -= previousDivisor;
			tempDivisor = divisor;
		}
		// 变号说明异号，直接返回
		if (signReversal)
		{
			return quotient;
		}
		else if (quotient == intMin)
		{
			return intMax;
		}
		return -quotient;
	}
};