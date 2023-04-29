# 2N-Prisoners-Riddle
During Februar 2023, Itay Otolengi and I encountered a riddle we did not know the answer to. We decided using a bit of brute-force approach to tackle the problem. The riddle and its answer are documented on the README file

The problem:

There is a prison of 2n prisoners.
Each prisoner may choose n numbers between (1:2n). Each prisoner receives a unic secret number which is not visible to him or to other prisoners.
The prisoners may not talk to each other during the choose / receive operations but only before the start of the game to choose a staregy.
Find a startegy with which, the prisoners have a probabilty C for everybody to choose their number.
***C must be positive and independent of n***

Solution:
The current solution is a very basic brute-force with no optimization. Therefore its operation time is somewhere like: O((2n!)*((2n choose n)^2n)).
Therefore on a regular pc I managed to see only the options for n = 1, 2, 3.
All of the options showed a decrease in the maximal probability of success. In addition the best startegy always seems to be: half of the prisoners should choose the first half of numbers, and the other half the second half.
Itay managed to optimize the code and receive the same outcomde for n=4, 5 - the cpp file.
After we showed the problem to Noam Tashma, a mathematical proof was given that the problem is not solveable. Probably a gag of some riddle maker! (or just a miscalculation for whom given solution...)