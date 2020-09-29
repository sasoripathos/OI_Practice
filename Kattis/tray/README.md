# [Tray Bien](https://open.kattis.com/problems/tray)

DFS with backtracking. For DFS, we can pick the first available solt (by loop though row and column) and try to put a tray. Since the trays are only one by one or one by two and based on the above loop strategy. There are at most 3 different ways to put a tray.

Simple DFS will TLE. So we can choose to record states. Given the first available solt, there are at most 64 different states. That's because one tray can at most affect 2 columns, 2 columns has 6 slots so there are at most 2<sup>6</sup> = 64 different states. Then we can record states based on the first available solt and the state of two columns (the column of the first available solt and the next one).