
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
            for(int it=adj[u].begin(); it!=adj[u].end(); it++)
            {


                if(  clr[*it]==0)
                {
                    clr[*it]=1;
                    dis[*it]=dis[u]+1;
                    p[*it]=u;
                    Q.push(*it);
                }
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
             adj[a].push_back(b);
            adj[b].push_back(a);

        }

    }

    for(int i=1; i<=ver; i++)
    {
        printf("adj[%d}",i);
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {
            cout<<"->"<<*it;
        }
        cout<<endl;

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
