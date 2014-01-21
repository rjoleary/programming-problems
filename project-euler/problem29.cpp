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
            for (auto &digit : power)
            {
                int value = digit * a + carry;
                digit = value % 10;
                carry = value / 10;
            }
            powers.insert(power);
        }
    }
    std::cout << powers.size() << '\n';
}
