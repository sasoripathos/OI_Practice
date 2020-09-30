# [Srednji](https://open.kattis.com/problems/srednji)

Since all integers are unique. The required subsequence must contain B. To make the median = B, the number of integers greater than B and the number of integers smaller than B should be equal (ie. gl + gr = sl + sr, which implies sl - gl = gr - sr). Then we can break the sequence into two parts from B and calculate the numbers on both side. 