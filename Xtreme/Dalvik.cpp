#include <iostream>

int computeOutput(int A, int B, int C)
{
    int v0 = A;
    int v1 = B;
    int v2 = C;
    int v3 = 1;
    int v4 = v3 - v3;
    int v5 = v4 - v3;
    int v6 = v3;
    int v7 = v4 - v1;
    int v8 = v0;
    int v9 = v0;
    v9 = v0 + v1;
    int v10 = v4;
    int v11 = v4;
    int v12 = v3;

    while (true)
    {
        v11 = v11 + v1;
        v10 = v10 + v0;
        int v13 = v10;
        int v14 = v4;
        int v15 = v4;

        while (v13 + v13 <= v1)
        {
            v13 = v13 - v1;
            v14 = v14 + v3;
            v15 = v15 + v1;
        }

        if (v13 > v4)
        {
            v13 = v4;
        }

        int v17 = v4;
        int v18 = v3;

        while (v17 + v13 <= v6)
        {
            v17 = v17 + v13;
            v18 = v18 + v3;
        }

        if (v18 <= v12)
        {
            v18 = v3;
        }

        v17 = v17 - v9;
        v18 = v18 + v3;

        if (v18 <= v12 && v17 < v4)
        {
            return v14;
        }

        v12 = v12 + v3;
    }
}

int main()
{
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i)
    {
        int A, B, C;
        std::cin >> A >> B >> C;
        int result = computeOutput(A, B, C);
        std::cout << result << std::endl;
    }

    return 0;
}
