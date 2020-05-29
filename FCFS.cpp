#include<bits/stdc++.h>
using namespace std;

#define pb push_back
struct block{
	int pid, a_tm, b_tm;
	//process id, arrival time, burst time
};
bool comp(block x, block y){
	return x.a_tm < y.a_tm;
}

int main(){
	int n; cin>>n;
	vector<block> proc;
	int st_tm[n+1]; //start time of all process
	int turn_time[n+1], wait_time[n+1];
	int arr_time[n+1], burst_time[n+1];

	for (int i=1; i<=n; i++){
		int a,b; cin>>a>>b;
		proc.pb({i,a,b});
		arr_time[i] = a, burst_time[i] = b;
	}

	sort(proc.begin(), proc.end(), comp);
	int sm=0; //stores the execution time upto ith process
	double avg_tt=0, avg_wt=0; //avg turnaround time //avg wait time

	//turnaround_time = st_time + burst_time - arrival_time
	//wait time = st_time - arrival_time
	for (auto [i,arr,bur]: proc){
		st_tm[i] = max(arr,sm);
		turn_time[i] = st_tm[i] + bur - arr;
		wait_time[i] = st_tm[i] - arr;
		sm = st_tm[i]+ bur;
		avg_tt+=turn_time[i];
		avg_wt+=wait_time[i];
	}
	avg_tt/=(n*1.0), avg_wt/=(n*1.0);
	cout<<endl;
	cout<<"PID ART BRT STR TUT WTT"<<endl;
	for (int i=1; i<=n; i++){
		cout<<i<<"   "<<arr_time[i]<<"   "<<burst_time[i]<<"   "<<st_tm[i]<<"   "
		<<turn_time[i]<<"   "<<wait_time[i]<<endl;
	}
	cout<<"Avg Wait Time: "<<avg_wt<<endl;
	cout<<"Avg Turnaround Time: "<<avg_tt<<endl;
}