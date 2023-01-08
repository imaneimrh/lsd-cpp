#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
/* 
a BFS starts at some arbitrary node of a graph and we explores the neighbour
nodes first, before moving to next level neighbours

~~Its rule : When we are selecting a vertex for exploration 
we must visit all its adjacent vertices, then only, we can go to the other vertex for exploration

The BFS algorithm uses a Queue data structure to track which node to visit next.
Upon reaching a new node the algorithm adds it to the queue to visist it later.

             Dequeue  <---  [*|*|*|*|*|*|*|*]  <----[*] Enqueue

We will be able to use it in order to find the shortest path from a source key to a destination key
by using:
-a distance array(how much we traveled from the source) 
-and a parent array to keep track from where we've come to the current node
*/


vector<int> G[MAX]; //I use an adjacency list, because it requires less space storage, but the input will look like a matrix.

int main(){
    int n; //number of nodes
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

    int visited[n]={0};
    int d[n]{0}; //shortest distance of each node from source vertex
    int p[n]; //it stores the parent, it's where did i come from to reach that node. like the previous node.
    int s;
    cout<<"enter the source key (please bear in mind that the indexation of the vertices start from 0 to n-1): ";
    cin>>s;
    visited[s]=1; //i'll declare it visited because, i'm already processing it
    d[s] = 0; //because from source to source, the shortest distance will be 0
    p[s] = -1; //parent of the source vertex will be -1, because there is no parent to the source vertex,
              // we're not coming from anywhere, we're starting from it.
    //now we will run the bfs:
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop(); //i'll remove the source from the queue
        //and then i'll be going to its neighbors
        for(int u: G[v]){
            if(!visited[u]){ /*i'll check if it's visited
            if it's not visited, i'll make sue to mark it as visited*/
                visited[u]=1;
            //and then I'll have to push it into the queue because i'll be exploring it shortly
                q.push(u);
            /*and then i add to the distance of u, because
            I'm coming from v to u so I'm traveling one unit of distance from v to u*/
                d[u]=d[v]+1;
            /*And then I'll mark parent of u as v, because from v i'm coming to u*/
                p[u] = v;


            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<"distance from source to "<<i<<": "<<d[i]<<endl;
    }
    //we will have to find the path till destination
    int dest;
    vector<int> path;
    cout<<"Please enter the key of the destination: ";
    cin>>dest;
    if(visited[dest]==0){
        cout<<"No path found."<<endl;
        //because we haven't reached destination so there is no path.
    }
    else{
        int x=dest;
        //i need to know from where i reach destination
        //so i will look for the parent of destination, and then i will also need to know from where i reach the parent and look for its own parent...
        //so i will keep on going until I reach source, and the parent will be -1
        while(x!=-1){
            path.push_back(x);
            //now from where did i reach x? that'll be the parent of x
            x = p[x];
            //and then eventually x will become -1.
            //we are backtracking we were in destination and we are finding the path back to source.
            //so we will have to reverse the array path
        }
        reverse(path.begin(), path.end());

        cout<<"the shortest path from "<<s<<" to "<<dest<<": "<<endl;
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;


    }




}
