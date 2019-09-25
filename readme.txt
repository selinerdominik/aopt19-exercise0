## Applied Optimization Exercise 0
1. How we solved the exercise
First off, we had to set up a development environment, which took multiple tries on windows before we got it running. After that we had to familiarize ourselves with how C++ works and how to use Eigen.
Task 1 was very straight forward. We simply had to build the functions from the task inside C++.
For Task 2 we had to iterate over the grid with for-loops. For the two dimensional functions we were able to use the same algorithm. We've decided to implement the multidimensional function using recursion. This naturally leads to long computation times for higher dimension functions.