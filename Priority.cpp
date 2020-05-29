#include<bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,pair<int,int> > &a, 
              const pair<int,pair<int,int> > &b) 
{ 
    return (a.second.second < b.second.second); 
}
int main()
 {
 	// freopen("input.txt", "r" , stdin);
  //   freopen("output.txt", "w", stdout);
 	vector<pair<int,pair<int,int>  > > v;
 	vector<pair<int,int> > wt,tt;

 	int n = 3;
 	v.push_back({3,{2,3}}), v.push_back({1,{4,1}}), v.push_back({2,{3,2}});
 	for(int i=1;i<=n;i++)
 		  {
 		  	// int bt,p;
 		  	// cin>>bt>>p;
 		  	// v.push_back(make_pair(i,make_pair(bt,p)));

 		  }


 		  sort(v.begin(),v.end(),sortbysec);
 		  int w=0;
 		  while(!v.empty())
 		  {
           
              wt.push_back(make_pair(v[0].first,w));
               tt.push_back(make_pair(v[0].first,v[0].second.first + w));
               w+=v[0].second.first;
               v.erase(v.begin());

 		  }
for(int i=0;i<wt.size();i++)
    	  {
             cout<<wt[i].first<<" "<<wt[i].second<<" "<<tt[i].second<<endl;

    	  }





}