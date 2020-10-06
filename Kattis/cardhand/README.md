# [Card Hand Sorting](https://open.kattis.com/problems/cardhand)

If we know the order of suit and the order of each suit, we know how we will arrange the cards. Construct a last of each cards target position based on the current position, then we just need (n - LIS) moves to resume the target relative order. So we can loop through all possible suit order and the orders of each suit, do an LIS for each case.

NOTE: in the problem, card A is the largest number.