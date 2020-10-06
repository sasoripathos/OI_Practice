# [Card Hand Sorting](https://open.kattis.com/problems/cardhand)

If we know the order of suit and the order of each suit, we know how we will arrange the cards. Then we just need n-LIS moves. So we can loop through all possible suit order and the orders of each suit, do an LIS for each case.