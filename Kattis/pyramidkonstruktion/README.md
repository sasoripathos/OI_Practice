# [Parallel Analysis](https://open.kattis.com/problems/pyramidkonstruktion)

It is easy to find out that to minimize the number of bricks, only the first layer need one 2x2 brick. The i-th layers need (2(i-1)) 4x2 bricks. So for input, we can use two 2x2 bricks as one 4x2 bricks if needed. Then the answer is the difference between the ideal solution and the input after replacing some 4x2 bricks with extra 2x2 bricks we have.