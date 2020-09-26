# [Card Trading](https://open.kattis.com/problems/cardtrading)

My first thought of this problem is DP, f[i][j] stands for "select j combos from the first i card types", then f[i][j] = max(f[i-1][j-1] + cost of using type i as a combo, f[i-1][j] + cost of not using type i as a combo). Though the first dimension can be saved during the implementation, the solution is still T<sup>2</sup> and will TLE.

Assume we have selected K types as combos, say one of them is i. Denote ui as the cost of using type i as a combo, ni as the cost of not using type i as a combo. Now what if we replace type i with another type j. What's the profit difference?

The difference is ni - ui - (nj - uj) since the cost from other selected types are not changed. Since the target is to maximize the profit, for any given j, we only allow the switch with i iff the difference is positive. Furthermore, consider type k is also currently selected and ni - ui - (nj - uj) > nk - uk - (nj - uj) > 0. It is clear that we want to replace i instead of k with j since otherwise we can then replace i with k to further increase the profit.

So we can use a priority queue (max heap) ordered by ni - ui and keep trying to replace the selected type with largest ni - ui with an unselected type until no replacement can happen.