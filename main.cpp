
import std;
using namespace std;

#include "headfiles/head.h"

int main() {

	//// 10正则表达式匹配
	//{
	//	Solution10 solution;
	//	string s = { "mississippi" };
	//	string p{ "mis*is*ip*." };
	//	auto result = solution.isMatch(s, p);
	//	println("10正则表达式匹配 result = {0}", result);
	//}

	//// 29两数相除
	//{
	//	Solution29 solution;
	//	int dividend = 2147483647;
	//	int divisor = 3;
	//	auto result = solution.divide(dividend, divisor);
	//	println("29两数相除 result = {0}", result);
	//}

	//// 30串联所有单词的子串
	//{
	//	Solution30 solution;
	//	string s{ "wordgoodgoodgoodbestword" };
	//	vector<string> words{ "word","good","best","good" };
	//	auto results = solution.findSubstring(s, words);
	//	println("30串联所有单词的子串 result.size() = {0}", results.size());
	//	for (const auto& result : results)
	//		print("{0} ", result);
	//	println("");
	//}

	//// 33搜索旋转排序数组
	//{
	//	Solution33 solution;
	//	vector<int> nums{ 4,5,6,7,0,1,2 };
	//	int target = 0;
	//	auto result = solution.search(nums, target);
	//	println("33搜索旋转排序数组 result = {0}", result);
	//}

	//// 37解数独
	//{
	//	Solution37 solution;
	//	vector<vector<char>> board
	//	{
	//		{'5','3','.','.','7','.','.','.','.'},
	//		{'6','.','.','1','9','5','.','.','.'},
	//		{'.','9','8','.','.','.','.','6','.'},
	//		{'8','.','.','.','6','.','.','.','3'},
	//		{'4','.','.','8','.','3','.','.','1'},
	//		{'7','.','.','.','2','.','.','.','6'},
	//		{'.','6','.','.','.','.','2','8','.'},
	//		{'.','.','.','4','1','9','.','.','5'},
	//		{'.','.','.','.','8','.','.','7','9'}
	//	};
	//	solution.solveSudoku(board);
	//	println("37解数独");
	//	for (const auto& row : board) {
	//		for (const auto& item : row)
	//			print("{0} ", item);
	//		println("");
	//	}
	//}

	//// 39组合总和
	//{
	//	Solution39 solution;
	//	vector<int> nums{ 2,3,6,7 };
	//	int target = 7;
	//	auto results = solution.combinationSum(nums, target);
	//	println("39组合总和 result.size() = {0}", results.size());
	//	for (const auto& result : results) {
	//		for (const auto& factor : result)
	//			print("{0} ", factor);
	//		println("");
	//	}
	//}

	//// 40组合总和II
	//{
	//	Solution40 solution;
	//	vector<int> nums{ 2,5,2,1,2 };
	//	int target = 5;
	//	auto results = solution.combinationSum2(nums, target);
	//	println("40组合总和II result.size() = {0}", results.size());
	//	for (const auto& result : results) {
	//		for (const auto& factor : result)
	//			print("{0} ", factor);
	//		println("");
	//	}
	//}

	//// 41缺失的第一个正数
	//{
	//	Solution41 solution;
	//	vector<int> nums{ 1 };
	//	auto result = solution.firstMissingPositive(nums);
	//	println("41缺失的第一个正数 result = {0}", result);
	//}

	//// 42接雨水
	//{
	//	Solution42 solution;
	//	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	//	auto result = solution.trap(height);
	//	println("42接雨水 result = {0}", result);
	//}

	//// 43字符串相乘
	//{
	//	Solution43 solution;
	//	string num1{ "123" };
	//	string num2{ "456" };
	//	auto result = solution.multiply(num1, num2);
	//	println("43字符串相乘 result = {0}", result);
	//}

	//// 44通配符匹配
	//{
	//	Solution44 solution;
	//	string s{ "" };
	//	string p{ "******" };
	//	auto result = solution.isMatch(s, p);
	//	println("44通配符匹配 result = {0}", result);
	//}

	//// 46全排列
	//{
	//	Solution46 solution;
	//  vector<int> nums{ 1,2,3 };
	//	auto results = solution.permute(nums);
	//	println("46全排列 result.size() = {0}", results.size());
	//	for (const auto& result : results) {
	//		for (const auto& i : result)
	//			print("{0} ", i);
	//		println("");
	//	}
	//}

	//// 47全排列II
	//{
	//	Solution47 solution;
	//	vector<int> nums{ 0,1,0,0,9 };
	//	auto results = solution.permuteUnique(nums);
	//	println("47全排列II result.size() = {0}", results.size());
	//	for (const auto& result : results) {
	//		for (const auto& i : result)
	//			print("{0} ", i);
	//		println("");
	//	}
	//}

	//// 48旋转图像
	//{
	//	Solution48 solution;
	//	vector<vector<int>> matrix{ {1,2,3},{4,5,6},{7,8,9} };
	//	solution.rotate(matrix);
	//	println("48旋转图像");
	//	for (const auto& row : matrix) {
	//		for (const auto& i : row)
	//			print("{0} ", i);
	//		println("");
	//	}
	//}

	//// 49字母异位词分组
	//{
	//	Solution49 solution;
	//	vector<string> strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
	//	auto results = solution.groupAnagrams(strs);
	//	println("49字母异位词分组 result.size() = {0}", results.size());
	//	for (const auto& result : results) {
	//		for (const auto& str : result)
	//			print("{0} ", str);
	//		println("");
	//	}
	//}

	//// 50Pow(x, n)
	//{
	//	Solution50 solution;
	//	double x = 2.0;
	//	int n = 10;
	//	auto result = solution.myPow(x, n);
	//	println("50Pow(x, n) result = {0}", result);
	//}

	//// 100031计算K置位下标对应元素的和
	//{
	//	Solution100031 solution;
	//	vector<int> nums{ 4,3,2,1 };
	//	int k = 2;
	//	auto result = solution.sumIndicesWithKSetBits(nums, k);
	//	println("100031计算K置位下标对应元素的和 result = {0}", result);
	//}

	//// 100040让所有学生保持开心的分组方法数
	//{
	//	Solution100040 solution;
	//	vector<int> nums{ 1,1,0,1 };
	//	auto result = solution.countWays(nums);
	//	println("100040让所有学生保持开心的分组方法数 result = {0}", result);
	//}

}