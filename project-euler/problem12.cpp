#include <iostream>

// Count the divisors of an integer.
int countFactors(int);

int main()
{
    int triangleNumber = 1;
    for (int i = 2; countFactors(triangleNumber) <= 500; i++)
        triangleNumber += i;
    std::cout << triangleNumber << '\n';
}

int countFactors(int x)
{
    int count = 2;
    for (int f = 2; f < x / f; f++)
    {
        int fCount = 1;
        while (x % f == 0)
        {
            fCount++;
            x /= f;
        }
        count *= fCount;
    }
    return count;
}
