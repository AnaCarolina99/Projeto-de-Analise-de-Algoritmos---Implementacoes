#include <bits/stdc++.h> 
using namespace std; 
#define INFINITO 9999

// estrutura da aresta de cada grafo
struct Aresta { 
   int vertice, direcao, peso; 
}; 

// estrutura do grafo
struct Grafo { 
   int V, A; // V=vertices, A=arestas
   struct Aresta* aresta; 
}; 

// cria o grafo
struct Grafo* criaGrafo(int V, int A) { 
   struct Grafo* grafo = new Grafo; 
   grafo->V = V; 
   grafo->A = A; 
   grafo->aresta = new Aresta[grafo->A]; 
   return grafo; 
}


void print(int dist[], int n){ 
   printf("Vertice \t Menor caminho \n");
   for (int i = 0; i < n; ++i) 
      printf("\t %d \t\t\t %d\n", i, dist[i]); 
} 
//acha a menor distancia e também determina se possui ciclo negativo ou nao
void BellmanFord(struct Grafo* grafo, int vertice) { 
   int V = grafo->V; 
   int A = grafo->A; 
   int dist[V]; 

// inicializando as distancias entre as arestas da vertice 0 como 0 e as outras como infinito 
   for (int i = 0; i < V; i++) 
      dist[i] = INFINITO; 
   dist[vertice] = 0; 

//relaxamento v-1 vezes 
   for (int i = 1; i <= V - 1; i++) { 
      for (int j = 0; j < A; j++) { 
         int ver = grafo->aresta[j].vertice; 
         int dir = grafo->aresta[j].direcao; 
         int peso = grafo->aresta[j].peso; 
         if (dist[ver] != INFINITO && dist[ver] + peso < dist[dir]) 
            dist[dir] = dist[ver] + peso; 
      } 
   } 

	//checa se possui ciclo negativo 
   for (int i = 0; i < A; i++) { 
      int ver = grafo->aresta[i].vertice; 
      int dir = grafo->aresta[i].direcao; 
      int peso = grafo->aresta[i].peso;  
      if (dist[ver] != INFINITO && dist[ver] + peso < dist[dir]) { 
         printf("O grafo possui ciclo negativo"); 
         return; // se tiver ciclo negativo nao retorna nada
      } 
   } 
   print(dist, V); 
   return; 
} 

int main() { 
   clock_t start, end; 
   start = clock(); 

   int V = 5; //vertices
   int A = 8; //arestas 
   struct Grafo* grafo = criaGrafo(V, A); 

   grafo->aresta[0].vertice = 0; 
   grafo->aresta[0].direcao = 1; 
   grafo->aresta[0].peso = -1; 

   grafo->aresta[1].vertice = 0; 
   grafo->aresta[1].direcao = 2; 
   grafo->aresta[1].peso = -4; 

   grafo->aresta[2].vertice = 1; 
   grafo->aresta[2].direcao = 2; 
   grafo->aresta[2].peso = -3; 

   grafo->aresta[3].vertice = 1; 
   grafo->aresta[3].direcao = 3; 
   grafo->aresta[3].peso = -2; 

   grafo->aresta[4].vertice = 1; 
   grafo->aresta[4].direcao = 4; 
   grafo->aresta[4].peso = -2; 

   grafo->aresta[5].vertice = 3; 
   grafo->aresta[5].direcao = 2; 
   grafo->aresta[5].peso = -5; 

   grafo->aresta[6].vertice = 3; 
   grafo->aresta[6].direcao = 1; 
   grafo->aresta[6].peso = -1; 

   grafo->aresta[7].vertice = 4; 
   grafo->aresta[7].direcao = 3; 
   grafo->aresta[7].peso = -3;



   BellmanFord(grafo, 0); 

   printf("\n"); 
   end = clock();  
   double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
   cout << "Tempo gasto : " << fixed  << time_taken << setprecision(5); 
   cout << " segundos " << endl; 

   return 0; 
} 
