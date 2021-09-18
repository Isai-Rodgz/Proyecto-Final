#include <iostream>
#include <limits.h>
using namespace std;

// Número de vertices en el gráfico relacionado. 
#define NumberOfVertices 7

// Función para encontrar el vertice de menor distancia desde el grupo de vertices aun no incluidos en el arbol de menor magnitud. 
int minimumshortestDistanceance(int shortestDistance[], bool vertexSet[])
{

	// Inicializamos (min value)
	int min = INT_MAX, min_index;

	for (int v = 0; v < NumberOfVertices; v++)
		if (vertexSet[v] == false && shortestDistance[v] <= min)
			min = shortestDistance[v], min_index = v;

	return min_index;
}

// Una función para imprimir la matriz de distancia construida.
void printVal(int shortestDistance[])
{
	for (int i = 0; i < NumberOfVertices; i++)
		cout << "Vertice: " << i << " -> Distancia desde el vertice inicial: " << shortestDistance[i] << endl << endl;
}

// Función que implementa el algoritmo de ruta más corta de fuente única para una relación del gráfico usando representación de matriz de adyacencia

void algorithm(int relatedGraph[NumberOfVertices][NumberOfVertices], int source)
{
	int shortestDistance[NumberOfVertices]; // La matriz de salida. shortestDistance[i] mantendrá la distancia más corta desde la fuente hasta i

	bool vertexSet[NumberOfVertices]; // El vertexSet[i] será verdadero si el vertice i es incluido en el camino mas corto desde la fuente hasta que i es finalizado.

	// Inicializamos todas las distancias como infinitas y colocamos stpSet[] como falso.
	for (int i = 0; i < NumberOfVertices; i++)
		shortestDistance[i] = INT_MAX, vertexSet[i] = false;

	// La distancia del vértice de la fuente desde sí mismo es siempre 0
	shortestDistance[source] = 0;

	// Encuentra el camino más corto para todos los vertices
	for (int count = 0; count < NumberOfVertices - 1; count++) {
    
    // Elija el vértice de distancia mínima del conjunto de vértices no aún procesado. u siempre es igual a la fuente en la primera iteración.
		int u = minimumshortestDistanceance(shortestDistance, vertexSet);

		// Marca el vértice elegido como procesado
		vertexSet[u] = true;

		// Actualizar los valores de shortestDistance de los vertices adyacentes al vertice elegido.
		for (int v = 0; v < NumberOfVertices; v++)

      // Actualice shortestDistance[v] solo si no está en vertexSet, hay un borde de u a v, y el peso total de la ruta desde la fuente hasta v a través de u es menor que el valor actual de shortestDistance [v]
			if (!vertexSet[v] && relatedGraph[u][v] && shortestDistance[u] != INT_MAX && shortestDistance[u] + relatedGraph[u][v] < shortestDistance[v])
				shortestDistance[v] = shortestDistance[u] + relatedGraph[u][v];
	}

	// Imprimos el arreglo de matriz construida.
	printVal(shortestDistance);
}

int main() {

	int relatedGraph[NumberOfVertices][NumberOfVertices] = { 
    { 0, 4, 3, 0, 0, 0, 0 },    // a
		{ 4, 0, 0, 0, 12, 5, 0 },   // b
		{ 3, 0, 0, 7, 10, 0, 0 },   // c
		{ 0, 0, 7, 0, 2, 0, 0},    // d
		{ 0, 12, 10, 2, 0, 0, 5 },  // e
		{ 0, 5, 0, 0, 0, 0, 16 },  // f
		{ 0, 0, 0, 0, 5, 16, 0 }    // z
  };

	algorithm(relatedGraph, 0);

	return 0;
}
