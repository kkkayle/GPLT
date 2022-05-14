#include <bits/stdc++.h>
using namespace std;
queue<int>que;
stack<int>sta;
void print(vector<int>arr)
{
    for(auto i=arr.begin();i<arr.end();i++)
    {
        cout<<*i;
        if(i!=arr.end()-1)
        {
            cout<<' ';
        }
        else
        {
            cout<<endl;
        }
    }
}
int main()//不满足要求的条件 盒子满了 推送器的大于枝干的 
{          //推送器空了 盒子的大于枝干的  先盒子后推送器
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        que.push(temp);
    }
    
    while(1)
    {
        vector<int>arr;
        int count=0;
        while(count<=k)
        {
            if(count==0)//插第一个树干的情况
            {
                if(que.empty()&&sta.empty())
                {
                    return 0;
                }
                if(!sta.empty())//盒子不空就先拿盒子 不然就拿推送器
                {
                    arr.push_back(sta.top());
                    sta.pop();
                }
                else
                {
                    arr.push_back(que.front());
                    que.pop();
                }
                count++;
            }
            else
            {
                if(que.empty()&&sta.empty()&&!arr.empty())
                {
                    print(arr);
                    return 0;
                }
                if(!que.empty()&&sta.size()==m&&que.front()>arr.back())
                {
                    print(arr);
                    break;
                }
                else if(!sta.empty()&&sta.top()>arr.back()&&que.empty())
                {
                    print(arr);
                    break;
                }
                else if(arr.size()==k)
                {
                    print(arr);
                    break;
                }
                if(!sta.empty()&&sta.top()<=arr.back())
                {
                    arr.push_back(sta.top());
                    sta.pop();
                }
                else if(!que.empty()&&que.front()<=arr.back())
                {
                    arr.push_back(que.front());
                    que.pop();
                }
                else
                {
                    sta.push(que.front());
                    que.pop();
                }
            }
        }
    }
}