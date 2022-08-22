#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> adj[100];
    list<int>::iterator it;

    int x,sum[100]= {0},max=0,max1=0,a,b;
    cout<<"input the vertix :\n";
    cin>>x;

    int i=1,j=1,k=1,s=0;

    while(i!=0&&j!=0)
    {
        cout<<"edge "<<k<<": \n";
        cin>>i>>j;

        if(i<=x&&j<=x)
        {
            adj[i].push_back(j);
            adj[j].push_back(i);
            k++;
        }
        else if(i==0||j==0)
        {
            break;
        }
        else
            cout<<"wrong input\n";
    }

    for(int i=1; i<=x; i++)
    {
        cout<<"adj["<<i<<"]";
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {
            cout<<"-->"<<*it;


            }
    cout<<"\n";
}
for(int i=1; i<=x; i++){
    sum[i]=0;
}
for(int i=1; i<=x; i++)
    {
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {
                if(*it==1)
                    sum[a]=sum[a]+1;
                else if(*it==1)
                    sum[a]=sum[a]+1;
                else if(*it==1)
                    sum[a]=sum[a]+1;
                else if(*it==1)
                    sum[a]=sum[a]+1;
                else if(*it==1)
                    sum[a]=sum[a]+1;

            }
    cout<<"\n";
}
 for(int i=1; i<=x; i++){
    cout<<"indegree of node "<<i<<": "<<sum[i]<<"\n";
 }


}
