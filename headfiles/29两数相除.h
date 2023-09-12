
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
		// ������Ϊ0�򱻳���(��)���ڳ���(��)����Ϊ0
		if (dividend == 0 || dividend > divisor)
		{
			return 0;
		}

		// �̲�Ϊ0�����
		int quotient = 0;
		for (int times = -1, tempDividend = dividend, tempDivisor = divisor; tempDividend <= tempDivisor;)
		{
			// ���泬����ʱ������������С������һ�룩֮ǰ����ʱ����
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
		// ���˵����ţ�ֱ�ӷ���
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