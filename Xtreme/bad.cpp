#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, vector<string> > sequences;

    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;

        vector<string> sequenceValues(m);

        for (int j = 0; j < m; ++j)
        {
            cin >> sequenceValues[j];
        }

        for (int j = 0; j < m; ++j)
        {
            for (int k = j + 1; k < m; ++k)
            {
                string prefix = "", suffix = "";
                int len = min(sequenceValues[j].length(), sequenceValues[k].length());

                for (int l = 0; l < len; ++l)
                {
                    if (sequenceValues[j][l] == sequenceValues[k][l])
                    {
                        prefix += sequenceValues[j][l];
                    }
                    else
                    {
                        break;
                    }
                }

                reverse(sequenceValues[j].begin(), sequenceValues[j].end());
                reverse(sequenceValues[k].begin(), sequenceValues[k].end());

                len = min(sequenceValues[j].length(), sequenceValues[k].length());

                for (int l = 0; l < len; ++l)
                {
                    if (sequenceValues[j][l] == sequenceValues[k][l])
                    {
                        suffix += sequenceValues[j][l];
                    }
                    else
                    {
                        break;
                    }
                }

                reverse(suffix.begin(), suffix.end());

                if (!prefix.empty() && !suffix.empty())
                {
                    sequences[prefix + suffix].push_back(sequenceValues[j]);
                    sequences[prefix + suffix].push_back(sequenceValues[k]);
                }
            }
        }
    }

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i)
    {
        string oldPassword, newPassword;
        cin >> oldPassword >> newPassword;

        bool reject = false;

        for (auto &seq : sequences)
        {
            string prefix = seq.first;
            vector<string> &values = seq.second;

            if (oldPassword.find(prefix) == 0 && newPassword.find(prefix) == 0)
            {
                string suffix = oldPassword.substr(prefix.length());
                string oldSuffix = oldPassword.substr(prefix.length());
                string newSuffix = newPassword.substr(prefix.length());

                bool foundOld = false, foundNew = false;

                for (auto &value : values)
                {
                    if (value.find(oldSuffix) == 0)
                    {
                        foundOld = true;
                    }

                    if (value.find(newSuffix) == 0)
                    {
                        foundNew = true;
                    }
                }

                if (foundOld && foundNew)
                {
                    reject = true;
                    break;
                }
            }
        }

        if (reject)
        {
            cout << "REJECT" << endl;
        }
        else
        {
            cout << "OK" << endl;
        }
    }

    return 0;
}