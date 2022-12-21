#include <iostream>

using namespace std;
int vertex;
int edge;

void bfGraph(int vertex, int edges){
	
	int s = 0;
	int d = 0;
	int w = 0;
  bool printFlag = true;
	int distance[vertex];
	int **graph = new int *[3];

	for(int i = 0; i < vertex; i++){
		*(graph + i) = new int[edges];
    
		for(int j = 0; j < vertex; j++){
			*(*(graph + i) + j) = 0;
		}
	}

	for(int i = 0; i < edges; i++){
		cin >> s;
		cin >> d;
		cin >> w;

		graph[0][i] = s;
		graph[1][i] = d;
		graph[2][i] = w;
	}
	
	for(int i = 0; i < vertex; i++){

		*(distance + i) = 2147483647;

	}

	*(distance) = 0;

	for(int i = 1; i <= vertex-1; i++){
		for(int j = 0; j < edges; j++){

			int u = graph[0][j];
			int v = graph[1][j];
			int w = graph[2][j];

      if(*(distance + u) != 2147483647){
        if(*(distance + u) + w < *(distance + v)){
          distance[v] = distance[u] + w;
        }
      }
		}
	}
  
	for(int i = 0; i < edges; i++){
	
		int u = graph[0][i];
		int v = graph[1][i];
		int w = graph[2][i];

		if(distance[u] != 2147483647 && distance[u] + w < distance[v]){

			cout << "FALSE" << endl;
			printFlag = 0;

		} else{
    }
	}



	if(printFlag == true){
		cout << "TRUE" << endl;
    } else{
    goto jump;
    }
  
		for(int i = 0; i < vertex; i++){

			if(distance[i] == 2147483647){

				cout << "INFINITY" << endl;

			}else{
	
				cout << distance[i] << endl;

			}
		}
  
  jump:
  return;
}







int main(){

	cin >> vertex;
	cin >> edge;

	bfGraph(vertex, edge);
return 0;
}