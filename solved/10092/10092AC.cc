using namespace std;   
   
#include <algorithm>   
#include <cctype>   
#include <cmath>   
#include <cstdio>   
#include <cstdlib>   
#include <cstring>   
#include <iostream>   
#include <map>   
#include <queue>   
#include <set>   
#include <sstream>   
#include <stack>   
#include <string>   
#include <vector>   
   
#define EPS 1e-11   
#define inf ( 1LL << 31 ) - 1   
#define LL long long   
   
#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )   
#define rep( i, n ) for( __typeof(n) i = 0; i < ( n ); ++i )   
#define rrep( i, a, b ) for( __typeof(b) i = ( a ); i >= ( b ); --i )   
#define xrep( i, a, b ) for( __typeof(b) i = ( a ); i <= ( b ); ++i )   
   
#define abs(x) (((x)< 0) ? (-(x)) : (x))   
#define all(x) (x).begin(), (x).end()   
#define ms(x, a) memset((x), (a), sizeof(x))   
#define mp make_pair   
#define pb push_back   
#define sz(k) (int)(k).size()   
   
typedef vector <int> vi;   
   
// She   
// May be the reason I survive   
// The why and wherefore I'm alive   
// The one I'll care for through the rough in ready years   
   
//...   
   
const int MAX = 1050;   
const int INF = 1000000000;   
const int MAXA = 1000000;   
const int MAXN = 1025;   
// variables   
   
   
// dinic matching   
struct Arc   
{   
    int from, to, cap, next;       
    bool x;   
} el[MAXA];   
   
int start[MAXN], par[MAXN], d[MAXN], path[MAXN], nv, szp, source, sink, nk, np, matched;   
bool vis[MAXN], found;   
vi cat;   
   
int add_arc(int from, int to, int cap, bool x)   
{   
    el[nv].from = from;   
    el[nv].to = to;   
    el[nv].cap = cap;   
    el[nv].next = start[from];   
//  cout << nv << ' ' << from << ' ' << to << ' ' << start[from]<<endl;
	el[nv].x=x;
	start[from]=nv++;
}

int reverse_arc(int idx) {
	return (idx ^ 1);
}

bool bfs(int from, int to) {
	int eidx;
	ms(vis, 0);
	ms(d, -1);
	queue<int> q;
    q.push(from);   
    d[from] = 0;   
//  cout << sink << endl;   
    while (!q.empty())   
    {   
        int u = q.front(); q.pop();   
        if (u == to) break;   
        for (eidx = start[u]; eidx != -1; eidx = el[eidx].next)   
        {   
//          cout << eidx << endl;   
            int v = el[eidx].to;   
            int rev = reverse_arc(eidx);   
            if (el[rev].cap > 0 && d[v] == -1)   
            {   
                d[v] = d[u] + 1;   
                q.push(v);   
            }   
        }   
           
    }   
    return (d[to] != -1);   
}

int c;   
void update_path()   
{   
//  ++matched;   
    rep(i, szp)   
    {   
        int x = path[i];   
        el[x].cap--;   
        el[reverse_arc(x)].cap++;   
    }   
}   
   
void dfs(int u)   
{   
    if (found) return;   
    vis[u] = true;   
    if (u == sink)   
    {      
        vis[u] = 0;   
        update_path();   
        found = true;   
        return;   
    }   
//  cout << "->" << u << endl;   
    int eidx;   
    for (eidx = start[u]; eidx != -1; eidx = el[eidx].next)   
    {   
        int v = el[eidx].to;   
        if(!vis[v] && d[u] == d[v] + 1 && el[eidx].cap > 0)    
        {   
            path[szp++] = eidx;   
            dfs(v);   
            if (found) return;   
            szp--;   
        }   
    }   
}   
   
void dinic()   
{   
    int ret;   
   
    while (bfs (sink, source))   
    {   
        do   
        {   
            found = false;   
            szp = 0;   
            dfs (source);   
            if (found) ++matched;   
        }    
        while (found);   
    }   
}   
   
int main()   
{   
    while (scanf("%d %d", &nk, &np) == 2)   
    {   
        int X = nk + np, nc, C, req = 0;   
           
        if (X == 0) break;   
        matched = 0;   
        ms(start, -1);   
        ms(el, -1);   
        cat.clear();   
        source = 0, sink = X+1;   
   
        rep(i, nk)    
        {   
            scanf("%d", &C);   
            cat.pb(C);   
            req += C;   
        }   
               
        rep(i, np)   
        {   
            scanf("%d", &nc);   
   
            add_arc(source, i+1, 1, false);                
            add_arc(i+1, source, 0, false);                            
               
            rep(j, nc)   
            {   
                scanf("%d", &C);   
                add_arc(i+1, C+np, 1, true);                   
                add_arc(C+np, i+1, 0, false);                              
            }              
        }   
           
        rep(i, sz(cat))   
        {   
            add_arc(i+1+np, X+1, cat[i], false);   
            add_arc(X+1, i+1+np, 0, false);   
        }   
		
        dinic();   
        //cout << tot << endl;   
        printf("%d\n", (matched==req)?1:0);   

        bool flag = false;   
           
        if (matched == req)   
        {   
            vector <int> ans[25];   
            rep(i, nv)    
            {   
                if (el[i].x && el[i].cap == 0)   
                    ans[el[i].to - np].pb(el[i].from);   
            }   
               
            rep(i, nk)   
            {   
                rep(j, sz(ans[i+1]))   
                {   
                    if (j) printf(" ");   
                    printf("%d", ans[i+1][j]);   
                }   
                printf("\n");   
            }   
               
        }          
           
    }      
}