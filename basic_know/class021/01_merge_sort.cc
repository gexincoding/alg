#include <iostream>
#define N 10
using namespace std;

int a[N], help[N];

void merge(int l, int r, int m) {
  int i = l, p = l, q = m + 1;
  while (p <= m && q <= r) help[i++] = a[p] <= a[q] ? a[p++] : a[q++];
  while (p <= m) help[i++] = a[p++];
  while (q <= r) help[i++] = a[q++];
  for (int i = l; i <= r; i++) a[i] = help[i];
}

void msort_dfs(int l, int r) {
  if (l == r) return;
  int m = (l + r) / 2;
  msort_dfs(l, m);
  msort_dfs(m + 1, r);
  merge(l, r, m);
}

void mort() {
  // i表示当前需要按照i个一组局部排序的方式对数组进行一遍操作
  for (int i = 1; i <= N; i *= 2) {
    int l = 0;
    while (l <= N - 1) {
      int m = l + i - 1, r = l + 2 * i - 1;
      if (m + 1 >= N) break;
      if (r >= N) r = N - 1;
      merge(l, r, m);
      l = r + 1;
    }
  }
}

int main() {
  for (int i = 0; i < N; i++) cin >> a[i];
  // msort_dfs(0, N - 1);
  mort();
  for (int i = 0; i < N; i++) cout << a[i] << " ";
  cout << endl;
}
