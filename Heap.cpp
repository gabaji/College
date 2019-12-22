//I know it's trash code. I'm learning myself. Will update shortly!


#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int len,x,a[20];
    float n;
    int root;
    cout<<"Length"<<endl;
    cin>>len;
    for(int i=0;i<len;++i)
    {
        n=i;
        n=n/2;
        cin>>x;
        a[i]=x;
        root=ceil(n)-1;
        x=i;
        //cout<<"root is "<<root<<endl;
        while(root>-1)
        {

            if(a[root]<a[x])
            {
                swap(a[root],a[x]);
                n=root;
                x=root;
                n=n/2;
                root=ceil(n)-1;
            }
            else
                goto x;
        }
        x:
        continue;

    }
    cout<<endl<<"Heapified array "<<endl;
    for(int i=0;i<len;++i)
            cout<<a[i]<<" ";


    return 0;


}
