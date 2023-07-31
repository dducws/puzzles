**Recursion can actually be broken down into three steps:**

1. The base step (stops recursion).
2. The Minimization step (creates the smallest possible instance of a problem. Example: a 500-element array turned into a 1 or 2-element array).
3. The Solution step (This handles the solution for the 1 or 2-element array rather than the 500 elements).

Once the function arrives at the Solution step, the array has already been broken down to its smallest possible version. It then solves the smallest problem and works its way up, solving and handling the rest of the array.


## Resources

- Thinking Like a Programmer: An Introduction to Creative Problem Solving [(Chapter 6)][1]
- Recursion (Think Like a Programmer) [(YouTube)][2]
- Backtracking (Think Like a Programmer) [(YouTube)][3]


[1]: https://nostarch.com/download/samples/TLAP_ch6.pdf
[2]: https://www.youtube.com/watch?v=oKndim5-G94
[3]: https://www.youtube.com/watch?v=gBC_Fd8EE8A
