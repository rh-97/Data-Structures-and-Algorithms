/*
  
  Author: Rakib Hasan
  Prim's Algorithm

*/
 
 
#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define PII pair<int, int>
#define F first
#define S second

struct Node {
	int id;
	int cost = INT_MAX;
	bool visited = false;
	bool pushed = false;
	vector<PII> adjacents;
	//Node (int i) : id(i) {}
	bool operator() (Node a, Node b) { return a.cost > b.cost; }
};

unordered_map<int, Node> G;


priority_queue<Node, vector<Node>, Node> PQ;

void prim() {
	int s, d, w;
	while (cin >> s >> d >> w) {
		G[s].id = s;
		G[s].adjacents.PB({d, w});
		
		G[d].id = d;
		G[d].adjacents.PB({s, w});
	}
	
	G[s].cost = 0;
	PQ.push(G[s]);
	
	int min_cost = 0;
	while (!PQ.empty()) {
		Node *node = &G[PQ.top().id];
		PQ.pop();
		node->visited = true;
		min_cost += node->cost;
		cout << "Node: " << node->id << '\n';
		for (PII &adj : node->adjacents) {
			if (!G[adj.F].visited and G[adj.F].cost > adj.S) {
				G[adj.F].cost = adj.S;
				if (!G[adj.F].pushed) PQ.push(G[adj.F]), G[adj.F].pushed = true;
			}
		}
	}
	cout << "\n\n Minimum Cost = " << min_cost << ".\n";
}

int32_t main() {
	
	prim();
	
	return 0;
}




