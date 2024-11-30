// 测试链接 : https://leetcode.cn/problems/permutations/
#include <vector>
using namespace std;
vector<int> a;
vector<vector<int>> res;

void swap(int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

void dfs(int idx) {
  if (idx == a.size()) {
    res.push_back(a);
    return;
  }
  for (int j = idx; j < a.size(); j++) {
    swap(idx, j);
    dfs(idx + 1);
    swap(idx, j);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  a = nums;
  dfs(0);
  return res;
}

//
int main() {}