//20043 10004
//Chapter 9: Bicoloring
//Brad Yinger

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

#define MAXV 205
#define MAXDEGREE 205

struct graph {
	int edges[MAXV+1][MAXDEGREE];
	int degree[MAXV+1];
	int nvertices;
	int nedges;
};

void initialize_graph(graph *g) {
	int i;
	
	g->nvertices = 0;
	g->nedges = 0;
	
	for(i=1;i<=MAXV;i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed) {
	if(g->degree[x] > MAXDEGREE)
		printf("Warning: insertion(%d,%d) exceeds max degree\n",x,y);
	
	g->edges[x][g->degree[x]] = y;
	g->degree[x]++;
	
	if(!directed)
		insert_edge(g,y,x,true);
	else
		g->nedges++;
}

void print_graph(graph *g) {
	int i,j;
	
	for(i=1;i<=g->nvertices;i++) {
		printf("%d: ",i);
		for(j=0;j<g->degree[i];j++) {
			printf(" %d",g->edges[i][j]);
		}
		printf("\n");
	}
}

void read_graph(graph *g, int v, int e, bool directed) {
	int i;
	int x, y;
	
	initialize_graph(g);
	
	g->nvertices = v;
	
	for(i=1;i<=e;i++) {
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,directed);
	}
}

int find_path(int start, int end, int parents[], int count) {
	if((start == end) || (end == -1))
		return count + 1;
	else {
		return 1 + find_path(start, parents[end], parents, count);
	}
}

// for dfs
bool processed[MAXV];
bool discovered[MAXV];
int parent[MAXV];

void init_search(graph *g) {
	int i;
	for(i=1;i<=g->nvertices;i++) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

bool finished = false;

void process_vertex(int v) {
	printf("processed vertex %d\n", v);
}

void process_edge(int x, int y) {
	printf("processed edge %d %d\n", x,y);
	printf("parent: %d\n", parent[x]);
	//if(parent[x] != y) {
	//	printf("Cycle from %d to %d\n",y,x);
	//	int nv = find_path(y,x,parent,0);
	//	cout << nv << endl;
	//	if(nv % 2)
	//		finished = true;
	//}
}

bool valid_edge(int e) {
	return true;
}

void dfs(graph *g, int v) {
	int i;
	int y;
	
	if(finished) return;
	
	discovered[v] = true;
	process_vertex(v);
	
	For(i, 0, g->degree[v]) {
		y = g->edges[v][i];
		if(valid_edge(y)) {
			if(!discovered[y]) {
				cout << "parent of " << y << " is " << v << endl;
				parent[y] = v;
				dfs(g,y);
			}
			else {
				if(!processed[y]) {
					process_edge(v,y);
				}
			}
		}
		if(finished) return;
	}
	
	processed[v] = true;
}

void bfs(graph *g, int start) {
	queue<int> q;
	int v;
	int i;
	
	init_search(g);
	q.push(start);
	discovered[start] = true;
	
	while(!q.empty()) {
		v = q.front();
		q.pop();
		process_vertex(v);
		processed[v] = true;
		for(i=0;i<g->degree[v];i++) {
			int edge = g->edges[v][i];
			if(valid_edge(edge)) {
				if(!discovered[edge]) {
					q.push(edge);
					discovered[edge] = true;
					parent[edge] = v;
				}
				if(!processed[edge]) process_edge(v,edge);
			}
		}
	}
}

int main() {
	int v, e;
	while((cin >> v) && v) {
		cin >> e;
		graph g;
		read_graph(&g,v,e,false);
		//finished = false;
		//init_search(&g);
		//print_graph(&g);
		//dfs(&g,0);
		bfs(&g,2);
		if(finished)
			printf("NOT BICOLORABLE.");
		else
			printf("BICOLORABLE.");
		cout << endl;
	}
	return 0;
}
