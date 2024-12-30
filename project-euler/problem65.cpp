#include <iostream>
#include <numeric>

struct BigNum {

};

typedef BigNum Num;

struct Fraction {
    Num num, den;

    Fraction operator*(const Fraction &other) const {
        return Fraction{num * other.num, den * other.den};
    }

    Fraction operator+(const Fraction &other) const {
        return Fraction{num * other.den + other.num * den, den * other.den};
    }
};

// Continued Fraction constants for mathematical constant e.
class ECFConstants {
  public:
    class Iterator {
        Num nextEven;
        Num numOnes;
        Num a;

        friend class ::ECFConstants;
        Iterator(Num nextEven, Num numOnes, Num a)
            : nextEven(nextEven)
            , numOnes(numOnes)
            , a(a) {
        }

      public:
        Num operator*() const {
            return a;
        }

        Iterator & operator++() {
            // Pattern: [2; (1, 2, 1, 1, 4, 1, 1, 6, 1, 1, 8, 1, 1, 10, ...)]
            if (numOnes == 0) {
                numOnes = 2;
                a = nextEven;
                nextEven += 2;
            } else {
                numOnes--;
                a = 1;
            }
            return *this;
        }

        // In theory, there is no end. This never matches end.
        bool operator!=(const Iterator &other) const {
            return true;
        }
    };

    Iterator begin() const {
        return Iterator(2, 1, 2);
    }

    // In theory there is no end. In practice INT_MAX.
    Iterator end() const {
        return Iterator(0, 0, 0);
    }
};

// Continued fraction for mathematical constant e.
class ECF {
  public:
    class Iterator {
        // Accumulates all the previous constants
        std::vector<Num> accum;
        // Generator for the constants
        ECFConstants::Iterator gen;

        friend class ::ECF;
        Iterator()
            : gen(ECFConstants().begin()) {
            accum.push_back(*gen);
        }

      public:
        Fraction operator*() const {
            Fraction ret{accum[accum.size()-1], 1};
            for (int i = accum.size() - 2; i >= 0; i--) {
                ret = Fraction{accum[i], 1} + Fraction{ret.den, ret.num};
            }
            return ret;
        }

        Iterator & operator++() {
            ++gen;
            accum.push_back(*gen);
            return *this;
        }

        // In theory, there is no end. This never matche end.
        bool operator!=(const Iterator &ecf) const {
            return true;
        }
    };

    Iterator begin() const {
        return Iterator();
    }

    Iterator end() const {
        return Iterator();
    }
};

void printExpansionsOfE() {
    for (const auto fraction : ECF()) {
        std::cout << fraction.num << '/' << fraction.den << " = " << double(fraction.num) / double(fraction.den) << '\n';
    }
}

int main() {
    // Debug: printExapansionsOfE();

    auto cf = ECF().begin();
    for (int i = 0; i < 99; i++) {
        ++cf;
    }
    std::cout << (*cf).num << '\n';
    return 0;
}
