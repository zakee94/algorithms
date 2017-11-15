# Algorithms
Codes of the (common and not-so-common) algorithms used in computer science in C/C++. This is an ongoing project and there are many more to come.

Most of the algorithms are implemented in more than one way, using different data-structures and by using different approaches catering both to the naive and the advanced users.

## How robust are these codes ?
The codes available have been extensivley tested and debugged with large number of testcases varying from small to really big input sizes (to the order of 10^7). The codes are specially built to handle large number of data with efficiency.

Users are welcome to test for themselves using inbuilt test-case generators provided with some of them (ex: [quick-sort-test-case-generator](https://github.com/zakee94/algorithms/blob/master/sorting/quick-sort/quick-sort-tcgen.cpp)).

Even after all these there is always a chance for error/improvement. Users are welcome to provide feedback and comment regarding these.

## How to use them ?
Users should set-up an environment which supports C/C++ like GNU or IDEs which support C/C++. You can simply compile them and run the executable.

An example is given below for linux environment, open a terminal in the directory in which the code is present and execute the following commands:
```
// For C codes:
gcc <name of file>
./a.out

// For C++ codes:
g++ <name of file>
./a.out
```
All codes have predefined input already available in main(), however these can be replaced by external test-cases. Users are welcome to use the [testing-debug-template](https://github.com/zakee94/algorithms/tree/master/testing/debug-template) to help read input from an external file / write input to an external file.

## Contents
List of algorithms (in no specific order) present in the project. Please note that this is only a tentaive list and many more are yet to come.
1. [Merge Sort (using Hoare-partitioning)](https://github.com/zakee94/algorithms/blob/master/sorting/merge-sort/merge-sort-1.c)
2. [Merge Sort (using Lomuto-partitioning)](https://github.com/zakee94/algorithms/blob/master/sorting/merge-sort/merge-sort-2.c)
3. [Quick Sort (using Hoare-partitioning)](https://github.com/zakee94/algorithms/blob/master/sorting/quick-sort/quick-sort-1.c)
4. [Quick Sort (using Lomuto-partitioning)](https://github.com/zakee94/algorithms/blob/master/sorting/quick-sort/quick-sort-2.cpp)
5. [Fisher Yates Shuffling](https://github.com/zakee94/algorithms/tree/master/others/fisher-yates-shuffling)
6. [i-th Order Statistic (both randomized and deterministic)](https://github.com/zakee94/algorithms/tree/master/others/i-th-order-statistic)
7. [Dijkstra's Shortest Path (2 variants)](https://github.com/zakee94/algorithms/tree/master/greedy/dijkstra-shortest-path)
8. [Prim's MST](https://github.com/zakee94/algorithms/tree/master/greedy/prims-mst/alternative-2)
9. [Prim's MST using Heap](https://github.com/zakee94/algorithms/tree/master/greedy/prims-mst/alternative-1)
10. [DFS & BFS in a Graph](https://github.com/zakee94/algorithms/tree/master/graphs/traversal)
11. [Hashing](https://github.com/zakee94/algorithms/blob/master/hashing/hash.cpp)
12. [Krager's Minimum Cut](https://github.com/zakee94/algorithms/tree/master/graphs/others/krager-min-cut)
13. [Computing Components in a Graph](https://github.com/zakee94/algorithms/tree/master/graphs/computing-components/components-bfs-undirected)
14. [Kosaraju's Strongly Connected Components](https://github.com/zakee94/algorithms/tree/master/graphs/computing-components/kosarajus-scc-directed)
15. [Inversion of an Array](https://github.com/zakee94/algorithms/tree/master/divide-n-conquer/array-inversion)
16. [Finding Closest Pair in 1 Dimension](https://github.com/zakee94/algorithms/blob/master/divide-n-conquer/closest-pair/closest-pair-1D.c)
17. [Finding Closest Pair in 2 Dimension (2 variants)](https://github.com/zakee94/algorithms/tree/master/divide-n-conquer/closest-pair)
18. [Max & Min Heap](https://github.com/zakee94/algorithms/tree/master/binary-heaps)
19. [Karatsuba-Multiplication](https://github.com/zakee94/algorithms/tree/master/divide-n-conquer/karatsuba-multiplication)
20. [Various representation of graphs](https://github.com/zakee94/algorithms/tree/master/graphs/representation/)

## Contributing
Anyone can contribute to this project as much as possible using any language of their choice. Do give proper comments in your code and please maintain the coding style mentioned [here](http://www.geeksforgeeks.org/contribute/article-writing-style/).

Let's keep expanding this list of algorithms !

## Authors
* [zakee94](https://github.com/zakee94/)

## License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/zakee94/algorithms/blob/master/LICENSE) file for details
