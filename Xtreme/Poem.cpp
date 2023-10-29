#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string getRhymeScheme(vector<vector<string>>& rhymes, vector<string>& passage) {
    map<string, char> rhymeMap;
    char label = 'A';

    for (vector<string>& group : rhymes) {
        for (string& word : group) {
            rhymeMap[word] = label;
        }
        if (label != 'X') {
            label++;
        }
    }

    string result = "";
    for (string& line : passage) {
        string lastWord = "";
        for (int i = line.size() - 1; i >= 0; i--) {
            if (line[i] == ' ') {
                break;
            }
            lastWord = line[i] + lastWord;
        }
        // Convert the last word to lowercase for case-insensitive comparison
        transform(lastWord.begin(), lastWord.end(), lastWord.begin(), ::tolower);
        if (rhymeMap.count(lastWord) == 0) {
            result += 'X';
        } else {
            result += rhymeMap[lastWord];
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<string> > rhymes(n);
    for (int i = 0; i < n; i++) {
        string word;
        while (cin >> word) {
            rhymes[i].push_back(word);
            if (cin.get() == '\n') {
                break;
            }
        }
    }

    cin.ignore();
    vector<string> passage(m);
    for (int i = 0; i < m; i++) {
        getline(cin, passage[i]);
    }

    string rhymeScheme = getRhymeScheme(rhymes, passage);
    cout << rhymeScheme << endl;

    return 0;
}
