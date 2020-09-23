# [Low Order Zeros](https://open.kattis.com/problems/loworderzeros)

My first thought is brute force and only keep the lowest order non-zero digit. But there are edge cases for this. For example, the lowest orde non-zero digit for 14! is 2, 2 * 15 = 30. But the lowest orde non-zero digit for 15! is 8 instead of 3. This is simply due to there is a new 0 appear during the multiplication and in this case, we need to consider more than the lowest order non-zero digit. So instead of only keeping the lowest order non-zero digit, we keep several more non-zero digits. And the brute force works. 

BTW, I chose to pre calcuate all results within 10<sup>6</sup> to avoid repeaded calculation.


