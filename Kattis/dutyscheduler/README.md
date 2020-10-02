# [RA Duty Scheduler](https://open.kattis.com/problems/dutyscheduler)

"To minimize the maximum number of days" indicates that we need binary search on the maximum number of days and check if there is a such assignment.

Given the maximum number of days to which any RAs may be assigned (say d), we can use construct a graph and perform network flow algorithm. The graph is like:
- (S, ra, d): node S to a node for one RA with capacity d.
- (ra, day, 1): a node for one RA to a node for a day with capacity 1, where that RA can be assigned to that day.
- (day, T, 2): a node for a day to node T with capacity 2.

There is an assignment when the maximum number of days to which any RAs may be assigned is d iff the maximum flow for above graph is 2n. Then we can recover the actual assignment from the residual graph. 