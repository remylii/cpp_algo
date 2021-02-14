#include <iostream>
#include <vector>
using namespace std;

int main() {
  /**
   * 1. basecase
   *  opt[0] = 0
   * 2.
   *  opt[1] = 1
   *  opt[2] = 1
   *  opt[3] = 2
   *  opt[4] = 2
   *  opt[5] = 1
   *
   *
   */
  int n = 3;
  int amount = 11;
  int coins[] = {1, 2, 5};
  vector<int> opt(n, 99999999);
  opt[0] = 0;  // basecase

  for (int i = 1; i < amount + 1; ++i) {
    for (int c : coins) {
      if (c >= i) {
        opt[i] = min(opt[i - c] + 1, opt[i]);
      }
    }
  }

  for (auto x : opt) {
    cout << x << endl;
  }

  cout << opt[amount] << endl;
}