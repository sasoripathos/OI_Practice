# [Maximizing (And Minimizing) Your Winnings](https://open.kattis.com/problems/maximizingwinnings)

Simple DP problem. Let map be the given matrix.

f[i][j] is the max amount of money the player can earn after i turns and stop in room j: f[i][j] = max(f[i][j], f[i-1][k] + map[k][j]);

g[i][j] is the min amount of money the player can earn after i turns and stop in room j: g[i][j] = min(g[i][j], g[i-1][k] + map[k][j]);
