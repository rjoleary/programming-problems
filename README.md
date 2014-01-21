Programming Problems
====================

Hello, this is a collection of solutions to programming problems I've worked on
over the past couple years. After finding bits and pieces of these problems all
over my hard drive, I decided to clean them up and organize them into a single
repo. I try my best to only include working solutions. They may not be the
clearest or most optimized since I want to represent solutions I wrote with
minimal help. Remember to try a problem on your own before looking at the
answers!

Sources
-------

The problems come from these sources:

+ [Canadian Computing Competition (ccc)](http://cemc.uwaterloo.ca/Contests/past_contests.html#ccc)
+ [ECOO Programming Contest (ecoo)](http://ecoocs.org/past.php)
+ [Programming Challenges](http://uva.onlinejudge.org/)
+ [Project Euler (project-euler)](http://projecteuler.net/)
+ [Sphere Online Judge (spoj)](http://www.spoj.com/)


Compiling and Running
---------------------

The C++ solutions will compile with:

    g++ -std=c++11 -Wall -pedantic

The Python solutions run with the standard CPython 3.3.

Lua solutions work with the latest LuaJIT.

I'm not as certain about the Haskell and Scheme solutions. I used GHC for
Haskell and DrRacket for Scheme.


Test Cases
----------

I don't provide many test cases. If you want to test them, ECOO and CCC provide
test cases on their website, SPOJ and UVa have online judges and the solutions
for Project Euler can be checked from their website.

I added a short script `test.sh` to compare the outputs of the Project Euler
C++ solutions with the answers located in the file `answers.txt`.


License
-------

The license is found in the `LICENSE.txt` file.
