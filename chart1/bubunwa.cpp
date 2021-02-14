#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > memo;
int global_count = 0;

bool func(int i, int w, const vector<int> &a) {
  cout << "  global_count: " << global_count << ", i: " << i << ", w: " << w
       << endl;
  global_count++;

  // basecase
  if (i == 0) {
    if (w == 0)
      return true;
    else
      return false;
  }

  // memo をチェック
  if (memo[i][w] != -1) {
    cout << "  exist memo" << endl;
    return memo[i][w];
  }

  // a[i -1] を選ばない場合
  if (func(i - 1, w, a)) return memo[i][w] = 1;

  // a[i - 1] を選ぶ場合
  if (func(i - 1, w - a[i - 1], a)) return memo[i][w] = 1;

  // どちらも false の場合は false
  return memo[i][w] = 0;
}

int main() {
  auto start = chrono::system_clock::now();

  int n = 4;
  int org_data[] = {1, 2, 5, 7};
  vector<int> a(org_data, end(org_data));
  int w = 11;

  memo.assign(n + 1, vector<int>(w + 1, -1));
  if (func(n, w, a)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  memo.clear();

  auto end = chrono::system_clock::now();
  auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
  cout << msec << " milli sec" << endl;
}