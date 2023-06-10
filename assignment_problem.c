#include<stdio.h>
int getm(int k1,int k2,int n,int a[n][n],int s)
{int mini,i,j;
for(i=0;i<n;i++)
{mini=0;
    for(j=0;j<n;j++)
    {
        if((i!=k1)&&(j!=k2))
        {
            if(a[i][j]!=-1000){
         if(mini==0)
         {
             mini=a[i][j];
         }
         else if(mini>a[i][j])
         {
             mini=a[i][j];
         }
        }}
    }
    s=s+mini;
}
return s;
}
int main()
{
    int n,i,j,k1,k2,s,pre,min,fixed=0;
    printf("enter no of rows:");
    scanf("%d",&n);
    int a[n][n],pos[n];
    printf("enter matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);

        }
    }
    for(i=0;i<n;i++)
    {pre=-1;
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=-1000){
            s=a[i][j]+fixed;

            min=getm(i,j,n,a,s);
//printf("min=%d\n",min);
            if(pre==-1)
            {k1=i;k2=j;
                pre=min;
            }
            else if(min<pre)
            {
                pre=min;
                k1=i;
                k2=j;
            }
        }}
        fixed=fixed+a[k1][k2];
        //printf("%d\n**\n",pre);
        pos[i]=a[k1][k2];
      //  printf("%d====\n",pos[i]);
        for(int ii=0;ii<n;ii++)
        {
            for(int jj=0;jj<n;jj++)
            {if((ii==k1)||(jj==k2))
                a[ii][jj]=-1000;
            }
        }
    }
 for(int new=0;new<n;new++)
        {
            printf("%d\t%d\n",new+1,pos[new]);

        }
}
