/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) {
      return combinations;
    }
    unordered_map<char, string> phoneMap{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string combination;
    backtrack(combinations, phoneMap, digits, 0, combination);
    return combinations;
  }

  void backtrack(vector<string>&                    combinations,
                 const unordered_map<char, string>& phoneMap,
                 const string&                      digits,
                 int                                index,
                 string&                            combination) {
    if (index == digits.length()) {
      combinations.push_back(combination);
    } else {
      char          digit   = digits[index];
      const string& letters = phoneMap.at(digit);
      for (const char& letter : letters) {
        combination.push_back(letter);
        backtrack(combinations, phoneMap, digits, index + 1, combination);
        combination.pop_back();
      }
    }
  }
};
// @lc code=end
