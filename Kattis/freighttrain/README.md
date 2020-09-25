# [Freight Train](https://open.kattis.com/problems/freighttrain)

The problem asks to "minimize the maximum", which is a strong indicator of binary search. I need to binary search on the possible answers and check if an answer can satisfy all the requirements.

More specifically, I first use binary search to "guess" an answer, say ans, which stands for "the length of the largest train heading for Luxembourg". Then given the ans as an addictional constraint, I check whether it is possible to spilt the train.

When performing the check, there is an observation: given ans, we don't want to have a train just for empty wagons unless there are more than ans consecutive empty wagons that can be carried by the next train.