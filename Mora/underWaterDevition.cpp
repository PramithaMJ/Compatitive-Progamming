#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

double calculate_area(double m1, double c1, double m2, double c2)
{
    return abs(c1 - c2) / sqrt(1 + m1 * m1);
}

pair<double, double> process_image(const vector<string> &image)
{
    vector<int> x_coords, y_coords;
    for (int y = 0; y < 50; ++y)
    {
        for (int x = 0; x < 50; ++x)
        {
            if (image[y][x] == '1')
            {
                x_coords.push_back(x);
                y_coords.push_back(y);
            }
        }
    }

    int n = x_coords.size();
    double sum_x = 0, sum_y = 0, sum_xx = 0, sum_xy = 0;

    for (int i = 0; i < n; ++i)
    {
        sum_x += x_coords[i];
        sum_y += y_coords[i];
        sum_xx += x_coords[i] * x_coords[i];
        sum_xy += x_coords[i] * y_coords[i];
    }

    double slope = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / n;

    return make_pair(slope, intercept);
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(); 
    vector<double> scores;
    vector<string> image(50);

    for (int i = 0; i < N; ++i)
    {
        string skip;
        getline(cin, skip);

        for (int j = 0; j < 50; ++j)
        {
            getline(cin, image[j]);
        }

        pair<double, double> result = process_image(image);
        double m = result.first;
        double c = result.second;

        double area = calculate_area(m, c, 0, 0);
        double score = 2 * pow(2, -pow(area / 150, 2)) - 1;
        scores.push_back(score +1);
    }

    for (double score : scores)
    {
        if (score < 0)
        {
            cout << "x" << endl;
        }
        else
        {
            pair<double, double> result = process_image(image);
            printf("%.15f %.15f\n", result.first, result.second);
        }
    }

    return 0;
}