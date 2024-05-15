#include<iostream>
using namespace std;
int main(){
    int p;
    cout<<"enter the number of processes: ";
    cin>>p;
    int a[p];
    for(int i=0;i<p;i++){
        cout<<"enter the execution time for "<<i+1<<"th process: ";
        cin>>a[i];
    }
    int wt[p];
    for(int i=2;i<p;i++){
        wt[0]=0;
        wt[1]=a[0];
        wt[i]=a[i-1]+wt[i-1];
    }
    int tat[p];
    for(int i=0;i<p;i++){
        tat[i]=wt[i]+a[i];
    
    }
    cout<<"Number of processes\t\tExecution tme\t\tWaiting time\t\tTAT\n";
    for(int i=0;i<p;i++){
    cout<<i+1<<"\t\t\t"<<a[i]<<"\t\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i]<<"\n";}
    float sum1=0,sum2=0;
     for(int i=0;i<p;i++){
        sum1=wt[i]+sum1;
        sum2=tat[i]+sum2;
     }  
    
     cout<<"\nAverage Waiting Time : "<<sum1/p;
     cout<<"\nAverage TAT Time : \n"<<sum2/p;
    
}