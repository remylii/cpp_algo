#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

vector<int> convert(int bit, vector<int> data) {
  vector<int> S;

  for (int i = 0; i < data.size(); ++i) {
    if (bit & (1 << i)) {
      S.push_back(data[i]);
    }
  }
  return S;
}

int main() {
  int n = 4;
  int org_data[] = {1, 3, 5, 7};
  vector<int> data(org_data, end(org_data));

  // (1<<n) = 2^n, 今回は 2^4 = 16, {0, 1, ..., n-1} の全探索
  cout << (1 << n) << endl;
  for (int bit = 0; bit < (1 << n); ++bit) {
    cout << bit << endl;
    bitset<8> bs = bitset<8>(bit);
    cout << "  " << bs << endl;
    vector<int> s = convert(bit, data);
    int sum = accumulate(s.begin(), s.end(), 0);
    cout << "  sum: " << sum << endl;
  }
}