/*
    c program to implement FCFS scheduling without Arrival time

    Enter the burst time of the process : 3 10 4 6
    Process  Burst Time      Waiting Time    Turn Around Time
    1             3               0               3
    2             10              3               13
    3             4               13              17
    4             6               17              23
    Avarage Waiting Time = 8.250000
    Avarage Turn Around Time = 14.000000
*/

#include <stdio.h>
#include <conio.h>
#define max 30

void main() {
    int i,j,n,bt[max],wt[max],tat[max];
    float awt = 0, atat = 0;
    // clrscr();

    printf("Enter the number of process : ");
    scanf("%d", &n);

    printf("Enter the burst time of the process : ");
    for(i=0; i<n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Process\t Burst Time\t Waiting Time\t Turn Around Time\n");
    for(i=0; i<n; i++) {
        wt[i] = 0;
        tat[i] = 0;

        for(j=0; j<i; j++){
            wt[i] = wt[i] + bt[j];
        }

        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    awt = awt/n;
    atat = atat/n;
    printf("Avarage Waiting Time = %f\n", awt);
    printf("Avarage Turn Around Time = %f\n", atat);
    getch();

}
