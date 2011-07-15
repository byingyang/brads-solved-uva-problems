//20043 10092
//Chapter 10: The problem with the problem setter
//Brad Yinger

#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl

using namespace std;

#define MAXV 1024
#define MAXDEGREE 1024

struct edge {
	unsigned short v;
	unsigned char capacity;
	unsigned char flow;
	unsigned char residual;
	bool orig;
};

struct graph {
	edge edges[MAXV][MAXDEGREE];
	unsigned short degree[MAXV];
	unsigned short nvertices;
	unsigned short nedges;
};

bool processed[MAXV];
bool discovered[MAXV];
short parent[MAXV];

void insert_flow_edge(graph &g, int x, int y, bool directed, int w, bool orig) {
	g.edges[x][g.degree[x]].v=y;
	g.edges[x][g.degree[x]].capacity=w;
	g.edges[x][g.degree[x]].flow=0;
	g.edges[x][g.degree[x]].residual=w;
	g.edges[x][g.degree[x]].orig=orig;
	g.degree[x]++;
	if(!directed)
		insert_flow_edge(g,y,x,true,w,orig);
	else
		g.nedges++;
}

bool valid_edge(edge e) {
	return (e.residual > 0);
}

void bfs(graph &g, int start) {
	queue<int> q;
	int v,y;
	q.push(start);
	discovered[start]=true;
	while(!q.empty()) {
		v=q.front();
		q.pop();
		processed[v]=true;
		For(i,0,g.degree[v]) {
			y=g.edges[v][i].v;
			if(valid_edge(g.edges[v][i])) {
				if(!discovered[y]) {
					q.push(y);
					discovered[y]=true;
					parent[y]=v;
				}
			}
		}
	}
}

void initialize_search(graph &g) {
	For(i,1,g.nvertices+1) {
		processed[i]=discovered[i]=false;
		parent[i]=-1;
	}
}

edge *find_edge(graph &g, int x, int y) {
	For(i,0,g.degree[x]) {
		if(g.edges[x][i].v==y)
			return &(g.edges[x][i]);
	}
	return NULL;
}

int path_volume(graph &g, int start, int end, short parents[]) {
	if(parents[end] == -1) return 0;
	edge *e;
	e=find_edge(g,parents[end],end);
	if(start==parents[end])
		return e->residual;
	else
		return min(path_volume(g,start,parents[end],parents),(int)e->residual);
}

void augment_path(graph &g, int start, int end, short parents[], int volume) {
	if(start==end) return;
	edge *e;
	e=find_edge(g,parents[end],end);
	e->flow+=volume;
	e->residual-=volume;
	e=find_edge(g,end,parents[end]);
	e->residual+=volume;
	augment_path(g,start,parents[end],parents,volume);
}

void add_residual_edges(graph &g) {
	For(i,1,g.nvertices+1) {
		int deg=0;
		for(int j=g.degree[i]-1;j>=0;j--) {
			if(find_edge(g,g.edges[i][j].v,i)==NULL)
				insert_flow_edge(g,g.edges[i][j].v,i,true,0,false);
		}
	}
}

void print_flow_graph(graph &g) {
	for(int i=1;i<=g.nvertices;i++)
	{
		printf("%d: ",i);
		for(int j=g.degree[i]-1;j>=0;j--)
			if(g.edges[i][j].orig)
				printf(" %d(%d,%d,%d)",g.edges[i][j].v,g.edges[i][j].capacity,
					g.edges[i][j].flow,g.edges[i][j].residual);
		printf("\n");
	}
}

void netflow(graph &g, int source, int sink) {
	int volume;
	add_residual_edges(g);
	initialize_search(g);
	bfs(g,source);
	volume = path_volume(g,source,sink,parent);
	while(volume > 0) {
		augment_path(g,source,sink,parent,volume);
		initialize_search(g);
		bfs(g,source);
		volume=path_volume(g,source,sink,parent);
		//D(volume);
	}
}

int read_flow_graph(graph &g, int nk, int np, bool directed) {
	int nki, s = 1, t = nk+np, catCaps = 0, nCat, catNum;
	vector<int> v;
	
	g.nvertices = t+2;
	
	For(i,0,nk) {
		cin >> nki;
		catCaps += nki;
		v.push_back(nki);
	}
	For(i,0,np) {
		cin >> nCat;
		insert_flow_edge(g, s, s+i+1, directed, 1,true);
		For(j,0,nCat) {
			cin >> catNum;
			insert_flow_edge(g, s+i+1, s+np+catNum, directed, 1,true);
		}
	}
	For(i,0,v.size()) {
		insert_flow_edge(g, s+np+i+1, s+t+1, directed, v[i],true);
	}
	
	return catCaps;
}

void init_graph(graph &g) {
	g.nvertices=g.nedges=0;
	for(int i=1;i<=MAXDEGREE;i++)
		g.degree[i]=0;
}

int main() {
	int nk, np;
	bool flag = false;
	while(cin >> nk >> np && (nk && np)) {
		graph g;
		init_graph(g);
		int s=1;
		int cap = read_flow_graph(g,nk,np,true);
		netflow(g,s,nk+np+s+1);
		//print_flow_graph(g);
		int ff = 0;
		For(i,0,g.degree[s])
			if(g.edges[s][i].flow>0)
				ff+=g.edges[s][i].flow;
		
		
		cout << (ff==cap?1:0);
		
		if(ff==cap) {
			flag = true;
			For(c,s+np+1,g.nvertices) {
				cout << endl;
				bool flag2 = false;
				For(i,s+1,s+np+1) {
					For(j,0,g.degree[i]) {
						if(g.edges[i][j].orig && g.edges[i][j].flow > 0 && g.edges[i][j].residual == 0 && g.edges[i][j].v==c) {
							if(flag2) cout << " ";
							flag2 = true;
							printf("%d",i-s);
						}
					}
	            }
			}
		}
		cout << endl;
	}
	return 0;
}


