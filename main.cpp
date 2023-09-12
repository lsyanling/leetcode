
import std;
using namespace std;

#include "headfiles/head.h"

int main() {

	//// 10������ʽƥ��
	//{
	//	Solution10 solution;
	//	string s = "mississippi";
	//	string p = "mis*is*ip*.";
	//	auto result = solution.isMatch(s, p);
	//	print("{0}", result);
	//}

	//// 29�������
	//{
	//	Solution29 solution;
	//	int dividend = 2147483647;
	//	int divisor = 3;
	//	auto result = solution.divide(dividend, divisor);
	//	print("{0}", result);
	//}

	//// 30�������е��ʵ��Ӵ�
	//{
	//	Solution30 solution;
	//	string s = "wordgoodgoodgoodbestword";
	//	vector<string> words = { "word","good","best","good" };
	//	auto results = solution.findSubstring(s, words);
	//	for (const auto& result : results) {
	//		print("{0} ", result);
	//	}
	//}

	//// 33������ת��������
	//{
	//	Solution33 solution;
	//	vector<int> nums = { 3,4,5,6,1,2 };
	//	int target = 2;
	//	auto result = solution.search(nums, target);
	//	print("{0}", result);
	//}

	//// 39����ܺ�
	//{
	//	Solution39 solution;
	//	vector<int> nums = { 2,3,6,7 };
	//	int target = 7;
	//	auto results = solution.combinationSum(nums, target);
	//	println("{0}", results.size());
	//	for (const auto& result : results) {
	//		for (const auto& factor : result)
	//			print("{0} ", factor);
	//		println("");
	//	}
	//}

	// 40����ܺ�II
	{
		Solution40 solution;
		vector<int> nums = { 2,5,2,1,2 };
		int target = 5;
		auto results = solution.combinationSum2(nums, target);
		println("{0}", results.size());
		for (const auto& result : results) {
			for (const auto& factor : result)
				print("{0} ", factor);
			println("");
		}
	}

}