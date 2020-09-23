# Square Fields

My solution is DP with state compression (since n is no greater than 15). Works both for easy and hard.

## [Square Fields (Easy)](https://open.kattis.com/problems/squarefieldseasy)

For a n-bit number i, each bit stands for one points. 1 means covered, 0 means not covered. f[i][k] stands for reaching state i with k squares. Then f[i][k] = min(f[i][k], max(f[j][k-1], f[j XOR i][1])), where (j AND i) == j, which means the points covered in state j is a subset of the points covered in state i. The general idea of max(f[j][k-1], f[j xor i][1]) is to find the length of the sqaures needed to cover all points in state i.

## [Square Fields (Hard)](https://open.kattis.com/problems/squarefieldshard)

As above.
