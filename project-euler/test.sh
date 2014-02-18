#!/usr/bin/env bash

# Running this script will compile and run all the C++ problems. Their outputs
#  will be compared with the answers in `answers.txt`.

for file in $(find -regex '\./problem[0-9]+[a-z]*\.cpp' | sort -t m -k 2n); do
    number=$(echo "$file" | egrep -o '[0-9]+')
    answer=$(sed -n "${number}p" < 'answers.txt')
    if clang++ -Wall -Wextra -pedantic -std=c++11 "$file" -o test.out; then
        if [ "$(./test.out)" -eq $answer ]; then
            echo "Problem $number correct!"
        else
            echo "Problem $number is answered incorrectly; expected ${answer}. =("
        fi
    fi
done
