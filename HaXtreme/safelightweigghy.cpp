#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tw;
    cin >> tw;

    int n;
    cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int min_removed = n + 1;
    vector<bool> cm(n);

    for (int i = 0; i < (1 << n); i++)
    {
        vector<bool> combination(n);
        int trw = 0;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                trw += w[j];
                combination[j] = true;
            }
        }

        if (trw == tw && count(combination.begin(), combination.end(), true) < min_removed)
        {
            min_removed = count(combination.begin(), combination.end(), true);
            cm = combination;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (cm[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}