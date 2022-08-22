#include<stdio.h>
int n,adj[100][100],row[100],col[100];
void graph()
{
    int a,b;
    printf("Enter No. of vertex: ");
    scanf("%d",&n);
    while(1)
    {
        printf("Edge :");
        scanf("%d %d",&a,&b);
        if(a>n || b>n)
            printf("Invalid\n");
        else if(a==0 || b==0 )
            break;
        else
        {
            adj[a][b]=1;

        }
    }
}
void In_degree_Out_degree()
{
    printf("\n\n");
    int i,j,r=0,c=0;
    for(i=1;i<=n;i++)
    {
        printf("Node %d in-degree & out-degree:",i);
        for(j=1;j<=n;j++)
        {
           r=r+adj[i][j];
           c=c+adj[j][i];
        }
        row[i]=r;
        col[i]=c;
        printf("%d & %d",col[i],row[i]);
        r=0;c=0;
        printf("\n");
    }

}

void Maximum_out_degree()
{
    In_degree_Out_degree();
    printf("\n");
    int max,i;
    max=row[1];
    for(i=2;i<=n;i++)
       if(max<row[i])
          max=row[i];
    printf("Maximum out-degree:%d",max);
    printf("\n");

}
void Node_Maximum_out_degree()
{
   In_degree_Out_degree();
   printf("\n");
    int max,i,p;
    max=row[1];
    p=max;
    for(i=2;i<=n;i++)
      {
          if(max<row[i])
             {
                 max=row[i];
                 p=i;
             }

      }
    printf("Node %d maximum out-degree that is %d",p,max);
    printf("\n");

}
void Minimum_in_degree()
{
    In_degree_Out_degree();
    printf("\n");
    int min,i;
    min=col[1];
    for(i=2;i<=n;i++)
       if(min>col[i])
          min=col[i];
    printf("Minimum in-degree:%d",min);
    printf("\n");

}

void Two_In_degree()
{
    In_degree_Out_degree();
    printf("\n\n");
    int i,j,c=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           c=c+adj[j][i];
        }
        if(c==2)
            printf("Node %d two in-degree\n",i);
        c=0;

    }

}

void  Out_degree_even()
{
     In_degree_Out_degree();
     printf("\n\n");
    int i,j,r=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
           r=r+adj[i][j];
        }

        if(r%2==0)
            printf("Node %d out-degree even\n",i);
        r=0;

    }

}

void Number_out_degree_even_in_degree_odd()
{
    In_degree_Out_degree();
    printf("\n\n");
    int i,j,r=0,c=0,w=0;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)
        {
           r=r+adj[i][j];
           c=c+adj[j][i];
        }

        if(r%2==0 && c%2!=0)
            {
                 printf("Node %d out-degree even & in-degree odd\n",i);
                 w++;
            }
        r=0;c=0;

    }
    if(w==0)
    printf("None");


}

void Directed_or_Undirected()
{
   In_degree_Out_degree();
   printf("\n\n");
    int i,j,r=0,c=0;
    for(i=1;i<=n;i++)
    {

        for(j=1;j<=n;j++)
        {
           r=r+adj[i][j];
           c=c+adj[j][i];
        }

        if(r==c)
             printf("Node %d is Undirected graph",i);
        else
            printf("Node %d is Directed graph",i);
        r=0;c=0;
        printf("\n");
    }


}
void display()
{
    int i,j;
    printf("\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
           {
               printf("%d ",adj[i][j]);
           }
     printf("\n");
    }
}
int main()
{
    graph();
    int c;
    while(1){
   printf("1.In-degree & Out-degree ");
    printf("\n2.Maximum out-degree");
    printf("\n3.Node(Maximum out-degree)");
    printf("\n4.Minimum in-degree");
    printf("\n5.Two In-degree");
    printf("\n6.Out-degree even");
    printf("\n7.Number(out-degree even && in-degree odd)");
    printf("\n8.Directed/Undirected");
    printf("\n9.Display");
    printf("\n10.Exit");

    printf("\n\nCHOICE:");
    scanf("%d",&c);

    if(c==1)
       In_degree_Out_degree();
    else if(c==2)
       Maximum_out_degree();
    else if(c==3)
       Node_Maximum_out_degree();
    else if(c==4)
       Minimum_in_degree();
    else if(c==5)
       Two_In_degree();
    else if(c==6)
       Out_degree_even();
    else if(c==7)
       Number_out_degree_even_in_degree_odd();
    else if(c==8)
       Directed_or_Undirected();
    else if(c==9)
       display();
    else if(c==10)
        break;
    else
        printf("Invalid");
    }

}
