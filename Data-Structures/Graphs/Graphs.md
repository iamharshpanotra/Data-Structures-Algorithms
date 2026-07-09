# Graph Data Structure (C++)

> **Document Version:** 1.0  
> **Category:** Data Structures & Algorithms  
> **Language:** C++  
> **Difficulty:** Intermediate  
> **Author:** Engineering Documentation  
> **Last Updated:** July 2026

---

# Table of Contents

1. Introduction
2. What is a Graph?
3. Terminology
4. Types of Graphs
5. Graph Representation
6. Adjacency Matrix
7. Adjacency List
8. Weighted Graph Representation
9. Graph Traversal
10. Breadth First Search (BFS)
11. Depth First Search (DFS)
12. Cycle Detection
13. Topological Sorting
14. Shortest Path Algorithms
15. Minimum Spanning Tree
16. Graph Complexity Analysis
17. STL Implementation
18. Common Interview Problems
19. Best Practices
20. Summary

---

# 1. Introduction

A **Graph** is a non-linear data structure consisting of **vertices (nodes)** connected by **edges**.

Unlike Trees, graphs:

- Can contain cycles
- May not have a root
- Can have multiple paths
- Can be directed or undirected
- Can even be disconnected

Graphs are one of the most important data structures used in modern software engineering.

---

# 2. What is a Graph?

A graph is represented as:

```

G = (V, E)

```

Where

- **V** = Set of Vertices (Nodes)
- **E** = Set of Edges (Connections)

Example

```

A ----- B
| |
| |
C ----- D

```

Vertices

```

A B C D

```

Edges

```

(A,B)
(A,C)
(B,D)
(C,D)

```

---

# 3. Graph Terminology

## Vertex

A node in the graph.

```

A

```

---

## Edge

Connection between two vertices.

```

A ------ B

```

---

## Degree

Number of edges connected to a vertex.

Example

```

A ---- B
|
|
C

```

Degree of A = 2

---

## Path

Sequence of connected vertices.

```

A → B → D

```

---

## Cycle

A path that starts and ends at the same vertex.

```

A
/ \
B---C

```

---

## Connected Graph

Every vertex is reachable.

---

## Disconnected Graph

Some vertices cannot be reached.

---

## Weighted Edge

Each edge stores a cost.

```

A --5-- B

```

---

# 4. Types of Graphs

## Undirected Graph

```

A ----- B

```

Connection exists both ways.

---

## Directed Graph (Digraph)

```

A -----> B

```

Only one direction.

---

## Weighted Graph

```

A --10-- B

```

Edge has weight.

---

## Unweighted Graph

Every edge has equal weight.

---

## Cyclic Graph

Contains at least one cycle.

---

## Acyclic Graph

Contains no cycles.

---

## Connected Graph

Every node is reachable.

---

## Disconnected Graph

Some nodes are isolated.

---

## Complete Graph

Every vertex connects to every other vertex.

---

## Bipartite Graph

Vertices divided into two independent sets.

---

## DAG (Directed Acyclic Graph)

Directed graph with no cycles.

Used in

- Scheduling
- Dependency Resolution
- Build Systems

---

# 5. Graph Representation

There are two standard representations.

| Representation | Space |
|---------------|--------|
| Adjacency Matrix | O(V²) |
| Adjacency List | O(V+E) |

---

# 6. Adjacency Matrix

Stores graph inside a 2D matrix.

Example

```

0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

```

Meaning

```

0 → 1
0 → 2
1 → 3
2 → 3

```

### Advantages

- Easy edge lookup
- Simple implementation

### Disadvantages

- High memory usage
- Not suitable for sparse graphs

Space

```

O(V²)

```

---

# 7. Adjacency List

Stores neighbors of every vertex.

Example

```

0 -> 1 2
1 -> 0 3
2 -> 0 3
3 -> 1 2

```

### Advantages

- Memory efficient
- Fast traversal

### Disadvantages

- Edge lookup is slower

Space

```

O(V + E)

```

---

# 8. Weighted Graph Representation

```

0 -> (1,4) (2,8)

1 -> (2,5)

2 -> (3,7)

```

Each pair contains

```

(Node, Weight)

```

---

# 9. Graph Traversal

Traversal means visiting every vertex.

Two methods

- BFS
- DFS

---

# 10. Breadth First Search (BFS)

Visits nodes level by level.

Uses

- Queue
- Visited Array

Example

```

A

/ \

B C

/ \

D E

```

Traversal

```

A B C D E

```

### Algorithm

1. Push source into queue
2. Mark visited
3. Pop node
4. Visit neighbors
5. Repeat

### Complexity

Time

```

O(V + E)

```

Space

```

O(V)

```

### C++ Implementation

```cpp
void bfs(int start, vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : graph[node])
        {
            if(!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
```

