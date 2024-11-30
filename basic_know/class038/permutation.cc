#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> used;
vector<int> ans;

void dfs(int i) {
  if (i == n) {
    for (auto a : ans) {
      cout << a << " ";
    }
    cout << endl;
    return;
  }
  for (int k = 1; k <= n; k++) {
    if (used.find(k) == used.end()) {
      ans.push_back(k);
      used.insert(k);
      dfs(i + 1);
      ans.pop_back();
      used.erase(used.find(k));
    }
  }
}

int main() {
  cin >> n;
  dfs(0);
  return 0;
}