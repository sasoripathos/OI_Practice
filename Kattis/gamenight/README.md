# [Game Night](https://open.kattis.com/problems/gamenight)

Since the table is circular, then eventually all guests will sit like either AA...ABB...BCC...C or AA...ACC...CBB...B (circularly), then if we know the break point of the circle, the number of people that must move seats is fixed based on which of the two configurations above is chosen.

We can first count the number of A, B, C in the input string (say a, b, c). For each index i, it is easy to calculate how many A/B/Cs in the next a/b/c letters (including the letter at index i). Then we can loop over i as the break point, calculatet the number of moves needed for the two configurations above. Choose the smallest one.