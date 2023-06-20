### Strategy 
## Three-Step Recursion Problem Solving
**Step 1: Write an iterative function to solve the problem**: Start by writing an iterative function that solves the problem without using recursion. This will serve as the basis for your recursive solution.
**Step 2: Write a "dispatcher" function**: Create a dispatcher function that calls the iterative function you wrote in step 1. The dispatcher function will handle the recursive logic by making recursive calls to itself or other recursive helper functions.
**Step 3: In the dispatcher, replace all calls to the iterative function with a call to the dispatcher**: Modify the iterative function in step 1 to include calls to the dispatcher function instead of calling itself directly. This will enable the recursion to take place, as the dispatcher function will manage the recursive calls.


## Resources 
- [Thinking Like a Programmer: An Introduction to Creative Problem Solving (Chapter 6)][1]: 



[1]: https://nostarch.com/download/samples/TLAP_ch6.pdf
