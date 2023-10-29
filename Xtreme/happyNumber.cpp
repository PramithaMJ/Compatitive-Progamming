#include <iostream>
#include <unordered_set>

bool isHappy(int n)
{
    std::unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end())
    {
        seen.insert(n);
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}

int countHappyNumbers(int a, int b)
{
    int count = 0;
    for (int i = a; i <= b; ++i)
    {
        if (isHappy(i))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    int result = countHappyNumbers(a, b);
    std::cout << result << std::endl;
    return 0;
}
