//20043 10182
//Chapter 12: Bee Maja 
//Brad Yinger

#include <iostream>
using namespace std;
int dx[]={-1,-1,0,1,1,0};
int dy[]={1,0,-1,-1,0,1};
#define MAX 100005
int main() {
  int data[MAX][2];
  int count=2,ring=0,x=0,y=0,n=0;
  data[1][0]=0;
  data[1][1]=0;
  while (count<MAX){
    int p[ring];
    fill(p,p+6,ring);
	ring++;
    p[0]--;
	p[5]++;
    for(int i=0;i<6;i++) {
      	for(int j=0;j<p[i]&&count<MAX;j++) {
   			x+=dx[i];
    		y+=dy[i];
    		data[count][0]=x;
    		data[count][1]=y;
				count++;
      		}
    	}
  	}
  	while(scanf("%d",&n)!=-1) printf("%d %d\n",data[n][0],data[n][1]);
	return 0;
}
