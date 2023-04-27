# include <iostream>
# include <cstdio>
# include <queue>
# include <list>
using namespace std;
int clr[100];
int dis[100];
int pri[100];
list <int> adj[100];
list <int>:: iterator it;
int n;

void BFS(int s){
    for(int i = 1; i <= n; i++){
        clr[i] = 0;
        dis[i] = 200000;
        pri[i] = -1;
    }
    clr[s] = 1;
    dis[s] = 0;
    queue <int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(it = adj[u].begin(); it != adj[u].end(); it++){
            int i = *it;
            if(clr[i] == 0){
                clr[i] = 1;
                dis[i] = dis[u] + 1;
                pri[i] = u;
                q.push(i);
            }
        }
        clr[u] = 2;
    }

}

int main(){
    int k = 1, a, b, s;
    printf("Input the number of vertex: ");
    scanf("%d", &n);
    while(true){
        printf("Edge %d: ", k);
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0){
            break;
        }
        else if(a <= 0 || a > n || b <= 0 || b > n){
            printf("Invalid edge try again\n");
            continue;
        }
        else{
            adj[a].push_back(b);
            adj[b].push_back(a);
            k++;
        }
    }
    printf("The graph you entered:\n");
    for(int i = 1; i <= n; i++){
        printf("adj[%d]", i);
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            printf(" -> %d", *it);
        }
        printf("\n");
    }
    printf("Input source: ");
    scanf("%d", &s);
    if(s < 1 || s > n){
        printf("Invalid source");
    }
    else{
        BFS(s);
    }

    printf("Vertices :");
    for(int i = 1; i <= n; i++){
        printf(" %d", i);
    }
    printf("\n");

    printf("Color    :");
    for(int i = 1; i <= n; i++){
        printf(" %d", clr[i]);
    }
    printf("\n");

    printf("Distance :");
    for(int i = 1; i <= n; i++){
        printf(" %d", dis[i]);
    }
    printf("\n");

    printf("Pri      :");
    for(int i = 1; i <= n; i++){
        printf(" %d", pri[i]);
    }
    printf("\n");

}
