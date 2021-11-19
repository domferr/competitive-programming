# Competitive Programming and Contests

Each problem comes with a solution written in C++ and a test suite. Testing is done by using 
the [GoogleTest](https://github.com/google/googletest) framework.

## Problems

#### Trapping Rain Water | [Solution](https://github.com/domferr/competitive-programming/tree/main/TrappingRainWater)
  
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute 
how much water can be trapped between the blocks during the rainy season. 
Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/trapping-rain-water/0).

#### Sliding Window Maximum | [Solution](https://github.com/domferr/competitive-programming/tree/main/SlidingWindowMaximum)

Given an array arr[] of N elements and integer K, find the maximum for each and every contiguous subarray (window) of 
size K. Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0).

#### Next Larger Element | [Solution](https://github.com/domferr/competitive-programming/tree/main/NextLargerElement)

Given an array arr[] of size N having distinct elements, the task is to find the next greater element for each element 
of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest 
element on the right which is greater than the current element. If there does not exist next greater of current element, 
then next greater element for current element is -1. For example, next greater of the last element is always -1. 
Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1).

#### Max Segment Intersections | [Solution](https://github.com/domferr/competitive-programming/tree/main/MaxSegmentIntersections)

Given an array arr[] consisting of N pairs of type {L, R}, each representing a segment on the X-axis, the task is to 
find the maximum number of intersections a segment has with other segments. Problem available also 
on [GeeksForGeeks](https://www.geeksforgeeks.org/maximum-number-of-intersections-possible-for-any-of-the-n-given-segments/).

#### Longest K Good Segment | [Solution](https://github.com/domferr/competitive-programming/tree/main/LongestKGoodSegment)

The array a with n integers is given. Let's call the sequence of one or more consecutive elements in a segment. 
Also let's call the segment k-good if it contains no more than k different values. Find any longest k-good segment. 
Problem available also on [CodeForces](https://codeforces.com/contest/616/problem/D?locale=en).

#### Nested Segments | [Solution](https://github.com/domferr/competitive-programming/tree/main/NestedSegments)

You are given n segments on a line. There are no ends of some segments that coincide. For each segment find the number 
of segments it contains. Problem available also on [CodeForces](https://codeforces.com/problemset/problem/652/D?locale=en).

#### Counting Inversions | [Solution](https://github.com/domferr/competitive-programming/tree/main/CountingInversions)

Given an array, compute the number of inversions. Inversions for an array indicates – how far (or close) the array is
from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in
the reverse order, the inversion count is the maximum. Formally speaking, two elements a[i] and a[j] form an inversion
if a[i] > a[j] and i < j. Problem available also on [GeeksForGeeks](https://www.geeksforgeeks.org/counting-inversions/).

#### Rod Cutting | [Solution](https://github.com/domferr/competitive-programming/tree/main/RodCutting)

Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces. Problem available also
on [GeeksForGeeks](https://www.geeksforgeeks.org/cutting-a-rod-dp-13/).

#### House Robber | [Solution](https://github.com/domferr/competitive-programming/tree/main/HouseRobber)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer 
array representing the amount of money of each house, return the maximum amount of money you can rob tonight without 
alerting the police. Problem available also on [LeetCode](https://leetcode.com/problems/house-robber/).

## Data structures

#### Binary Search Tree | [Source code](https://github.com/domferr/competitive-programming/tree/main/BinarySearchTree)

The tree is stored as an array. The siblings of a node are easily got by just computing some bit arithmetic.

#### Fenwick Tree (or Binary Indexed Tree) | [Source code](https://github.com/domferr/competitive-programming/tree/main/FenwickTree)

The tree is stored as an array. Each node knows its value and the positions of the right and left children in the
array.

#### Segment Tree | [Source code](https://github.com/domferr/competitive-programming/tree/main/SegmentTree)

The tree is stored as an array in the order of Euler tour traversal. It is memory efficient because only (2 * N) - 1 
nodes are stored, where N is the number of original elements.
