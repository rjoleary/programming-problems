#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

typedef int64_t Num;

// Integer square root, floor(sqrt(x))
Num isqrt(Num x) {
    // binary search
    Num left = 0, right = x + 1;
    while (left < right - 1) {
        Num middle = (left + right) / 2;
        if (middle * middle <= x) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return left;
}

struct State {
    // a, b / (sqrt(n) - c)
    Num a, b, c;

    bool operator==(const State &other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    State next(Num n, Num nSqrt) {
        Num den = (n - c * c) / b;
        Num wholePart = (nSqrt + c) / den;
        return State{wholePart, den, den * wholePart - c};
    }
};

// Return n as a continued fraction. See definition in problem #64.
// The vector is passed by reference to re-use the allocation for better perf.
void continuedFraction(Num n, std::vector<Num> &outCF) {
    outCF.clear();

    const Num nSqrt = isqrt(n);

    State firstState = State{nSqrt, 1, nSqrt};
    outCF.push_back(firstState.a);
    if (nSqrt * nSqrt == n) return;  // perfect square
    State secondState = firstState.next(n, nSqrt);
    outCF.push_back(secondState.a);
    State nthState = secondState.next(n, nSqrt);

    while (!(nthState == secondState)) {
        outCF.push_back(nthState.a);
        nthState = nthState.next(n, nSqrt);
    }
}

void printContinuedFraction(const Num N, const std::vector<Num> cf) {
    std::cout << "sqrt(" << N << ") = [" << cf[0] << "; (";
    for (size_t i = 1; i < cf.size(); i++) {
        std::cout << cf[i];
        if (i != cf.size() - 1) {
            std::cout << ',';
        }
    }
    std::cout << ")], period=" << (cf.size() - 1) << '\n';
}

int main() {
    const Num N = 10000;

    std::vector<Num> cf;
    cf.reserve(N+1);

    Num oddCount = 0;
    for (int n = 1; n <= N; n++) {
        continuedFraction(n, cf);
        // Debug: printContinuedFraction(n, cf);
        oddCount += (cf.size() - 1) % 2 == 1;
    }
    std::cout << oddCount << '\n';
    return 0;
}
