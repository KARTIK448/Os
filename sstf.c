#include<stdio.h>
#include<stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMovement = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    
    // logic for SSTF disk scheduling
    printf("Seek Sequence: %d", initial); // Print initial head position
    while(count != n) {
        int min = 1000, d, index;
        for(i = 0; i < n; i++) {
            d = abs(RQ[i] - initial);
            if(min > d) {
                min = d;
                index = i;
            }
        }
        TotalHeadMovement += min;
        printf(" -> %d", RQ[index]); // Print the serviced request
        initial = RQ[index];
        RQ[index] = 1000; // Mark the serviced request as visited
        count++;
    }
    
    printf("\nTotal head movement is %d\n", TotalHeadMovement);
    return 0;
}
