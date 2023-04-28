#include<iostream> 
#include<queue>
#include<list>
#include<map>

using namespace std;

// int **adj; // adjacency matrix

// list<Node>* adj;

map<int, list<int>> adj;

void addEdge(int s, int e) {
    if(adj.find(s) == adj.end()) adj.insert(make_pair(s, list<int>()));
    if(adj.find(e) == adj.end()) adj.insert(make_pair(e, list<int>()));
    adj.at(s).push_back(e);
    adj.at(e).push_back(s);
}

// void bfs(int n, int start) {
//     bool visited[n];
//     for (int i = 0; i < n; i++) {
//         visited[i] = false;
//     }
//     queue<int> q;
//     q.push(start);
//     visited[start] = true;
//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();
//         cout << current << " ";
//         for (int i = 0; i < n; i++) {
//             if (adj[current][i] == 1 && !visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
//     cout << endl;
// }

// void dfsUtil(int v, bool visited[]) {
//     visited[v] = true;
//     cout << v << " ";
//     for (int i = 0; i < sizeof(visited)/sizeof(visited[0]); i++) {
//         if (adj[v][i] == 1 && !visited[i]) {
//             dfsUtil(i, visited);
//         }
//     }
// }

// void dfs(int n, int start) {
//     bool visited[n];
//     for (int i = 0; i < n; i++) {
//         visited[i] = false;
//     }
//     dfsUtil(start, visited);
//     cout << endl;
// }


int main() {
    // no of nodes
    int n;
    cout<< "Enter no of nodes : ";
    cin >>n;

    // adj = new int*[n];  // creating dynamic adjacency matrix
    // for(int i=0; i<n; i++){
    //     adj[i] = new int[n];
    // }

    // no of edges
    int edges;
    cout<< "Enter no of edges : ";
    cin >>edges;
    cout<<"Enter space seperated nodes : "<< endl;
    for(int i=0;i< edges; i++) {
        int s, e;
        cin>>s;
        cin>>e;
        addEdge(s, e);
    }

    // int start;
    // cout << "Enter the starting node for BFS and DFS: ";
    // cin >> start;
    // bfs(n, start);
    // dfs(n, start);

    return 0;
}