# [Continuous Median](https://open.kattis.com/problems/continuousmedian)

## [Partial Solution](continuousmedian1.cpp) (11/18 Test Cases)

Since the number set is dynamic and we want to find a specific k-th element, the median, my first thought is BST. I tried an AVL and can get a TLE.

## [Accepted Solution](continuousmedian.cpp)

The TLE above indicates that the we don't want to perform the same 'find' query for each input. So I consider the property of the median. It will always split the inputs into two parts, say a 'smaller' part and a 'larger' part. If I can dynamically maintain the two parts, I shall be able to calculate the median directly. 

Since we know the two parts should have the same number of elements (or one part has exactly one more element when there are odd numbers of inputs), I need two data structures for the two parts and maintain the size difference between them. Which data structures? Since the boundary of the two parts is the median, I only care the biggest number in the smaller part and the smallest number in the larger part. Min-Heap and Max-Heap are good in this case.

In all, the solution is to maintain a Max-Heap for the smaller part of inputs and a Min-Heap for the larger part of inputs, always keep the size difference of the two heaps between 1. The median then can be calculated from the two roots. Implementation details are in the code.
