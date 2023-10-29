#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    string original_word = "";
    int i = 0, j = 0;

    while (i < word1.length() && j < word2.length())
    {
        if (word1[i] == word2[j])
        {
            original_word += word1[i];
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }

    cout << original_word << endl;

    return 0;
}