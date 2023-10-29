#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++)
    {
        cin >> heights[i];
    }

    int st = 0;
    int sh = heights[0];
    int ph = heights[0];
    string pt = "";

    for (int i = 1; i < N; i++)
    {
        int cheight = heights[i];
        string ctpye = "";

        if (cheight > ph)
        {
            ctpye = "hill";
        }
        else if (cheight < ph)
        {
            ctpye = "slope";
        }
        else
        {
            ctpye = "flat";
        }

        if (ctpye != pt)
        {
            int duration = i - st;
            if ( pt != "")
            {
                cout << st << "-" << i - 1 << "=" << pt << endl;
            }
            st = i-1 ;
            sh = cheight;
            pt = ctpye;
        }

        ph = cheight;
    }

    int duration = N - st;
    cout << st << "-" << N - 1 << "=" << pt << endl;

    return 0;
}