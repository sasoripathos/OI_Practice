# [Ozljeda](https://open.kattis.com/problems/ozljeda)

Since a xor a = 0 for any number a, so the sequence is looping over n+1 numbers (the given n numbers and the xor of these n numbers). So for each query we only need to care about at most n + 1 numbers. Furthermore, due to the cancellation of xor, we can use a similar idea as prefix sum to save more time.