#include <algorithm>
#include <vector>
using namespace std;
// 题目2 : 返回数组的所有组合，可以无视元素顺序。时间复杂度O(2^n * n)
// https://leetcode.cn/problems/subsets-ii/
/**
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 */

vector<int> src;
vector<vector<int>> res;

int path[10];

void dfs(int i, int idx) {
  if (i >= src.size()) {
    res.push_back(vector<int>(path, path + idx));
    return;
  }
  int next = i + 1;
  while (next < src.size() && src[next] == src[i]) next++;
  dfs(next, idx);
  for (int j = 1; j <= next - i; j++) {
    path[idx++] = src[i];
    dfs(next, idx);
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  src = nums;
  sort(src.begin(), src.end());
  dfs(0, 0);
  return res;
}
