// Given a set of cities and the distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.

// hamiltonian cycle -> find if there exists a tour that visits every city exactly once. Always exists when the graph is complete

// a complete graph is a simple undirected graph in which every pair of distinct vertices is connected by a unique edge.

// The problem is to find a hamoltonian cycle with minimum cost

// Brute-force/Naive solution -> Consider city 1 as the starting and ending point,Generate all (n-1)! Permutations of cities,Calculate the cost of every permutation and keep track of the minimum cost permutation,Return the permutation with minimum cost.  [TC -> O(n!)]

// Dynamic programming approach ->

// the problem is a known as an NP-Hard problem. There are approximate algorithms to solve the problem though. The approximate algorithms work only if the problem instance satisfies Triangle-Inequality.

// Triangle-Inequality: The least distant path to reach a vertex j from i is always to reach j directly from i, rather than through some other vertex k (or vertices), i.e., dis(i, j) is always less than or equal to dis(i, k) + dist(k, j).
