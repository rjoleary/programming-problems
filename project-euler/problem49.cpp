#include <iostream>

int main()
{
    bool primeSieve[10000] = {0};
    for (int n = 2; n < 10000; n++)
        if (!primeSieve[n])
            for (int m = 2 * n; m < 10000; m += n)
                primeSieve[m] = true;

    for (int n = 1000; n < 10000; n++)
    {
        if (!primeSieve[n])
        {
            for (int m = n + 1; m < 10000; m++)
            {
                if (!primeSieve[m])
                {
                    int diff = m - n;
                    int o = m + diff;
                    if (o >= 10000)
                        break;
                    if (primeSieve[o])
                        continue;

                    int freqN[10] = {0}, freqM[10] = {0}, freqO[10] = {0};
                    freqN[n%10]++;
                    freqN[n/10%10]++;
                    freqN[n/100%10]++;
                    freqN[n/1000%10]++;
                    freqM[m%10]++;
                    freqM[m/10%10]++;
                    freqM[m/100%10]++;
                    freqM[m/1000%10]++;
                    freqO[o%10]++;
                    freqO[o/10%10]++;
                    freqO[o/100%10]++;
                    freqO[o/1000%10]++;
                    bool isValid = true;
                    for (int i = 0; i < 10; i++)
                    {
                        if (freqN[i] != freqM[i] ||
                            freqM[i] != freqO[i] ||
                            freqM[i] != freqO[i])
                        {
                            isValid = false;
                            break;
                        }
                    }

                    if (isValid)
                        std::cout << n << m << o << '\n';
                }
            }
        }
    }
}
