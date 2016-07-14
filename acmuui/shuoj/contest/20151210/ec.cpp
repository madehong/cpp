#include<bits/stdc++.h>
using namespace std;
int a[100];
int f=0;
int x,y,z;

set< pair<pair<int,int>,int> > s;

int dfs(int i,int j,int k)
{

    pair<pair<int,int>,int> q=make_pair(make_pair(i,j),k);
    if(!s.count(q))
    {
        if(i==0)a[f++]=k;
        s.insert(q);
    }
    else return 0;
    if(k>=y-j)dfs(i,y,k-(y-j));
    else dfs(i,j+k,0);
    if(k>=x-i)dfs(x,y,k-(x-i));
    else dfs(i+k,j,0);
    if(i>=y-j)dfs(i-(y-j),y,k);
    else dfs(0,j+i,k);
    if(i>=z-k)dfs(i-(z-k),j,z);
    else dfs(0,j,k+i);
    if(j>=z-k)dfs(i,j-(z-k),z);
    else dfs(i,0,k+j);
    if(j>=x-i)dfs(x,j-(x-i),k);
    else dfs(i+j,0,k);
}

int main()
{

    while(cin>>x>>y>>z)
    {
        for(int i  =0;i<10;i++){
            for(int j = 0;j<10;j++){
                    x = i;y = j;
                    cout<<i<<" "<<j<<"%";
                 s.clear();
        memset(a,0,sizeof(a));
        dfs(0,0,z);
        sort(a,a+f);
        f=unique(a,a+f)-a;

        for(int i=0;i<f-1;++i)if(a[i]!=0)cout<<a[i]<<' ';
        cout<<a[f-1]<<endl;
            }

        }

    }
    return 0;
}/*
*1 1 10
0 0%10
0 1%9 10
0 2%8 10
0 3%7 10
0 4%6 10
0 5%5 10
0 6%4 10
0 7%3 10
0 8%2 10
0 9%1 10
1 0%10
1 1%9 10
1 2%8 9 10
1 3%7 8 9 10
1 4%6 7 8 9 10
1 5%5 6 7 8 9 10
1 6%4 5 6 7 8 9 10
1 7%3 4 5 6 7 8 9 10
1 8%2 3 4 5 6 7 8 9 10
1 9%1 2 3 4 5 6 7 8 9 10
2 0%10
2 1%9 10
2 2%8 10
2 3%7 8 9 10
2 4%6 8 10
2 5%5 6 7 8 9 10
2 6%4 6 8 10
2 7%3 5 6 7 8 9 10
2 8%2 4 6 8 10
2 9%1 2 3 4 5 6 7 8 9 10
3 0%10
3 1%9 10
3 2%8 9 10
3 3%7 10
3 4%6 7 9 10
3 5%5 7 8 10
3 6%4 7 10
3 7%3 4 6 7 9 10
3 8%2 3 4 5 6 7 8 9 10
3 9%1 3 4 6 7 9 10
4 0%10
4 1%9 10
4 2%8 10
4 3%7 9 10
4 4%6 10
4 5%5 6 9 10
4 6%4 6 8 10
4 7%3 4 5 6 7 8 9 10
4 8%2 4 6 8 10
4 9%1 2 4 5 6 8 9 10
5 0%10
5 1%9 10
5 2%8 9 10
5 3%7 8 10
5 4%6 9 10
5 5%5 10
5 6%4 5 6 7 9 10
5 7%3 4 5 7 8 9 10
5 8%2 3 5 7 8 10
5 9%1 4 5 6 9 10
6 0%10
6 1%9 10
6 2%8 10
6 3%7 10
6 4%6 8 10
6 5%5 6 7 9 10
6 6%4 6 10
6 7%3 4 6 7 8 9 10
6 8%2 4 6 8 10
6 9%1 3 4 6 7 9 10
7 0%10
7 1%9 10
7 2%8 9 10
7 3%7 9 10
7 4%6 7 8 9 10
7 5%5 7 8 9 10
7 6%4 6 7 8 9 10
7 7%3 7 10
7 8%2 3 7 8 9 10
7 9%1 2 3 7 8 9 10
8 0%10
8 1%9 10
8 2%8 10
8 3%7 8 9 10
8 4%6 8 10
8 5%5 7 8 10
8 6%4 6 8 10
8 7%3 7 8 9 10
8 8%2 8 10
8 9%1 2 8 9 10
9 0%10
9 1%9 10
9 2%8 9 10
9 3%7 9 10
9 4%6 8 9 10
9 5%5 6 9 10
9 6%4 6 7 9 10
9 7%3 7 8 9 10
9 8%2 8 9 10
9 9%1 9 10


*/