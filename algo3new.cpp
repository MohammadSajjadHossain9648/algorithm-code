#include<bits/stdc++.h>

using namespace std;
int ver,a,b, s,u,i, adj[100][100]={0};
int clr[100],dis[100],p[100];
queue<int> Q;


void bfs(int s)
{

    for(int i=1; i<=ver; i++)
    {
        clr[i]=0;
        dis[i]=200000;
        p[i]=-1;
    }
    clr[s]=1;
    dis[s]=0;
    p[s]=-1;
    Q.push(s);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=1; i<=ver; i++)
        {
            if( adj[u][i]==1 && clr[i]==0)
            {
                clr[i]=1;
                dis[i]=dis[u]+1;
                p[i]=u;
                Q.push(i);
            }
        }
        clr[u]=2;
    }

    for(int i=1;i<=ver;i++)
    {   cout<<"vertex :"<<i<<"      ";


    }
    cout<<endl;
    for(int i=1;i<=ver;i++)
    {
        cout<<"color: "<<clr[i]<<"      ";

    }
     cout<<endl;
    for(int i=1;i<=ver;i++)
    {
        cout<<"Prev: "<<p[i]<<"     ";


    }
     cout<<endl;

     for(int i=1;i<=ver;i++)
    {
        cout<<"Dis: "<<dis[i]<<"        ";

    }
}

int main()

{
    cout<<"Number of vertex:  ";

    cin>>ver;

    while(1)
    {
        cout<<endl<<"Edge  : "<<i<<": ";
        cin>>a>>b;
        if(a>ver || a<0 || b>ver || b<0)
        {
            cout<<"Invalid  try again."<<endl;
            continue;
        }

        else if(a==0 && b==0)
        {
            break;
        }
        else

        {
            adj[a][b]=1;
            adj[b][a]=1;
            i++;

        }

    }

    for(int i=1; i<=ver; i++)
    {

       for(int j=1; j<=ver; j++)
       {
           cout<< adj[i][j]<<"\t";
       }
       cout <<" \n";
    }

ab:
    cout<<"enter s  ";
    cin>>s;

    if(s>ver || s<0)
    {
        cout<<"invalid try again"<<endl;
        goto ab;
    }
    bfs(s);

}
