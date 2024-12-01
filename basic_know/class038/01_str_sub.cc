// 返回字符串的全部子序列
// https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
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

char path[10000];
int nidx = 0;

unordered_set<string> ans_set2;
void dfs2(int i) {
  if (i == s.size()) {
    // [0, idx] 作为答案
    ans_set2.insert(string(path, path + nidx));
    return;
  }

  path[nidx++] = s.at(i);
  dfs2(i + 1);
  nidx--;
  dfs2(i + 1);
}

char path2[10000];
unordered_set<string> ans_set3;

void dfs3(int i, int nidx) {
  if (i == s.size()) {
    ans_set3.insert(string(path2, path2 + nidx));
    return;
  }
  path2[nidx] = s.at(i);
  // 为什么先调nidx+1
  dfs3(i + 1, nidx + 1);
  dfs3(i + 1, nidx);
}

void test() {
  dfs(0);
  for (auto s : ans_set) cout << s << " ";
  cout << endl;

  dfs2(0);
  for (auto s : ans_set2) cout << s << " ";
  cout << endl;

  dfs3(0, 0);
  for (auto s : ans_set3) cout << s << " ";
  cout << endl;
}

// 为了测试
vector<string> generatePermutation(string str) {
  s = str;
  dfs3(0, 0);
  vector<string> res;
  for (auto s : ans_set3) res.push_back(s);
  return res;
  // write code here
}

int main() {
  cin >> s;
  test();
  return 0;
}