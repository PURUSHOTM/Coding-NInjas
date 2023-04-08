/*
Code : Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/

/*-----------------------------------------------------Solution--------------------------------------------------------------*/
#include <climits>
#include <iostream>

using namespace std;

long findMinimumVertex(long *distance, bool *visited, long v)
{
    long vertex = -1;
    for (long i = 0; i < v; i++)
    {
        if (!visited[i] && (vertex == -1 || distance[i] < distance[vertex]))
            vertex = i;
    }
    return vertex;
}

int main()
{
    // Write your code here
    long v, e;
    cin >> v >> e;
    long **edges = new long *[v];
    for (long i = 0; i < v; i++)
    {
        edges[i] = new long[v];
        for (long j = 0; j < v; j++)
            edges[i][j] = 0;
    }

    for (long i = 0; i < e; i++)
    {
        long start, end, weight;
        cin >> start >> end >> weight;
        edges[start][end] = weight;
        edges[end][start] = weight;
    }

    // Dijkstra's algorithm

    bool *visited = new bool[v];
    long *distance = new long[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (long i = 0; i < v; i++)
    {
        long vertex = findMinimumVertex(distance, visited, v);
        visited[vertex] = true;
        for (long j = 0; j < v; j++)
        {
            if (edges[vertex][j] && edges[vertex][j] < distance[j] && !visited[j] &&
                (distance[vertex] + edges[vertex][j]) < distance[j])
                distance[j] = distance[vertex] + edges[vertex][j];
        }
    }

    for (long i = 0; i < v; i++)
        cout << i << " " << distance[i] << "\n";

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete[] edges;
    delete[] distance;
    delete[] visited;
    return 0;
}