#include <iostream>

int main()
{
    int number = 1;
    for (int i = 2; i <= 20; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (number * j % i == 0)
            {
                number *= j;
                break;
            }
        }
    }

    std::cout << number << '\n';
}
