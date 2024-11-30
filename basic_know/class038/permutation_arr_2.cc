// https://leetcode.cn/problems/permutations-ii/description/

/**
示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 */

// 排列这个东西，本质上是，不同的数来到一个位置，选剩下的结果这件事情
// 为什么不声明成全局的？
// 决策不同i位置时，「是否使用过」的概念是隔离的！
// 这个used数组的意思是，这个数有没有被放在过i位置，而不是「是否使用过」！
// 因为使用过的数依然可以使用，比如说在一个数出现重复的情况下
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> src;
vector<vector<int>> res;

void swap(int i, int j) {
  int tmp = src[i];
  src[i] = src[j];
  src[j] = tmp;
}

void dfs(int i) {
  if (i == src.size()) {
    res.push_back(src);
    return;
  }
  unordered_set<int> used;
  for (int j = i; j < src.size(); j++) {
    if (used.find(src[j]) == used.end()) {
      used.insert(src[j]);
      int tmp = src[i];
      src[i] = src[j];
      src[j] = tmp;
      dfs(i + 1);
      tmp = src[i];
      src[i] = src[j];
      src[j] = tmp;
    }
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  src = nums;
  dfs(0);
  return res;
}

int main() {
  int n;
  cin >> n;
  src = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> src[i];
  dfs(0);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
    cout << endl;
  }
}