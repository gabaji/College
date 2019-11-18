#include<iostream>
#include<vector>
int main()
{
    using namespace std;
    int a[5] = {1,2,3,4,5};
    vector<int> please (a,a+sizeof(a)/sizeof(a[0]));

    vector<int>::iterator i = please.begin();
    for(;i<please.end();i++)
        cout<<*i<<" ";
    return 0;
}
