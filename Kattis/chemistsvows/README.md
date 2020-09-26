# [Chemist's vows](https://open.kattis.com/problems/chemistsvows)

## [Partial Solution](chemistsvows1.cpp) (4/5 Test Cases)

Brute force, use a DFS to check if a word is speakable. Cutting branch by record some search result.

## [Accepted Solution](chemistsvows.cpp)

The DFS is still not fast enough after cutting some branches. A DP idea is much faster. f[i] be if a word's first i leters are speakable. f[i] = f[j] AND (word[j+1 .. i] is an atomic symbol).