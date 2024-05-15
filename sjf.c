#include<stdio.h>
int main(){
    int p,min,temp;
    printf("enter the number of processes: ");
    scanf("%d",&p);
    int a[p],b[p];
    for(int i=0;i<p;i++){
        printf("Enter the execution time for process %d ",i+1);
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    for(int i=0;i<p;i++){
        min=i;
        for(int j=i+1;j<p;j++){
            if(b[j]<b[min]){

                min=j;
            }
        }
        if(min!=i){
            temp=b[min];
            b[min]=b[i];
            b[i]=temp;
        }
    }
    for(int i=0;i<p;i++){
        printf("\t%d",b[i]);
    }
    printf("\n");
    int wt[p];
    for(int i=2;i<p;i++){
        wt[0]=0;
        wt[1]=b[0];
        wt[i]=b[i-1]+wt[i-1];

    }
    int tat[p];
    for(int i=0;i<p;i++){
        tat[i]=wt[i]+b[i];
    }
    printf("Number of processes\t\tExecution tme\t\tWaiting time\t\tTAT\n");
    for(int i=0;i<p;i++){
        printf("|%d\t\t\t\t|%d\t\t\t\t|%d\t\t\t\t|%d|\n",i+1,b[i],wt[i],tat[i]);

    }
    float sum1=0,sum2=0;
    for(int i=0;i<p;i++){
        sum1=wt[i]+sum1;
        sum2=tat[i]+sum2;}
        int awt=sum1/p;
        int att=sum2/p;
        printf("\nAverage waiting time: %d",awt);
        printf("\nAverage TAT: %d\n",att);
        return 0;
}