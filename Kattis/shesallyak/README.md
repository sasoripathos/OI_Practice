# [She's All Yak](https://open.kattis.com/problems/shesallyak)

This problem is a modified LIS (Longest Increasing Subsequence).

First, even without the Rule 1 (type), the size of N requires the O(NlogN) algorithm for LIS (there are plenty of explanation for the O(NlogN) algorithm on Google. e.g. [here](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)). Let's denote:

- q is the list we maintain for bisection in the O(NlogN) algorithm.
- Let q[i] be the **index** of a dance with smallest level of flair (S value) value such that the LIS ended at S<sub>q[i]</sub> has length i. (This is a small adjustment for this problem)

Now we need to consider how to handle the Rule 1. During the bisection process for S<sub>i</sub>, let *mid* is the current middle point. Then there are the following cases:

1. if S<sub>q[mid]</sub> < S<sub>i</sub> and C<sub>q[mid]</sub> != C<sub>i</sub>, then *mid + 1* is a potential length for the LIS ended at S<sub>i</sub>. We need to keep search on the interval [mid + 1, r] as normal.
2. if S<sub>q[mid]</sub> < S<sub>i</sub> and C<sub>q[mid]</sub> == C<sub>i</sub>, then *mid* must be a potential length for the LIS ended at S<sub>i</sub>. Why? Since in the LIS ended at S<sub>q[mid]</sub>, the second last element must be also < S<sub>i</sub> and is in a different type. We still need to check if *mid + 1* is a potential length for the LIS ended at S<sub>i</sub> before we keep search on the interval [mid+1, r].
3. if S<sub>q[mid]</sub> >= S<sub>i</sub>, then for sure *mid + 1* can never be a potential length for the LIS ended at S<sub>i</sub>. We need to keep search on the interval [l, mid - 1] as normal.

How the perform the further check in case 2? My solution is to maintain another list q2, q2[i] be the **index** of a dance with smallest level of flair (S value) value such that the LIS ended at S<sub>q2[i]</sub> has length i **and S<sub>q[i]</sub> <= S<sub>q2[i]</sub> and C<sub>q[i]</sub> != C<sub>q2[i]</sub>**. 

Then in Case 2, the further check is: if S<sub>q2[mid]</sub> < S<sub>i</sub>, then *mid + 1* must be a potential length for the LIS ended at S<sub>i</sub>.

Why this solution is correct? We need to consider why we maitain the list q as the original O(NlogN) algorithm suggested. We always let q[i] corresponds to smallest S value since with the same LIS length, the smallest S value can be used to extend to the most LIS for the following S. So for S<sub>i</sub> with the same type as S<sub>q[i]</sub>, we only need to check if S<sub>q2[i]</sub> can be used to extend to a LIS for S<sub>i</sub>. If not, the other larger S value can definitely not be used to extend to a LIS for S<sub>i</sub>.

