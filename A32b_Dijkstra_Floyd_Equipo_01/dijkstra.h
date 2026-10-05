/*
 * Descripcion: Programa que implementa Dijkstra usando un priority queue
 * Autores: Lucca Traslosheros Abascal A01713944
 *          Oscar Lopez Cardoso A01713355
 * Fecha: 04/10/2026.
 */
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr long long DIJKSTRA_INF = 1'000'000'000'000'000'000LL;

// Algoritmo de Dijkstra:
// Tiempo: O(N^3 log N) [o O(N^3) sobre matriz de adyacencia]
// Espacio adicional: O(N), espacio total con la matriz: O(N^2)
inline void dijkstraAllPairs(int n, const vector<vector<long long>> &graph) {
  cout << "Dijkstra:\n";
  for (int src = 0; src < n; ++src) {
    vector<long long> dist(n, DIJKSTRA_INF);
    dist[src] = 0;

    // Min-heap de pares (distancia_acumulada, nodo_actual)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    pq.push({0, src});

    while (!pq.empty()) {
      pair<long long, int> current = pq.top();
      pq.pop();

      long long d = current.first;
      int u = current.second;

      if (d > dist[u])
        continue;

      for (int v = 0; v < n; ++v) {
        if (graph[u][v] != -1) { // Existe arista de u a v
          long long weight = graph[u][v];
          if (dist[u] + weight < dist[v]) {
            dist[v] = dist[u] + weight;
            pq.push({dist[v], v});
          }
        }
      }
    }

    // Se omite la distancia del nodo hacia sí mismo, como en el ejemplo
    // solicitado.
    for (int dst = 0; dst < n; ++dst) {
      if (src != dst) {
        long long val = (dist[dst] == DIJKSTRA_INF) ? -1 : dist[dst];
        cout << "node " << (src + 1) << " to node " << (dst + 1) << ":  " << val
             << "\n";
      }
    }
  }
}

#endif