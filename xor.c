#include<stdio.h>  
int n,m;  
struct haha  
{  
      int next[3];  
      int nm;  
}node[100005*4];  
int pos;  
int makend()  
{  
    int i;  
    pos++;  
    for(i=0;i<2;i++)  
        node[pos].next[i]=-1;  
    node[pos].nm=0;  
  
    return pos;  
  
}  
void _insert(int x)  
{  
    int cur=0,i;  
    for(i=0;i<30;i++)  
    {  
        int flag=(x&(1<<i))?1:0;  
        if(node[cur].next[flag]==-1)  
             node[cur].next[flag]=makend();  
        cur=node[cur].next[flag];  
    }  
    node[cur].nm=x;  
}  
int findd(int x)  
{  
    int cur=0,i;  
    for(i=0;i<30;i++)  
    {  
        int flag=(x&(1<<i))?1:0;  
        if(flag==1)  
        {  
             if(node[cur].next[0]!=-1)  
                cur=node[cur].next[0];  
             else cur=node[cur].next[1];  
        }  
        else  if(flag==0)  
        {  
               if(node[cur].next[1]!=-1)  
                    cur=node[cur].next[1];  
               else cur=node[cur].next[0];  
        }  
  
    }  
    return x^node[cur].nm;  
}  
int mmax(int a,int b)  
{  
    return a>b?a:b;  
}  
int main()  
{  
     int i,x;  
     while(scanf("%d%d",&n,&m)!=EOF)  
     {  
         int mx=0;  
         pos=0;  
         for(i=0;i<2;i++)  
            node[pos].next[i]=-1;  
            node[pos].nm=0;  
         for(i=0;i<n;i++)  
         {  
             scanf("%d",&x);  
             if(i!=0)  
                mx=mmax(mx,findd(x));  
             _insert(x);  
         }  
         if(mx>m)  
           printf("YES\n");  
           else printf("NO\n");  
     }  
     return 0;  
} 
淡栀微澜  20:09:21
谢谢