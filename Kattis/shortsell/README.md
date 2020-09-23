# [Short Sell](https://open.kattis.com/problems/shortsell)

Let a[i] be the price of CryptoKattis on the i-th day. Consider we want to sell on the j-th day and purchase on the i-th day. Then the profit is 100 * a[j] - K * (i - j + 1) - 100 * a[i], which can be rewritten as 100 * a[j] + K * j - 100 * a[i] - K * (i + 1).

So if we decide to purchase on the i-th day, then the maximum profit will purely depends on 100 * a[j] + K * j (since - 100 * a[i] - K * (i + 1) is fixed). So we simply need to maintain the max j < i which has maximum 100 * a[j] + K * j while loop through the date i. Then we can easily get the largest profit.