---

# 11. Depth First Search (DFS)

Visits as deep as possible before backtracking.

Uses

- Recursion
- Stack

Traversal

```

A B D E C

```

### Complexity

Time

```

O(V + E)

```

Space

```

O(V)

```

### Recursive DFS

```cpp
void dfs(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    for(int neighbor : graph[node])
    {
        if(!visited[neighbor])
            dfs(neighbor, graph, visited);
    }
}
```

---

# 12. Cycle Detection

## Undirected Graph

Methods

- DFS
- BFS
- Union Find

---

## Directed Graph

Methods

- DFS + Recursion Stack
- Topological Sort

---

# 13. Topological Sorting

Applicable only for

- Directed Graph
- Acyclic Graph (DAG)

Produces a valid dependency ordering.

Example

```

Coding

↓

Compile

↓

Test

↓

Deploy

```

Algorithms

- DFS
- Kahn's Algorithm (BFS)

Complexity

```

O(V + E)

```

---

# 14. Shortest Path Algorithms

## BFS

Works for

- Unweighted Graph

Complexity

```

O(V + E)

```

---

## Dijkstra

Works for

- Positive Weights

Complexity

```

O((V + E) logV)

```

Uses

- Priority Queue

---

## Bellman Ford

Supports

- Negative Edges

Complexity

```

O(VE)

```

---

## Floyd Warshall

All Pair Shortest Path

Complexity

```

O(V³)

```

---

# 15. Minimum Spanning Tree

Connects every vertex with minimum total weight.

Algorithms

## Prim's Algorithm

Uses

- Min Heap

Complexity

```

O(E logV)

```

---

## Kruskal's Algorithm

Uses

- Sorting
- Union Find

Complexity

```

O(E logE)

```

---

# 16. Graph Complexity Analysis

| Operation | Adjacency List | Adjacency Matrix |
|------------|---------------|------------------|
| Add Edge | O(1) | O(1) |
| Remove Edge | O(V) | O(1) |
| Search Edge | O(V) | O(1) |
| BFS | O(V+E) | O(V²) |
| DFS | O(V+E) | O(V²) |
| Space | O(V+E) | O(V²) |

---

# 17. STL Implementation

## Graph Declaration

```cpp
vector<vector<int>> graph(n);
```

---

## Add Edge

### Undirected

```cpp
graph[u].push_back(v);
graph[v].push_back(u);
```

---

### Directed

```cpp
graph[u].push_back(v);
```

---

## Weighted Graph

```cpp
vector<vector<pair<int,int>>> graph(n);
```

Add Edge

```cpp
graph[u].push_back({v, weight});
```

---

# 18. Common Interview Problems

## Traversal

- BFS
- DFS

---

## Cycle Detection

- Directed
- Undirected

---

## Connected Components

---

## Number of Islands

---

## Clone Graph

---

## Course Schedule

---

## Rotten Oranges

---

## Word Ladder

---

## Network Delay Time

---

## Cheapest Flights

---

## Alien Dictionary

---

## Graph Coloring

---

## Minimum Spanning Tree

---

## Shortest Path

---

## Strongly Connected Components

---

## Bridges & Articulation Points

---

# 19. Best Practices

- Prefer **Adjacency List** for sparse graphs.
- Use **Adjacency Matrix** only when graph density is high.
- Maintain a visited array during traversal.
- Avoid revisiting nodes.
- Use BFS for minimum distance in unweighted graphs.
- Use Dijkstra for positive weighted graphs.
- Use Union-Find for dynamic connectivity problems.
- Choose iterative DFS when recursion depth may exceed stack limits.

---

# 20. Summary

| Concept | Description |
|----------|-------------|
| Graph | Collection of vertices and edges |
| Vertex | Node |
| Edge | Connection |
| BFS | Level Order Traversal |
| DFS | Depth First Traversal |
| Adjacency Matrix | O(V²) Memory |
| Adjacency List | O(V+E) Memory |
| Dijkstra | Positive Weight Shortest Path |
| Bellman Ford | Negative Weight Shortest Path |
| Floyd Warshall | All Pair Shortest Path |
| Prim | MST |
| Kruskal | MST |
| Topological Sort | DAG Ordering |
| Union Find | Connectivity Problems |

---

# Key Takeaways

- Graphs model complex real-world relationships and networks.
- **Adjacency List** is the preferred representation for most applications due to its space efficiency.
- **BFS** and **DFS** are the foundation for almost every graph algorithm.
- Mastering **Shortest Path**, **Minimum Spanning Tree**, **Cycle Detection**, and **Topological Sorting** is essential for technical interviews and real-world software development.
- Graph algorithms are extensively used in routing systems, social networks, recommendation engines, dependency management, distributed systems, AI, and compiler design.

---
````
