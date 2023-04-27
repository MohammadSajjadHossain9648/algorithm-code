#include<iostream> 
#include<queue>

using namespace std ; 

int n,k=1,m[100][100],c[100],d[100],p[100],a,b,s_node,even[100],odd[100],e=0,o=0 ; 

void bfs(int s)
{
	int u ,i,j; 
	queue<int> Q ; 
	Q.push(s) ; 

	for(i=1 ; i<= n ; i++)
	{
		c[i] = 1 ; 
		d[i] = 10000000 ; 
		p[i] = -1 ;
	}

	c[s] = 2 ; 
	d[s] = 0 ; 
	
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for( i=1 ; i<=n ; i++ )
		{
			if(m[u][i] == 1 && c[i] == 1)
			{
				c[i] = 2 ; 
				d[i] = d[u] + 1 ; 
				p[i] = u ; 
				Q.push(i) ; 
			}
			c[u] = 3 ;
		}
	
	}
	
}

void print(int s)
{
	cout << "source node : " << s<<endl ; 
	int i , j ; 

	cout << "node :\t\t" ;
	for( i=1 ; i<=n ; i++)
		cout << "\t" << i  ;
	cout << endl ; 

	cout << "color :\t\t";
	for( i=1 ; i<=n ; i++)
		cout << "\t" << c[i] ;   
	cout << endl ; 

	cout << "distance :\t";
	for( i=1 ; i<=n ; i++)
		cout << "\t" << d[i] ;   
	cout << endl ;

	cout << "previous node :\t";
	for( i=1 ; i<=n ; i++)
		cout << "\t" << p[i] ;   
	cout << endl ;  
}
	
void check_connected()
{
	for(int i=1; i<=n; i++)
	{ 
		if(c[i]<=2)
		{
			cout << "graph is not connected " << endl ; 
			return ; 
		}
	}
	
	cout << "graph is connected " << endl;  
}

void distance()
{
	int max=0 ; 
	for(int i=1; i<=n; i++)
	{
		if(d[i]>max)
			max = d[i] ; 	
	}
	
	cout << "maximum distanced nodes :\t " ;

	for(int i=1 ; i<=n ; i++)
	{
		if(d[i] == max )
			cout << i << "\t" ; 
	}
	cout << endl ; 
	return ; 
}

void even_odd_node()
{
	for(int i=1 ; i<=n ; i++)
	{
		if(d[i]%2==0)
		{
			even[e] = i ; 
			e++ ; 
		}
		else
		{
			odd[o] = i ; 
			o++ ; 
		}
	}
return ; 
}

void e_o_print() 
{
	cout << "even distaced nodes : ";
	for(int i=0 ; i<e ; i++)
		cout << even[i] << "\t" ; 
	cout << endl ;

	cout << "odd distaced nodes : ";
	for(int i=0 ; i<o ; i++)
		cout << odd[i] << "\t" ; 
	cout << endl ; 
return ; 
}

void check_bip()
{
	even_odd_node() ;

	for( int i=0 ; i<e ; i++ )
	{
		for(int j=1 ; j<= n ; j++ )
		{
			if(m[even[i]][j]==1  && d[j]%2==0)
			{
				cout << "graph is not bipartite " << endl ; 
				return ; 
			}
		}
	}

	cout << "graph is bipartite " << endl ; 
return ; 
		
}

void cehck_dominate()
{
	int  degree[100],max_degree ;
	max_degree = 0 ;
	for( int i=1 ; i<=n ; i++ )
	{
		degree[i] = 0 ; 
		for( int j=1 ; j<=n ; j++ )
		{
			if(m[i][j] == 1)
				degree[i] ++ ; 
		}
		if( degree[i]>max_degree )
			max_degree = degree[i] ; 
	}
	
	cout << "powerfull nodes : " ;	

	for( int i=1 ; i<=n ; i++ )
	{
		if(degree[i] == max_degree)
			cout << i << "\t" ; 
	}
	cout << endl ; 
	cout << "max d : " <<  max_degree << endl ; 
	cout << "1 :" << degree[1] ; 
return ; 
}
		

int main()
{
	
	cout << "enter the number of vetex : ";
	cin >> n ; 

	while(1)
	{
		cout << "Edge " << k << " : " ; 
		cin >> a ; 
		cin >> b ; 
		
		if(a==0 || b==0 )
			break ; 

		if(a > n || b > n )
			cout << "invalid number "<<endl ; 

		else
		{	
			m[a][b] = 1 ;
			m[b][a] = 1 ;
		
		k++ ; 
		}
	}

	cout<< endl<< "adjacency matrix " << endl ; 

	for(int i=1; i<=n ; i++)
	{
		for(int j=1; j<=n ; j++)
			cout << m[i][j] << "\t";

 		cout << endl ; 
	}
	
	cout << "enter source node : " ; 
	cin >> s_node ;
	while(s_node<=0 && s_node>n) 
	{
		cout << "invalid " << endl ; 
		cin >> s_node ; 
	}

	bfs(s_node) ;
	print(s_node) ; 
	check_connected() ; 
	check_bip() ; 
	e_o_print() ; 
	distance() ; 
	cehck_dominate() ; 

	return 0 ; 
}
