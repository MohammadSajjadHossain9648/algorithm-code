#include<bits/stdc++.h>
using namespace std;


int b,v,i,u,s,k,j;

int clr[100],dis[100],p[100];
list<int>adj[100];

list<int>::iterator it;
queue<int> Q;


void bfs(int s)
{

    for(i=1; i<=v; i++)
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
        for(i=1; i<=v; i++)
        {
            for(it=adj[u].begin(); it!=adj[u].end(); it++)
            {


                if(  clr[*it]==0)
                {
                    clr[*it]=1;
                    dis[*it]=dis[u]+1;
                    p[*it]=u;
                    Q.push(*it);
                }
            }
            clr[u]=2;
        }

    }

    for(i=1; i<=v; i++)
    {
        cout<<"vertex :"<<i<<"      ";


    }
    cout<<endl;
    for(i=1; i<=v; i++)
    {
        cout<<"color: "<<clr[i]<<"      ";

    }
    cout<<endl;
    for(i=1; i<=v; i++)
    {
        cout<<"Prev: "<<p[i]<<"     ";


    }
    cout<<endl;

    for(i=1; i<=v; i++)
    {
        cout<<"Dis: "<<dis[i]<<"        ";

    }
}


int main()
{
    cout<<"Input Number of Vertex :";
    cin>>v;
    int x,y;
    while(1)
    {
        cout<<"Enter row and colom: ";
        cin>>x>>y;
        if(x==0 && y==0)
        {
            break;
        }
        else if( x<0||y<0 ||x>v || y>v )
        {

            cout<<"Invalid try again"<<endl;
        }

        else
        {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    for(int i=1; i<=v; i++)
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

    if(s>v || s<0)
    {
        cout<<"invalid try again"<<endl;
        goto ab;
    }
    bfs(s);
}

