# [Kolinje](https://open.kattis.com/problems/kolinje)

we need a[i] + b[i] * x >= a[i+1] + b[i+1] * x, so (b[i+1] - b[i]) * x <= a[i] - a[i + 1], for each pair of i and i+1, we can bound the x, then if eventually we can have a valid bound for x, we can just pick a possible answer.
