// 测试链接 https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469
#include <iostream>
using namespace std;

using ll = long long;  // 为什么需要用ll类型

int a[100001], help[100001];
ll sum = 0, n;

void merge_find(int l, int m, int r) {
  int i = l, p = l, q = m + 1;
  while (p <= m && q <= r) {
    if (a[p] <= a[q]) {
      sum += a[p] * (r - q + 1);  // 这个公式如何推出？
      help[i++] = a[p++];
    } else
      help[i++] = a[q++];
  }
  while (p <= m) help[i++] = a[p++];
  while (q <= r) help[i++] = a[q++];
  for (int i = l; i <= r; i++) a[i] = help[i];
}

void find(int l, int r) {
  if (l == r) return;
  int m = (l + r) / 2;
  find(l, m);
  find(m + 1, r);
  merge_find(l, m, r);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  find(0, n - 1);
  cout << sum << endl;
  return 0;
}
