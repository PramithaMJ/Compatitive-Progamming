#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MOD = 998244353;
const int MAX_LEN = 32;

vector<string> strings;
unordered_set<string> substrings;

int main() {
  int M;
  cin >> M;

  strings.resize(M);
  for (int i = 0; i < M; i++) {
    cin >> strings[i];
  }

  // Calculate all substrings of length 32 of the given strings.
  for (string s : strings) {
    for (int i = 0; i < s.size() - 31; i++) {
      substrings.insert(s.substr(i, 32));
    }
  }

  // Calculate the sum of the powers of all strings of length 32.
  int sum = 0;
  for (int i = 0; i < 2^MAX_LEN; i++) {
    string str = "";
    for (int j = 0; j < MAX_LEN; j++) {
      str += (i & (1 << j)) ? '1' : '0';
    }

    // Check if the string contains any substrings of length 32 that are equal to one of the given strings.
    bool contains = false;
    for (int j = 0; j < str.size() - 31; j++) {
      if (substrings.count(str.substr(j, 32))) {
        contains = true;
        break;
      }
    }

    // Add the power of the string to the sum.
    if (contains) {
      sum += (1LL << (2 * MAX_LEN)) % MOD;
    } else {
      sum += (((1LL << MAX_LEN) - M - 1) * ((1LL << MAX_LEN) - 1)) % MOD;
    }
  }

  // Calculate the sum modulo 998244353.
  sum %= MOD;

  // Print the answer.
  cout << sum << endl;

  return 0;
}
