# [March of the Penguins](https://open.kattis.com/problems/marchofpenguins)

Classic maximum flow problem with special graph construction. For ice piece i, no matter how many penguins will land on it, only m<sub>i</sub> penguins can jump off. So for each ice piece, we need to two points, p<sub>i1</sub> and p<sub>i2</sub>, in the residual graph. We generally have the following edges in the graph:

* (S, p<sub>i1</sub>, n<sub>i</sub>): stands for there are n<sub>i</sub> penguins already on the i-th ice piece.
* (p<sub>i1</sub>, p<sub>i2</sub>, m<sub>i</sub>): as the restrict "at most m<sub>i</sub> penguins can jump off the ith ice piece".
* (p<sub>i2</sub>, p<sub>j1</sub>, v): iff a penguin can jump from the i-th ice piece to the j-th ice piece, v can be any value >= m<sub>i</sub>

"All penguins can meet at the i-th ice piece" means all penguins can lands on the i-th ice piece, that means the maximum flow from S to p<sub>i1</sub> is equal to the number of penguins. We just need to loop through the ice piece and check the maximum fow.

