#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double speed = 2.0;
    double xc = 0.0;
    double yc = 0.0;
    double wx = 10.0;
    double wy = 10.0;

    for (int i = 0; i < n; i++)
    {
        double x0, y0, x1, y1, v;
        cin >> x0 >> y0 >> x1 >> y1 >> v;

        double mx = x0 + (x1 - x0) * (yc - y0) / (y1 - y0);
        double my = yc;
        double distance = sqrt(pow(mx - xc, 2) + pow(my - yc, 2));
        double time = distance / (speed - v);

        if (time >= 0 && time <= 1 && abs(mx - xc - (speed - v) * time) < 1e-9)
        {
            cout << "unsafe" << endl;
            return 0;
        }
    }

    cout << "safe" << endl;

    return 0;
}