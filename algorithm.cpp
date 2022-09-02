#include<iostream>
#include<string>
using namespace std;

int main()
{
    int x,arr[100][100],sum[100]= {0},sum1[100]= {0},max=0,max1=0;
    string a;
    cout<<"input the vertix :\n";
    cin>>x;

    int i=1,j=1,k=1;

    while(i!=0&&j!=0)
    {
        cout<<"edge "<<k<<": \n";
        cin>>i>>j;

        if(i<=x&&j<=x)
        {
            arr[i][j]=1;
            arr[j][i]=1;
            k++;
        }
        else if(i==0&&j==0)
        {
            break;
        }
        else
            cout<<"wrong input\n";

    }

    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=x; j++)
        {
            cout<<arr[i][j]<<"\t";
            sum[i]=sum[i]+arr[i][j];
            sum1[j]=sum1[j]+arr[j][i];
        }
        cout<<"\n";
    }

    while(i==j){
        cout<<"\nit is a self loop graph\n";
                break;
    }

    //sum of row
    for(int i=1; i<=x; i++)
    {
        cout<<"\nsum of row "<<i<<": "<<sum[i];
        if(max<sum[i])
            max=sum[i];
    }
    cout<<"\nmax outdegree :"<<max<<"\n";
    for(int i=1;i<=x;i++){
            if(max=sum[i]){
                //problem of column no.
                cout<<"\nmax row no.: ";
                cout<<i;
            }
    }

    //sum of column
    for(int j=1; j<=x; j++)
    {
        cout<<"\nsum of column "<<j<<": "<<sum1[j];
        if(max1<sum1[j])
            max1=sum1[j];
    }
    cout<<"\nmax indegree :"<<max1<<"\n";
    for(int j=1; j<=x; j++)
    {
        if(max1=sum1[j])
        {
            //problem of column no.
            cout<<"\nmax column no.: ";
            cout<<j;
        }
    }

    return 0;
}
