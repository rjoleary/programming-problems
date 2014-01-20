#include <array>
#include <iostream>
#include <set>

int main()
{
    typedef std::array<int,200> Integer;
    std::set<Integer> powers;
    for (int a = 2; a <= 100; a++)
    {
        Integer power;
        power.fill(0);
        power[0] = a % 10;
        power[1] = a / 10 % 10;
        power[2] = a / 100;
        for (int b = 2; b <= 100; b++)
        {
            int carry = 0;
            for (int i = 0; i < power.size(); i++)
            {
                int digit = power[i] * a + carry;
                power[i] = digit % 10;
                carry = digit / 10;
            }
            powers.insert(power);
        }
    }
    std::cout << powers.size() << '\n';
}
