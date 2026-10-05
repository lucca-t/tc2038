/*
 * Descripcion: Programa que resuelve un laberinto utilizando la tecnica de programacion de "backtracking".
 * Autores: Lucca Traslosheros Abascal A01713944
 *          Oscar Lopez Cardoso A01713355
 * Fecha: 30/08/2026.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Funcion que se llama recursivamente para encontrar todos los caminos posibles.
 * grid: El grid de M x N que indica 1 si se puede pasar y 0 si no.
 * solution: El grid M x N que indica 1 si la celda es parte del camino y 0 si no.
 * i, j: indices actuales en el grid.
 * solutions: Vector que almacena todas las soluciones validas encontradas.
 * Criterio de avance: Arriba, Abajo, Izquierda, Derecha.
 * Retorno: void
 * Complejidad de Tiempo: O(4^(M*N)) en el peor de los casos, ya que puede explorar hasta 4 direcciones por celda.
 * Complejidad de Espacio: O(M*N) debido a la memoria de la matriz solucion y la profundidad de la pila de recursion.
 */
void back_helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& solution, vector <vector<vector<int>>>& solutions) {
    // Checar si estamos fuera de los limites del grid
    if( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return;
    }
    // Checar si es una pared (0) o si ya visitamos esta celda en el camino actual (1)
    if ( grid[i][j] == 0 || solution[i][j] == 1) {
        return;
    }
    // Caso base: Solucion?
    if ( ((i == grid.size()-1) && (j == grid[0].size() - 1)) && grid[i][j] == 1) {
        solution[i][j] = 1;
        solutions.push_back(solution); // Guardar una copia de la solucion completada
        solution[i][j] = 0; // Desmarcar para permitir que otras rutas alcancen la meta
        return;
    }
    
    // Marcar la celda actual como visitada
    solution[i][j] = 1;
    
    // Explorar vecinos recursivamente siguiendo el criterio de avance
    back_helper(i-1, j, grid, solution, solutions); // Arriba
    back_helper(i+1, j, grid, solution, solutions); // Abajo
    back_helper(i, j-1, grid, solution, solutions); // Izquierda
    back_helper(i, j+1, grid, solution, solutions); // Derecha

    // Desmarcar la celda actual para el backtracking
    solution[i][j] = 0;
}

/*
 * Inicializa y llama a la funcion recursiva para resolver el laberinto.
 * grid: El grid de M x N que indica 1 si se puede pasar y 0 si no.
 * Retorno: Vector de matrices 2D conteniendo todas las soluciones.
 * Complejidad de Tiempo: O(4^(M*N)) 
 * Complejidad de Espacio: O(M*N) 
 */
vector< vector<vector <int>> > backtracking(vector<vector<int>> grid) {
    int M = grid.size();
    int N = grid[0].size();

    vector< vector<vector<int>> > solutions;
    vector<vector<int>> solution(M, vector<int>(N, 0));

    // Iniciar la exploracion desde el origen (0, 0)
    back_helper(0, 0, grid, solution, solutions);

    return solutions;
}

/*
 * Lee los datos, guarda todo en una matriz, imprime el laberinto inicial y busca soluciones.
 * Retorno: codigo 0 cuando el programa termina correctamente y 1 si hubo error en entrada.
 */
int main() {
    int M, N;
    
    // Validacion basica para lectura de enteros (opcional pero recomendada)
    if (!(cin >> M >> N)) {
        cout << "Error de entrada\n";
        return 1;
    }

    vector<vector<int>> grid(M, vector<int>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            char ch;
            cin >> ch;

            // Validar que la entrada sea solo '0' o '1'
            if (ch != '1' && ch != '0') {
                cout << "Error de entrada\n";
                return 1;
            }
            int x = ch - '0';
            grid[i][j] = x;        
        }
    }

    // Mostrar el laberinto inicial tal como lo pide la rubrica
    cout << "Laberinto inicial:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";        
        }
        cout << "\n";
    }
    cout << "\n";

    // Encontrar todas las soluciones
    vector< vector<vector<int>>> all_solutions = backtracking(grid);

    // Imprimir las soluciones
    if (all_solutions.size() > 0) {        
        cout << "Backtracking\n";
        for( int x = 0; x < all_solutions.size(); x++) {
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    cout << all_solutions[x][i][j] << " ";        
                }
                cout << "\n";
            }
            // Separador visual si hay más de una solucion
            if ( x < all_solutions.size() - 1) {
                cout << "\n";    
            }
        }
    } else {
        cout << "No hay solucion\n";
    }

    return 0;
}