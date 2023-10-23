#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAX_N = 105;
const int MAX_L = 105;
const int INF = 1e9;

int dp[MAX_N][MAX_L][MAX_L];
string codeword;
int l, p, q;

int solve(int pos, int length, int last) {
    if (length == l) {
        return 0;
    }
    if (pos == codeword.size()) {
        return INF;
    }
    int &result = dp[pos][length][last];
    if (result != -1) {
        return result;
    }
    
    result = INF;
    // Add a character to the codeword
    int time_added = (length + 1) * p;
    result = min(result, time_added + solve(pos + 1, length + 1, last));
    
    // Duplicate the string if it's possible
    int match_len = 0;
    for (int i = pos; i < codeword.size(); i++) {
        if (codeword[i] == codeword[last]) {
            match_len++;
            if (match_len >= 2) {
                int time_added = match_len * q;
                result = min(result, time_added + solve(i + 1, length + match_len, i));
            }
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> l >> p >> q;
        cin >> codeword;
        
        int min_time = solve(0, 0, 0);
        cout << min_time << endl;
    }
    return 0;
}
