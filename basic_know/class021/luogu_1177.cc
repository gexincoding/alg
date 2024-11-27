#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comp(int a, int b) { return a < b; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end(), comp);
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
