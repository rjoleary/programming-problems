#include <iostream>

const int digitCount = 10;

void addTo(int *lhs, const int *rhs);
void mulBy(int *lhs, int rhs);

int main()
{
    // the extra 1 is for overflow
    int sum[digitCount+1] = {0};

    // calculate the sum
    // 1000 does not need to be counted
    for (int i = 1; i < 1000; i++)
    {
        int product[digitCount+1] = {1};
        for(int j = 0; j < i; j++)
            mulBy(product, i);

        addTo(sum, product);
    }

    for (int i = digitCount - 1; i >= 0 ; i--)
        std::cout << sum[i];
    std::cout << '\n';
}

void addTo(int* lhs, const int* rhs)
{
    for (int i = 0; i < digitCount; i++)
    {
        lhs[i] += rhs[i];
        lhs[i+1] += lhs[i] / 10;
        lhs[i] %= 10;
    }
}

void mulBy(int* lhs, int rhs)
{
    for (int i = 0; i < digitCount; i--)
        lhs[i] *= rhs;

    for (int i = 0; i < digitCount; i++)
    {
        lhs[i+1] += lhs[i] / 10;
        lhs[i] %= 10;
    }
}
