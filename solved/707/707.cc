//20043 707
//Chapter 12: Robbery 
//Brad Yinger

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cout << #x " is " << x << endl
#define N 103

const int dx[]={0,0,0,-1,1};
const int dy[]={0,1,-1,0,0};

int w,h,timeLocked;

using namespace std;

void mem(int memo[N][N][N],int i,int j,int v)
{
     int ii;
     if(v<timeLocked)
     {
     for(ii=0;ii<=4;ii++)
     {
     if((i+dx[ii])>=1 && (i+dx[ii])<=w && (j+dy[ii]>=1) && (j+dy[ii]<=h))
     {
      if(memo[i+dx[ii]][j+dy[ii]][v+1]==-1)
      {
       memo[i+dx[ii]][j+dy[ii]][v+1]=3;
       mem(memo,i+dx[ii],j+dy[ii],v+1);
      }
      }
     }
     }
     else{
          memo[i][j][v]=3;
          }
}

void find_possibilities(int memo[N][N][N],int pos[],int spots[],int xpos[],int ypos[],int i,int j,int v)
{
int ii,jj,kk;
  if(v>1)
  {
    for(ii=0;ii<=4;ii++)
     {
     if((i+dx[ii])>=1 && (i+dx[ii])<=w && (j+dy[ii]>=1) && (j+dy[ii]<=h))
     {
      if(memo[i+dx[ii]][j+dy[ii]][v-1]==3)
      {
       memo[i+dx[ii]][j+dy[ii]][v-1]=1;
       find_possibilities(memo,pos,spots,xpos,ypos,i+dx[ii],j+dy[ii],v-1);
       memo[i+dx[ii]][j+dy[ii]][v-1]=3;
      }
      }   
     }
    }
  else {
     for(kk=1;kk<=timeLocked;kk++)
       for(ii=1;ii<=w;ii++)
        for(jj=1;jj<=h;jj++)
         if(memo[ii][jj][kk]==1)
         {
          if(!pos[kk]) 
           {
           spots[kk]=1;
           pos[kk]=1;
           xpos[kk]=ii;
           ypos[kk]=jj;
           }
          else
          {

              if(ii!=xpos[kk] || jj!=ypos[kk]) spots[kk]=0;
          }     
         }
       }
}

int main() {
	int n,k=1;
	while((cin >> w >> h >> timeLocked) && (w && h && timeLocked)) {
		// -1 = uncomputed
		// 0 = vacant
		// 1 = possibility
		// memo[width][height][time]
		int memo[N][N][N]={-1},pos[N]={0},spots[N]={-1},xpos[N],ypos[N];
		
		for(int i=1;i<=w;i++)
	        for(int j=1;j<=h;j++)
	         for(int k=1;k<=timeLocked;k++)
	          memo[i][j][k]=-1;
	       for(int i=1;i<=timeLocked;i++) {spots[i]=-1;pos[i]=0;}
		
		printf("Robbery #%d:\n",k++);
		
		cin >> n;
		if(!n) {
			if(w==1&&h==1) 
				For(i,1,timeLocked+1) {
					printf("Time step %d: The robber has been at 1,1.\n",i);
				}
		    else {
				printf("Nothing known.\n");
		    }
		}
		else {
			for(int i=1;i<=n;i++)
		       {
				int t,tp,l,rp,r,b;
		        scanf("%d %d %d %d %d",&t,&l,&tp,&r,&b);
		        for(int j=l;j<=r;j++)
		         for(int k=tp;k<=b;k++)
		          memo[j][k][t]=0;
		       }

		       for(int i=1;i<=w;i++)
		        for(int j=1;j<=h;j++)
		         if(memo[i][j][1]==-1)
		         {
		          memo[i][j][1]=3;
		          mem(memo,i,j,1);
		          }
		       for(int i=1;i<=w;i++)
		        for(int j=1;j<=h;j++)
		         if(memo[i][j][timeLocked]==3)
		         {
		          memo[i][j][timeLocked]=1;
		          find_possibilities(memo,pos,spots,xpos,ypos,i,j,timeLocked);
		          memo[i][j][timeLocked]=3;
		          }
				bool found=true;
		       for(int i=1;i<=timeLocked;i++)
		        if(!pos[i]) { found=false; break;}

		         if(!found) printf("The robber has escaped.\n");
		        else{
		       int possibility=0;
		       for(int i=1;i<=timeLocked;i++)
		        if(spots[i]==1) possibility++;
		       if(possibility==0) printf("Nothing known.\n");
		       else for(int i=1;i<=timeLocked;i++) if(spots[i]) printf("Time step %d: The robber has been at %d,%d.\n",i,xpos[i],ypos[i]);
		       }
		}
			
		cout << endl;
	}
	return 0;
}
