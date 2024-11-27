// 测试链接 https://leetcode.cn/problems/reverse-pairs/
// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j)
// 称作一个重要翻转对。

// 你需要返回给定数组中的重要翻转对的数量。

#include <iostream>
using namespace std;
using ll = long long;
int n, a[50000], help[50000];
ll num;

void merge(int l, int m, int r) {
  int i = l, p = l, q = m + 1;
  if (p <= l && q <= r) {
  }
}

void dfs(int l, int r) {
  if (l == r) return;
  int m = (l + r) / 2;
  dfs(l, m);
  dfs(m + 1, r);
  merge(l, m, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  dfs(0, n - 1);
  cout << num << endl;
}