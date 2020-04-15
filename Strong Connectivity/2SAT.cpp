/*

Algorithm: 

Suppose given formula is 
    L = (x2 | !x1) & (!x1 | !x2) & (x1 | x3) & (!x2 | !x3) & (x1 | x4) 

In the graph, for each variable two nodes are present for example, for x1 there are two nodes x1 and !x1

1. For each pair (x1 | x2) add two edge !x1 -> x2 and !x2 to x1
2. After graph is complete then run Kosaraju's Algorithm to find SCC's 
3. If in a single SCC both x1 and !x1 exists then break
4. else form a Component Graph
5. Run topological sort in the graph
6. Assign values to variables in reverse topological sort order until all values are assigned so that each SCC returns true

*/