#include <iostream>
#include <set>

unsigned getCycleLength(unsigned value);

int main()
{
    unsigned maxCycle = 0, maxValue = 0;
    for (unsigned i = 2; i < 1000; i++)
    {
        unsigned cycleLength = getCycleLength(i);
        if (cycleLength > maxCycle)
        {
            maxCycle = cycleLength;
            maxValue = i;
        }
    }
    std::cout << maxValue << '\n';
}

unsigned getCycleLength(unsigned value)
{
    std::set<unsigned> prevRemainders;
    prevRemainders.insert(0);

    unsigned dividend = 1;
    while (dividend <= value) dividend *= 10;

    unsigned remainder = dividend % value;
    unsigned cycles = 0;

    while (prevRemainders.find(remainder) == prevRemainders.end())
    {
        prevRemainders.insert(remainder);
        remainder = 10 * remainder % value;

        cycles++;
    }

    return cycles;
}
