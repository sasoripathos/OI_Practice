# [Keyboards in Concert](https://open.kattis.com/problems/keyboardconcert)

Greedy algorithm. To minimize the switchs, always pick the instrument that can play the most notes before a necessary switch.
We can use a suffix sum idea to record how many notes a instrument can play before a necessary switch.