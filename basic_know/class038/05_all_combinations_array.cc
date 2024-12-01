#include <algorithm>
#include <vector>
using namespace std;


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
