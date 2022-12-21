#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Graph {
    private:
    int newVertex;
    vector<int> *adjacent;
    void DFS(int vertex, bool traveled[],int node,int ar[]);
    void fillNode(int vertex, bool traveled[], stack<int> &Stack);
    

    public:
    Graph transpose();
    Graph(int newVertex);
    void print(int node,int arr[]);
    void SCC(int vertex, int w);
};

Graph::Graph(int aVertex){
    this->newVertex = aVertex;
    adjacent = new vector<int>[newVertex];
}

void Graph::DFS(int vertex, bool traveled[], int node, int arr[]){  
    traveled[vertex] = true;
    arr[vertex] = node;
   vector<int>::iterator i = adjacent[vertex].begin();
    for (i; i!= adjacent[vertex].end(); i++){
        if (traveled[*i] != true){
            DFS(*i, traveled, node, arr);
        } else{
            continue;
        }
    }
    return;
}

Graph Graph::transpose(){
    Graph g(newVertex);
    for (int vertex = 0; vertex < newVertex; vertex++){
        vector<int>::iterator i = adjacent[vertex].begin();
        for(i; i != adjacent[vertex].end(); i++){
            g.adjacent[*i].push_back(vertex);
        }
    }
    return g;
}

void Graph::SCC(int vertex, int w){
    if(vertex >= 0){
        adjacent[vertex].push_back(w);
    }
    return;
}

void Graph::fillNode(int vertex, bool traveled[], stack<int> &Stack){
    traveled[vertex] = true;
    vector<int>::iterator i = adjacent[vertex].begin();
    for(i; i != adjacent[vertex].end(); i++){
        if(traveled[*i] == false){
            fillNode(*i, traveled, Stack);
        }
    }
    Stack.push(vertex);
    return;
}

void Graph::print(int node,int arr[]){
    stack<int> vertecies;
    int minValue;
    bool *traveled = new bool[newVertex];

    for(int i = 0; i < newVertex; i++){
        traveled[i] = false;
    }

    for(int i = 0; i < newVertex; i++){
        if(traveled[i] == false){
            fillNode(i, traveled, vertecies);
        } else{
            continue;
        }
    }
    Graph gr = transpose();

    for(int i = 0; i < newVertex; i++){
        traveled[i] = false;
    }

    while (vertecies.empty() != true){
        int vertex = vertecies.top();
        vertecies.pop();
        if (traveled[vertex] != true){
            gr.DFS(vertex, traveled, vertex, arr);
            minValue = vertex;
            for(int i = 0; i < node; i++){
                if(arr[i] == vertex){
                    if(minValue > i){
                        minValue = i;
                    } else{
                        goto jump;
                    }
                }
            }
            jump:
            for(int i = 0; i < node; i++){
                if(*(arr + i) == vertex){
                    *(arr + i) = minValue;
                }
            }
        }
    }
    return;
}

int main(){
    int vertex;
    int edges;
    cin >> vertex;
    cin >> edges;
    int arr[vertex];
    Graph graphObject(vertex);

    if(vertex < 1 || edges < 1){
        exit(1);
        //return 0;
    }


    for(int i = 0; i < edges; i++){
        int u;
        int w;
        cin >> u >> w;
        graphObject.SCC(u,w);
    }

    for(int i = 0; i < vertex; i++){
        *(arr + i) = vertex + 2;
    }

    graphObject.print(vertex, arr);

    for(int i = 0; i < vertex; i++){
        cout << *(arr + i) << endl;
    }

    return 0;
}