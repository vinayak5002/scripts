
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;

    for(int I=1; I<=T; I++){
        int n, m, total = 0;
        cin>>n>>m;

        int c[n];
        for(int i=0; i<n; i++){
            cin>>c[i];
            total += c[i];
        }

        int ans = total % m;
        cout<<total<<endl;

        cout<<"Case #"<<I<<": "<<ans<<endl;

    }

    return 0;
}