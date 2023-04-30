# include <iostream>
# include <cstdio>
# include <queue>
# include <list>
using namespace std;
int clr[100];
int st[100];
int f[100];
int dis[100];
int pri[100];
list <int> adj[100];
list <int>:: iterator it;
int n, t;

void DFS_visit(int s){
    clr[s] = 1;
    t++;
    st[s] = t;
    for(int i = 1; i <= n; i++){
        if(clr[i] == 0){
            pri[i] = s;
            DFS_visit(i);
        }
    }
    clr[s] = 2;
    t++;
    f[s] = t;
}

void DFS(int s){

    for(int i = 1; i <= n; i++){
        clr[i] = 0;
        pri[i] = -1;
        st[i] = -1;
        f[i] = -1;
    }
    t = 0;
    for(int i = 1; i <= n; i++){
        if(clr[i] == 0){
            DFS_visit(i);
        }
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

    DFS(1);


}
