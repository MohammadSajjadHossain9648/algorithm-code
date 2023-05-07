#include<iostream>
#include<cstdio>
#include<list>
using namespace std;
int main()
{
    list<int> graph[100];
    //list<int>::iterator it;
    int outdegree[100] = {0}, indegree[100] = {0};
    cout<<"Input Number of Vertex: ";
    int ver;
    cin>>ver;
    int edge = 1;
    while(1)
    {
        cout<<"Edge "<<edge<<": ";
        int x, y;
        cin>>x>>y;
        if( x == 0 && y == 0)
        {
            break;
            //cout<<"Invalid Input Try Again"<<"\n";
        }
        else if(x <= 0 || y <= 0 || x > ver || y > ver)
        {
             cout<<"Invalid Input Try Again\n";
        }
        else
        {
            graph[x].push_back(y);
            ///graph[y].push_back(x);
            edge++;
        }
    }
    bool self_loop = 0;
    int max_indegeee = 0;
    int max_outdegeee = 0;
    for(int i = 1; i<= ver ; i++)
    {
        printf("Graph[%d]", i);
        //int counter = 0;
        for(list<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
        {
            cout<<"->"<<*it;
            outdegree[i]++;
            indegree[*it]++;
            if(indegree[*it] > max_indegeee)
            {
                max_indegeee = indegree[*it];
            }
            if(i == *it)
            {
                self_loop = 1;
            }
        }
        if(outdegree[i] > max_outdegeee)
        {
            max_outdegeee = outdegree[i];
        }
        //outdegree[i] = counter;
        cout<<"\n";
    }
    if(self_loop == true)
    {
        cout<<"The graph contains self loop\n";
    }
    else
    {
        cout<<"The following graph does not contain any self-loops\n";
    }
    printf("Maximum Indegree is : %d and maximum outdegree is : %d\n", max_indegeee, max_outdegeee);
    for(int i=1; i<= ver ; i++)
    {
        printf("%d : Outdegree : %d and the Indegree : %d\n", i, outdegree[i], indegree[i]);
    }
    cout<<"These vertices have the highest outdegree: ";
    for(int i=1; i<= ver ; i++)
    {
        if(outdegree[i] == max_outdegeee)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\nThese vertices have the highest indegree: ";
    for(int i=1; i<= ver ; i++)
    {
        if(indegree[i] == max_indegeee)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n";

    cout<<"These vertices have the odd outdegree: ";
    for(int i=1; i<= ver ; i++)
    {
        if(outdegree[i] % 2 == 1)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\nThese vertices have the even indegree: ";
    for(int i=1; i<= ver ; i++)
    {
        if(indegree[i] % 2 == 0)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    bool universal_sink = 0;
    for(int i =1; i<= ver; i++)
    {
        if(outdegree[i] == 0)
        {
            if(indegree[i] == ver - 1 )
            {
                universal_sink = 1;
            }
        }
    }
    if(universal_sink == true)
    {
        cout<<"The graph contains universal sink\n";
    }
    else
    {
        cout<<"The following graph does not contain any universal sink\n";
    }
}
