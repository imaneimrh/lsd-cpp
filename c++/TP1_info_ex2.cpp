#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

/* DFS (depth-first-search) visits all vertices of a connected component when it is called on a vertex of that connected component.

If we iterate over all vertices, in case we find an unvisited node, it is because it was not visited by DFS done on vertices so far.
That means it is not connected to any previous nodes that were visited, it was not part of prior components.

Hence this node is part of a new component. So, we need to increment the component count and visit all the nodes part of the component using DFS. */


vector<int> G[MAX]; //I use an adjacency list, because it requires less space storage, but the input will look like a matrix.

void DFS(int v, int visited[], vector<int> G[]){
    visited[v] = 1;
    for(int u: G[v]){
        if(!visited[u])
            DFS(u, visited, G);
        }
}

int main(){
    int n; //number of nodes
    int count=0;
    cout<<"please enter the number of NODES in the graph: ";
    cin>>n;
    cout<<endl<<"~~~please enter the adjacency matrix~~~"<<endl;
    int x,j,i;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>x;
            if(x==1){
                G[i].push_back(j);
            }
            else
                continue;
        }
    }

    int visited[n]={0};            // step 1: First, mark all vertices as unvisited.
    for (int v =0; v < n; v++) {  //step 2: iterating over all the vertices
        if (visited[v] ==0) {    //If a vertex is not visited
            DFS(v, visited, G); //perform DFS on that vertex 
            count +=1;         //and increment the count by 1.
        }
    } // After iterating over all vertices, the value of count will be the number of connected components in the graph.
    cout<<"The number of connected components in a graph is: "<<count; 
    

}



    