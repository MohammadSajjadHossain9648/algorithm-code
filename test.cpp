#include <bits/stdc++.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
#include<queue>
using namespace std;

int number;
int discover[100];
int finish[100];
int previous[100];
int temp =1;
char color[100];
list < int >  store[100];


void dfs(int start)
{
    discover[start] = temp++;
    color[start] = 'g';
    list < int > :: iterator travarse;
    for (travarse = store[start].begin(); travarse != store[start].end(); travarse++)
    {
        if (color[*travarse] == 'w')
        {
            previous[*travarse] = start;
            dfs(*travarse);
        }
    }
    finish[start] = temp++;
    color[start] = 'b';
}

int main ()
{
    printf("Vertex: ");
    scanf("%d",&number);
    int edge = 1, from, too;
    for (int a=1; a<=number; a++)
    {
        color[a] = 'w';
        previous[a] = -1;
        discover[a] = -1;
        finish[a] = -1;
    }

    while (1)
    {
        printf("Input Edge %d: ",edge);
        scanf("%d%d",&from,&too);
        if (from == 0 && too == 0)
            break;
        else
        {
            if ((from > 0 && from <=number) && (from > 0 && from <=number))
            {
                store[from].push_back(too);
                edge++;
            }
            else
                printf("Invalid!!\n");
        }
    }

    for (int a=1; a<=number; a++)
    {
        if (color[a] == 'w')
            dfs(a);
    }

    for (int a=1; a<=number; a++)
        cout << "\t" << a;
    cout << endl;
    for (int a=1; a<=number; a++)
        cout << "\t" << discover[a];
    cout << endl;
    for (int a=1; a<=number; a++)
        cout << "\t" << finish[a];
    cout << endl;
    for (int a=1; a<=number; a++)
        cout << "\t" << previous[a];
    cout << endl;
}
