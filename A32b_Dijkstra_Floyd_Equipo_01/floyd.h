#ifndef FLOYD_H
#define FLOYD_H

#include <iostream>
#include <vector>

using namespace std;

constexpr long long FLOYD_INF = 1'000'000'000'000'000'000LL;

// Algoritmo de Floyd-Warshall:
// Tiempo: O(N^3), Espacio adicional y total: O(N^2)
inline void floydWarshall(int n, const vector<vector<long long>>& graph) {
    vector<vector<long long>> dist(n, vector<long long>(n, FLOYD_INF));
    
    // Inicialización de matriz de distancias
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            } else if (graph[i][j] != -1) {
                dist[i][j] = graph[i][j];
            }
        }
    }
    
    // Programación dinámica de Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != FLOYD_INF && dist[k][j] != FLOYD_INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    // Impresión de matriz resultante
    cout << "\nFloyd:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long val = (dist[i][j] == FLOYD_INF) ? -1 : dist[i][j];
            cout << val << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

#endif