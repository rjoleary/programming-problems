#include <iostream>
#include <numeric>

struct BigNum {
    std::vector<uint8_t> digits; // little-endian

    BigNum() {
    }

    BigNum(size_t val) {
        while (val) {
            digits.push_back(val % 10);
            val /= 10;
        }
    }

    BigNum operator+(const BigNum &other) const {
        BigNum sum;
        size_t maxSize = std::max(digits.size(), other.digits.size());
        sum.digits.reserve(maxSize + 1);

        uint8_t carry = 0;
        for (size_t i = 0; i < maxSize + 1; i++) {
            uint16_t digitSum = carry;
            if (i < digits.size()) {
                digitSum += digits[i];
            }
            if (i < other.digits.size()) {
                digitSum += other.digits[i];
            }
            carry = digitSum / 10;
            digitSum %= 10;
            sum.digits.push_back(digitSum);
        }
        while (!sum.digits.empty() && sum.digits.back() == 0) {
            sum.digits.pop_back();
        }
        return sum;
    }

    BigNum operator*(const BigNum &other) const {
        BigNum product;
        for (size_t i = 0; i < digits.size(); i++) {
            BigNum copy = other;
            for (auto &d : copy.digits) {
                d *= digits[i]; // max = 9 * 9 = 81 < 256
            }
            copy.digits.insert(copy.digits.begin(), i, 0); // shift
            product = product + copy;
        }
        return product;
    }

    bool operator==(const BigNum &other) const {
        size_t maxSize = std::max(digits.size(), other.digits.size());
        for (size_t i = 0; i < maxSize; i++) {
            if (i >= digits.size() && other.digits[i] != 0) {
                return false;
            } else if (i >= other.digits.size() && digits[i] != 0) {
                return false;
            } else if (digits[i] != other.digits[i]) {
                return false;
            }
        }
        return true;
    }
};

std::ostream & operator<<(std::ostream &s, const BigNum &bn) {
    if (bn.digits.empty()) {
        s << 0;
    }
    for (auto it = bn.digits.crbegin(); it != bn.digits.crend(); ++it) {
        s << (int)*it;
    }
    return s;
}

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
        size_t numOnes;
        Num a;

        friend class ::ECFConstants;
        Iterator(Num nextEven, size_t numOnes, Num a)
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
                nextEven = nextEven + 2;
            } else {
                numOnes--;
                a = 1;
            }
            return *this;
        }

        // In theory, there is no end. This never matches end.
        bool operator!=(const Iterator &) const {
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
        bool operator!=(const Iterator &) const {
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
        std::cout << fraction.num << '/' << fraction.den << '\n';
    }
}

int main() {
    // Debug: printExpansionsOfE();

    auto cf = ECF().begin();
    for (int i = 0; i < 99; i++) {
        ++cf;
    }
    const auto &digits = (*cf).num.digits;
    std::cout << std::accumulate(digits.begin(), digits.end(), 0) << '\n';
    return 0;
}
