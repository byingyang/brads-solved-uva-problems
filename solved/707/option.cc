#include<stdio.h>
int m,n,t,mat[101][101][101],poznato[101],mozi[101],iii[101],jjj[101];
const int dx[]={0,0,0,-1,1};
const int dy[]={0,1,-1,0,0};
void memo(int i,int j,int v);
void najdipat(int i,int j,int v);
main()
{
      int tt,l,r,tp,b,i,j,k,br,test,mozii,da;
      test=0;
      while(1)
      {
       scanf("%d %d %d",&m,&n,&t);
       if(m==0 && n==0 && t==0) break;

       test++;
       printf("Robbery #%d:\n",test);

       for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
         for(k=1;k<=t;k++)
          mat[i][j][k]=-1;
       for(i=1;i<=t;i++) {mozi[i]=-1;poznato[i]=0;}
       scanf("%d",&br);
       if(br>0)
       {
       for(i=1;i<=br;i++)
       {
        scanf("%d %d %d %d %d",&tt,&l,&tp,&r,&b);
        for(j=l;j<=r;j++)
         for(k=tp;k<=b;k++)
          mat[j][k][tt]=0;
       }
       
       for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
         if(mat[i][j][1]==-1)
         {
          mat[i][j][1]=3;
          memo(i,j,1);
          }
       for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
         if(mat[i][j][t]==3)
         {
          mat[i][j][t]=1;
          najdipat(i,j,t);
          mat[i][j][t]=3;
          }
       da=1;
       for(i=1;i<=t;i++)
        if(!poznato[i]) { da=0; break;}
        
         if(!da) printf("The robber has escaped.\n");
        else{
       mozii=0;
       for(i=1;i<=t;i++)
        if(mozi[i]==1) mozii++;
       if(mozii==0) printf("Nothing known.\n");
       else for(i=1;i<=t;i++) if(mozi[i]) printf("Time step %d: The robber has been at %d,%d.\n",i,iii[i],jjj[i]);
       }
       }
       else{
            if(m==1 && m==n) for(i=1;i<=t;i++) { printf("Time step %d: The robber has been at 1,1.\n",i);}
            else printf("Nothing known.\n");
            }
printf("\n");
       }
}
void memo(int i,int j,int v)
{
     int ii;
     if(v<t)
     {
     for(ii=0;ii<=4;ii++)
     {
     if((i+dx[ii])>=1 && (i+dx[ii])<=m && (j+dy[ii]>=1) && (j+dy[ii]<=n))
     {
      if(mat[i+dx[ii]][j+dy[ii]][v+1]==-1)
      {
       mat[i+dx[ii]][j+dy[ii]][v+1]=3;
       memo(i+dx[ii],j+dy[ii],v+1);
      }
      }
     }
     }
     else{
          mat[i][j][v]=3;
          }
}
void najdipat(int i,int j,int v)
{
int ii,jj,kk;
  if(v>1)
  {
    for(ii=0;ii<=4;ii++)
     {
     if((i+dx[ii])>=1 && (i+dx[ii])<=m && (j+dy[ii]>=1) && (j+dy[ii]<=n))
     {
      if(mat[i+dx[ii]][j+dy[ii]][v-1]==3)
      {
       mat[i+dx[ii]][j+dy[ii]][v-1]=1;
       najdipat(i+dx[ii],j+dy[ii],v-1);
       mat[i+dx[ii]][j+dy[ii]][v-1]=3;
      }
      }   
     }
    }
  else {
     for(kk=1;kk<=t;kk++)
       for(ii=1;ii<=m;ii++)
        for(jj=1;jj<=n;jj++)
         if(mat[ii][jj][kk]==1)
         {
          if(!poznato[kk]) 
           {
           mozi[kk]=1;
           poznato[kk]=1;
           iii[kk]=ii;
           jjj[kk]=jj;
           }
          else
          {

              if(ii!=iii[kk] || jj!=jjj[kk]) mozi[kk]=0;
          }     
         }
       }
}
