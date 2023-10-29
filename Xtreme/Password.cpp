#include <iostream>
#include <vector>
#include <string>

using namespace std;


string shouldReject(const vector<vector<string> > &iteratedSequences, const string &pOld, const string &pNew)
{
    for (const vector<string> &sequence : iteratedSequences)
    {
        string commonPrefix = "";
        string commonSuffix = "";

        for (const string &value : sequence)
        {
            if (pOld.find(commonPrefix + value) == 0)
            {
                commonPrefix += value;
            }
            else
            {
                break;
            }
        }

        for (auto it = sequence.rbegin(); it != sequence.rend(); ++it)
        {
            const string &value = *it;
            size_t suffixPos = pOld.rfind(value + commonSuffix);

            if (suffixPos != string::npos && suffixPos + value.length() == pOld.length())
            {
                commonSuffix = value + commonSuffix;
            }
            else
            {
                break;
            }
        }

        if (pOld == commonPrefix + commonSuffix)
        {
            for (const string &value : sequence)
            {
                if (pNew == commonPrefix + value + commonSuffix)
                {
                    return "REJECT";
                }
            }
        }
    }
    return "OK";
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string> > iteratedSequences(n);

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        iteratedSequences[i].resize(m);

        for (int j = 0; j < m; j++)
        {
            cin >> iteratedSequences[i][j];
        }
    }

    int p;
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        string pOld, pNew;
        cin >> pOld >> pNew;

        string result = shouldReject(iteratedSequences, pOld, pNew);
        cout << result << endl;
    }

    return 0;
}
