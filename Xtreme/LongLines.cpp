#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<int> ans(n);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i)
    {
        int cnt = 1;

        while (!s.empty() && heights[i] >= s.top())
        {
            s.pop();
            ++cnt;
        }

        if (s.empty())
        {
            --cnt;
        }

        ans[i] = cnt;
        s.push(heights[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

