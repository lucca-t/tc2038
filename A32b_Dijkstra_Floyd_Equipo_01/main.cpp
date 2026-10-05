#include <iostream>
#include <vector>
#include "dijkstra.h"
#include "floyd.h"

using namespace std;

// Algoritmo de Dijkstra:
// Tiempo: O(N^3 log N) [o O(N^3) sobre matriz de adyacencia]
// Espacio adicional: O(N), espacio total con la matriz: O(N^2)

// Algoritmo de Floyd-Warshall:
// Tiempo: O(N^3), Espacio adicional y total: O(N^2)
int main() {
    // Optimización de entrada/salida
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<vector<long long>> graph(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    
    dijkstraAllPairs(n, graph);
    floydWarshall(n, graph);
    
    return 0;
}