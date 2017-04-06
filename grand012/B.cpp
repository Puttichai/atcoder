#include <bits/stdc++.h>

void collect(std::vector<std::vector<int> >& graph, std::vector<int> curNodes, std::vector<int>& collection, int dist)
{
    if (curNodes.size() == 0) return;
    std::vector<int> newCurNodes;
    for (std::vector<int>::iterator i = curNodes.begin(); i != curNodes.end(); i++) {
	collection[*i] = 0;
	for (std::vector<int>::iterator j = graph[*i].begin(); j != graph[*i].end(); j++) {
	    if (collection[*j] == 0) continue;
	    newCurNodes.push_back(*j);
	}
    }
    dist--;
    if (dist < 0) return;
    return collect(graph, newCurNodes, collection, dist--);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    std::vector<std::vector<int> > G(N); // graph with N vertices
    while (M--) {
	int a, b;
	scanf("%d %d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }
    int Q;
    scanf("%d", &Q);
    std::vector<int> V(Q), D(Q), C(Q);
    for (int i = 0; i < Q; i++) {
	scanf("%d %d %d", &V[i], &D[i], &C[i]);
	V[i]--;
    }
    
    std::vector<int> colors(N, 0);
    std::vector<int> collection(N, -1); // N-vector filled with -1
    for (int k = 0; k < Q; k++) {
    	std::vector<int> curNodes(1, V[k]);
    	collect(G, curNodes, collection, D[k]);
    	for (int l = 0; l < N; l++) {
    	    if (collection[l] > -1) {
    		colors[l] = C[k];
    	    }
    	}
	std::fill(collection.begin(), collection.end(), -1); // reset the vector
    }
    for (int i = 0; i < N; i++) {
    	printf("%d\n", colors[i]);
    }
}
