# include <iostream>
# include <cstdio>
# include <queue>
using namespace std;
int clr[100];
int st[100];
int f[100];
int dis[100];
int pri[100];
int adj[100][100] = {0};
int a, b, n, t, te, be, fe, ce;

void DFS_visit(int s){
    clr[s] = 1;
    t++;
    st[s] = t;
    for(int i = 1; i <= n; i++){
        if(clr[i] == 0 && adj[s][i] == 1){
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

void edge_count(){
    te = 0, be = 0, fe = 0, ce = 0;
    for(int u = 1; u <= n; u++){
        for(int v = 1; v <= n; v++){
            if(adj[u][v] == 1){
                if(st[u] < st[v] && f[u] > f[v] && st[u] < f[v]){
                    te++;
			cout<<"Tree Edge: "<<u<<"	"<<v<<endl;
                }
                else if(st[u] > st[v] && st[u] < f[v] && f[u] < f[v]){
                    be++;
			cout<<"Back Edge: "<<u<<"	"<<v<<endl;
                }
                else if(st[u] < st[v]){
                    fe++;
			cout<<"Forward Edge: "<<u<<"	"<<v<<endl;
                }
                else{
                    ce++;
			cout<<"Cross Edge: "<<u<<"	"<<v<<endl;
                }
            }
        }
    }
    printf("TREE  : %d\n", te);
    printf("BACK  : %d\n", be);
    printf("FORD  : %d\n", fe);
    printf("CROS  : %d\n", ce);

	if(be>0)
		cout<<"cycle"<<endl;
	else
		cout<<"not cycle"<<endl;
}

int main(){
    int k = 1, s;
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
            adj[a][b] = 1;
            k++;
        }
    }
    printf("The graph you entered:\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    DFS(1);

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

    printf("Discover :");
    for(int i = 1; i <= n; i++){
        printf(" %d", st[i]);
    }
    printf("\n");

    printf("Finish   :");
    for(int i = 1; i <= n; i++){
        printf(" %d", f[i]);
    }
    printf("\n");

    edge_count();

}

