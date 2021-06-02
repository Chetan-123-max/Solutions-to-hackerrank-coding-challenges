#include<stdlib.h>
#include<stdio.h>

struct s
    {
    int *p,size;
    int M;
}s[100000];

int *fun(int M,int *a,int size)
{

 int *p=(int *)malloc(sizeof(int )*M);
 for(int i=0;i<size;i++)
       p[i]=a[i];
 free(a);
return p;
}

int main() {
    int x,y,q,n,i,lastans=0,a,d,j;
    
    for(int k=0;k<100000;k++){
        s[k].M=100;
        s[k].p=(int*)malloc(sizeof(int)*s[k].M);
    }
    
    scanf("%d %d",&n,&q);
    for(i=1;i<=q;i++)
        {
        scanf("%d %d %d",&a,&x,&y);
        if(a==1)
            {
            d=((x^lastans)%n);
            if(s[d].size>s[d].M){
                s[d].M=2*s[d].M;
                s[d].p=fun(s[d].M,s[d].p,s[d].size);   
            }
            s[d].p[s[d].size++]=y;
        }
        else
            {
            d=((x^lastans)%n);
            j=s[d].size;
            lastans=s[d].p[y%j];
            printf("%d\n",lastans);
        }
    }
}


