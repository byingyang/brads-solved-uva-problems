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
	
	for(i=0;i<MAXV;i++) g->degree[i] = 0;
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
	
	for(i=0;i<g->nvertices;i++) {
		printf("%d: ",i);
		for(j=0;j<g->degree[i];j++) {
			printf(" %d",g->edges[i][j]);
		}
		printf("\n");
	}
}

bool processed[MAXV];
bool discovered[MAXV];
int color[MAXV];
int depth[MAXV];
int p[MAXV];

void init_search(graph *g) {
	int i;
	for(i=0;i<g->nvertices;i++) {
		processed[i] = discovered[i] = false;
		color[i] = 0;
		depth[i] = 10000;
		p[i] = 0;
	}
}

bool bfs(graph *g, int start) {
	queue<int> q;
	int v;
	int i;
	
	init_search(g);
	q.push(start);
	p[start] = 1;
	color[start] = 1;
	depth[start] = 0;
	
	while(!q.empty()) {
		v = q.front();
		q.pop();
		for(i=0;i<g->degree[v];i++) {
			int edge = g->edges[v][i];
			if(p[v] == p[edge])
				return false;
			else {
				if(color[edge] == 0) {
					color[edge] = 1;
					depth[edge] = depth[v] + 1;
					p[edge] = 3 - p[v];
					q.push(edge);
				}
			}
		}
		color[v] = 2;
	}
	return true;
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

int main() {
	int v, e;
	while((cin >> v) && v) {
		cin >> e;
		graph g;
		read_graph(&g,v,e,false);
		//print_graph(&g);
		if(bfs(&g,0))
			printf("BICOLORABLE.");
		else
			printf("NOT BICOLORABLE.");
		cout << endl;
	}
	return 0;
}
