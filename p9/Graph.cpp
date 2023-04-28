#include<iostream> 
#include<list>
#include<map>
#include<queue>

using namespace std;

map<int, list<int>> adj;

void addEdge(int s, int e) {
    if(adj.find(s) == adj.end()) adj.insert(make_pair(s, list<int>()));
    if(adj.find(e) == adj.end()) adj.insert(make_pair(e, list<int>()));
    adj.at(s).push_back(e);
    adj.at(e).push_back(s);
}

void dfs(int n, bool* visited) {
    if(visited[n]) return;
    visited[n] = true;
    cout<< n << " ";
    list<int> l = adj.at(n);
    list<int>::iterator it;
    for(it = l.begin(); it != l.end(); it++) {
        dfs(*it, visited);
    }
}

void bfs(int n, int size) {
    bool* visited = new bool[size];
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(!q.empty()) {
        list<int> l = adj.at(q.front());
        cout<< q.front() << " ";
        q.pop();
        list<int>::iterator it;
        for(it = l.begin(); it != l.end(); it++) {
            if(!visited[*it]) {
                q.push(*it);
                visited[*it] = true;
            }
        }
    }
    cout<<endl;
}

int main() {
    // no of nodes
    int n;
    cout<< "Enter no of nodes : ";
    cin >>n;

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

    int start;
    cout<<"Enter the start node : ";
    cin >> start;

    cout<< "dfs : ";
    dfs(start, new bool[n]);
    cout<<"\nbfs : ";
    bfs(start, n);
    return 0;
}