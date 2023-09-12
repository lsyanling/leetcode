
import std;
using namespace std;

#include "headfiles/head.h"

int main() {

	//// 10正则表达式匹配
	//{
	//	Solution10 solution;
	//	string s = "mississippi";
	//	string p = "mis*is*ip*.";
	//	auto result = solution.isMatch(s, p);
	//	print("{0}", result);
	//}

	//// 29两数相除
	//{
	//	Solution29 solution;
	//	int dividend = 2147483647;
	//	int divisor = 3;
	//	auto result = solution.divide(dividend, divisor);
	//	print("{0}", result);
	//}

	//// 30串联所有单词的子串
	//{
	//	Solution30 solution;
	//	string s = "wordgoodgoodgoodbestword";
	//	vector<string> words = { "word","good","best","good" };
	//	auto results = solution.findSubstring(s, words);
	//	for (const auto& result : results) {
	//		print("{0} ", result);
	//	}
	//}

	//// 33搜索旋转排序数组
	//{
	//	Solution33 solution;
	//	vector<int> nums = { 3,4,5,6,1,2 };
	//	int target = 2;
	//	auto result = solution.search(nums, target);
	//	print("{0}", result);
	//}

	//// 39组合总和
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

	// 40组合总和II
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