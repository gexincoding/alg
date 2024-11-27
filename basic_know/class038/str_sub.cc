// 返回字符串的全部子序列
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

string s;
string ans = "";
unordered_set<string> ans_set;

// dfs(i) 表示：当前来到i位置做选择，可以选择要当前字符还是不要当前字符
// 来到每一个位置做选择，到达最后的时候，选择完毕，泥记录结果
void dfs(int i) {
  if (i == s.size()) {
    ans_set.insert(ans);
    return;
  }
  char c = s.at(i);
  string temp = ans;
  ans += c;
  dfs(i + 1);
  ans.pop_back();
  dfs(i + 1);
}

int main() {
  cin >> s;
  dfs(0);
  for (auto s : ans_set) cout << s << endl;
  return 0;
}