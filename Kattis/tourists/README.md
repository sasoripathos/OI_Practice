# [Tourists](https://open.kattis.com/problems/tourists)

Lowest common ancestor. 

The given graph is a tree. The path between a pair x, y must go though their lowest common ancestor, say lca. By finding the
Lowest common ancestor, we can easily find the node count between a pair. In this problem, we can loop though each pair with
compleity n+n/2+n/3+n/4+... = O(nlgn). Finding lca overall (including necessary setup) also takes about O(nlogn).