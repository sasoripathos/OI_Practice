# [Knockout Tournament](https://open.kattis.com/problems/knockout)

A strong filling is to let the stonger players fight first and try to make them eliminate each other as many as possible. On the other hand, try to give Dale weaker players. I had the general guess of sorting the players but cannot prove its correctness (T.T). So I couldn't convince myself and eventually turn to the [official solution](https://people.bath.ac.uk/masjhd/NWERC/news/nwerc2017slides.pdf) (starting from page 25). And my guess was correct.

It needs some binary number operations to obtain the j range in the solution above. It is easy to figure out how to get the range of j by binding the binary numbers in a binary tree (ie. left child means 0, right child means 1, then a path to leaf is a binary number)
