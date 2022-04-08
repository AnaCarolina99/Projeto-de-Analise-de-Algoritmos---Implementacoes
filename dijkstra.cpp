// Algoritmo de Dijkstra para definir caminho mais curto 
#include <bits/stdc++.h> 
#include <math.h>

using namespace std; 
#define INFINITO 9999
#define V 5         // numero de vertices

void print(int dist[]) { 
   printf("Vertice \t Menor caminho \n"); 
   for (int i = 0; i < V; i++) 
      printf("\t %d \t\t\t %d\n", i, dist[i]); 
} 

// encontra o vértice com a menor distancia 
int distMin(int dist[], bool visitados[]) { 
   int min = INFINITO, min_indice; 
   for (int ver = 0; ver < V; ver++) {
      if (visitados[ver] == false && dist[ver] <= min) {
         min = dist[ver];
         min_indice = ver; 
      }
   }
   return min_indice; 
} 


void dijkstra(int grafo[V][V], int vertice) { 
   int dist[V];
   bool visitados[V]; // controle de vertices ja visitados

	// todas as distancias sao inicializadas como infinito e a visitados como falso
   for (int i = 0; i < V; i++){ 
      dist[i] = INFINITO;
      visitados[i] = false; 
   }

   //o vertice é inicializado como 0 para ser o primeiro 
   dist[vertice] = 0; 

	// acha o menor caminho
   for (int cont = 0; cont < V - 1; cont++) { 
   	// pega o vertice de menor distancia entre os nao selecionados 
      int vert = distMin(dist, visitados); 
      int dir;
   
   	// marca o vertice como visitado
      visitados[vert] = true; 
   
   	// atualiza a distancia dos vertices adjacentes
      for (dir = 0; dir < V; dir++) 
         if (!visitados[dir] && grafo[vert][dir] && dist[vert] != INFINITO && dist[vert] + grafo[vert][dir] < dist[dir]) 
            dist[dir] = dist[vert] + grafo[vert][dir]; 
   } 
   print(dist); 

} 

int main() { 
   clock_t start, end; 
   start = clock(); 
   int grafo[V][V] = {{0,1,0,3,10},
                      {1,0,5,0,0},
                      {0,5,0,2,1},
                      {3,0,2,0,6},
                      {10,0,1,6,0}
      
      }; 
   dijkstra(grafo, 0);
   end = clock();  
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
   cout << "Tempo gasto : " << fixed  << time_taken << setprecision(5); 
   cout << " segundos " << endl; 
   return 0;
} 
