# [Tomography](https://open.kattis.com/problems/tomography)

Greedy algorithm. 

Before all, we know the sum of each row (say r<sub>i</sub>) cannot greater than n; the sum of each column (say c<sub>i</sub>) cannot greater than m. The sum of all r<sub>i</sub> should be equal to the sum of c<sub>i</sub>.

We know for each r<sub>i</sub>, we need to split it to r<sub>i</sub> different columns. Which r<sub>i</sub> columns should we choose? To leave as many columns as possible (for the other rows), we should always pick the r<sub>i</sub> columns with the largest remaining c<sub>i</sub>. We can simulate the process with a max-heap.