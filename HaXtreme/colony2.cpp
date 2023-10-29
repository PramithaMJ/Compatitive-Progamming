#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    // Create a table to store the length of the common substring
    int dp[len1 + 1][len2 + 1];
    int maxLen = 0;   // Variable to store the length of the longest common substring
    int endIndex = 0; // Variable to store the ending index of the longest common substring

    // Initialize the dynamic programming table
    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    endIndex = i - 1;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    // Reconstruct the original message
    string originalMessage;
    for (int i = endIndex - maxLen + 1; i <= endIndex; i++)
    {
        originalMessage += str1[i];
    }

    cout << originalMessage << endl;

    return 0;
}
