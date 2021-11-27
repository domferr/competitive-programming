# Competitive Programming and Contests

Each problem comes with a solution written in C++ and a test suite. Testing is done by using 
the [GoogleTest](https://github.com/google/googletest) framework. The following is the list 
of all the problems together with a link to my solution.

## Problems

#### Trapping Rain Water | [Solution](https://github.com/domferr/competitive-programming/tree/main/TrappingRainWater)
  
Given an array of N non-negative integers representing the height of blocks. If width of each block is 1, compute 
how much water can be trapped between the blocks during the rainy season. 
Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/trapping-rain-water/0).

#### Sliding Window Maximum | [Solution](https://github.com/domferr/competitive-programming/tree/main/SlidingWindowMaximum)

Given an array of N elements and integer K, find the maximum for each and every contiguous subarray (window) of 
size K. Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0).

#### Missing Number in Array | [Solution](https://github.com/domferr/competitive-programming/tree/main/MissingNumber)

Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing
element. Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1).

#### Kadane's Algorithm | [Solution](https://github.com/domferr/competitive-programming/tree/main/KadanesAlgorithm)

Given an array of N integers. Find the contiguous sub-array (containing at least one number) which has the maximum 
sum and return its sum. Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1).

#### Towers | [Solution](https://github.com/domferr/competitive-programming/tree/main/Towers)

Little Vasya has received a young builder’s kit. The kit consists of several wooden bars, the lengths of all of them 
are known. The bars can be put one on the top of the other if their lengths are the same. Vasya wants to construct the 
minimal number of towers from the bars. Help Vasya to use the bars in the best way possible. Problem available 
also on [Codeforces](http://codeforces.com/problemset/problem/37/A?locale=en).

#### Next Larger Element | [Solution](https://github.com/domferr/competitive-programming/tree/main/NextLargerElement)

Given an array of size N having distinct elements, the task is to find the next greater element for each element 
of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest 
element on the right which is greater than the current element. If there does not exist next greater of current element, 
then next greater element for current element is -1. For example, next greater of the last element is always -1. 
Problem available also on [GeeksForGeeks](http://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1).

#### Max Segment Intersections | [Solution](https://github.com/domferr/competitive-programming/tree/main/MaxSegmentIntersections)

Given an array consisting of N pairs of type {L, R}, each representing a segment on the X-axis, the task is to 
find the maximum number of intersections a segment has with other segments. Problem available also 
on [GeeksForGeeks](https://www.geeksforgeeks.org/maximum-number-of-intersections-possible-for-any-of-the-n-given-segments/).

#### Longest K Good Segment | [Solution](https://github.com/domferr/competitive-programming/tree/main/LongestKGoodSegment)

The array a with n integers is given. Let's call the sequence of one or more consecutive elements in a segment. 
Also let's call the segment k-good if it contains no more than k different values. Find any longest k-good segment. 
Problem available also on [Codeforces](https://codeforces.com/contest/616/problem/D?locale=en).

#### Maximum Path Sum | [Solution](https://github.com/domferr/competitive-programming/tree/main/MaximumPathSum)

Given a binary tree in which each node element contains a number. Find the maximum possible path sum from one leaf node
to another leaf node. Problem available also on [GeekForGeeks](http://practice.geeksforgeeks.org/problems/maximum-path-sum/1).

#### Nested Segments | [Solution](https://github.com/domferr/competitive-programming/tree/main/NestedSegments)

You are given n segments on a line. There are no ends of some segments that coincide. For each segment find the number 
of segments it contains. Problem available also on [Codeforces](https://codeforces.com/problemset/problem/652/D?locale=en).

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

#### Minimum Cost Path | [Solution](https://github.com/domferr/competitive-programming/tree/main/MinimumCostPath)

We are given a matrix M of n * m integers. The goal is to find the minimum cost path to move from the top-left 
corner to the bottom-right corner by moving only down or to right.

#### 0-1 Knapsack | [Solution](https://github.com/domferr/competitive-programming/tree/main/01Knapsack)

You are packing for a vacation on the sea side and you are going to carry only one bag with capacity
S (1 <= S <= 2000). You also have N (1<= N <= 2000) items that you might want to take with you to the sea side.
Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given
its size and its value. You want to maximize the total value of all the items you are going to bring. What is this
maximum total value? Problem available also on [Sphere Online Judge](https://www.spoj.com/problems/KNAPSACK/).

## Data structures

#### Binary Search Tree | [Source code](https://github.com/domferr/competitive-programming/tree/main/BinarySearchTree)

The tree is stored as an array. The siblings of a node are easily got by just computing some bit arithmetic.

#### Fenwick Tree (or Binary Indexed Tree) | [Source code](https://github.com/domferr/competitive-programming/tree/main/FenwickTree)

The tree is stored as an array. Each node knows its value and the positions of the right and left children in the
array.

#### Segment Tree | [Source code](https://github.com/domferr/competitive-programming/tree/main/SegmentTree)

The tree is stored as an array in the order of Euler tour traversal. It is memory efficient because only (2 * N) - 1 
nodes are stored, where N is the number of original elements.

## Other problems

#### Tiling Problem | [Source code](https://github.com/domferr/competitive-programming/tree/main/TilingProblem)

Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1
tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. Problem
available also on [GeeksForGeeks](https://www.geeksforgeeks.org/tiling-problem/).

#### Gold Mine Problem | [Source code](https://github.com/domferr/competitive-programming/tree/main/GoldMineProblem)

Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold 
in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) 
that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down 
towards the right. Find out maximum amount of gold he can collect. Problem available also 
on [GeeksForGeeks](https://www.geeksforgeeks.org/gold-mine-problem/).