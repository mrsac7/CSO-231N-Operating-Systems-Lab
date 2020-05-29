#include<bits/stdc++.h>
using namespace std;

#define pb push_back
struct block{
	int pid, a_tm, b_tm;
	//process id, arrival time, burst time
};

int main(){
	int n; cin>>n;
	int turn_tm[n+1], wait_tm[n+1];
	int arr_tm[n+1], bur_tm[n+1], rem_tm[n+1], fin_tm[n+1];

	double avg_tt=0, avg_wt=0; //avg turnaround time //avg wait time

	for (auto i=1;i<=n; i++){
		int a,b; cin>>a>>b;
		arr_tm[i] = a, bur_tm[i] = b, rem_tm[i] = b;
	}
	int p = 0, t = 1;
	while(p<n){
		//arr_tm is geq t and && rem_tm is min >0
		int mn = INT_MAX, id = -1;
		for (int i=1;i<=n; i++){
			if (arr_tm[i]<=t && rem_tm[i]<mn && rem_tm[i]>0){
				mn = rem_tm[i];
				id = i;
			}
		}
		t++;
		if (id==-1) continue;
		rem_tm[id]--;
		if (rem_tm[id] == 0){
			p++;
			fin_tm[id] = t;
			wait_tm[id] = fin_tm[id] - bur_tm[id] - arr_tm[id];
			turn_tm[id] = wait_tm[id] + bur_tm[id];
			avg_wt+= wait_tm[id];
			avg_tt+= turn_tm[id];
		}
	}
	avg_tt/= (n*1.0), avg_wt/= (n*1.0);
	cout<<endl;
	cout<<"PID ART BRT TUT WTT"<<endl;
	for (int i=1; i<=n; i++){
		cout<<i<<"   "<<arr_tm[i]<<"   "<<bur_tm[i]<<"   "
		<<turn_tm[i]<<"   "<<wait_tm[i]<<endl;
	}
	cout<<"Avg Wait Time: "<<avg_wt<<endl;
	cout<<"Avg Turnaround Time: "<<avg_tt<<endl;
}