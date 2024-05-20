#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i, j, n, pid[10], at[10], bt[10], time = 0, tsum = 0, wsum = 0, over = 0, start, t;
    float awt = 0, atat;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("PID: ");
        scanf("%d", &pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sorting based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&pid[j], &pid[j + 1]);
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    while (over < n) {
        int count = 0;
        for (i = over; i < n; i++) {
            if (at[i] <= time) {
                count++;
            } else {
                break;
            }
        }

        if (count > 1) {
            for (i = over; i < over + count; i++) {
                for (j = i + 1; j < over + count; j++) {
                    if (bt[i] > bt[j]) {
                        swap(&pid[i], &pid[j]);
                        swap(&at[i], &at[j]);
                        swap(&bt[i], &bt[j]);
                    }
                }
            }
        }

        start = time;
        time += bt[over];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[over], at[over], bt[over], time, (time - at[over]) - bt[over], time - at[over]);
        tsum += (time - at[over]);
        wsum += ((time - at[over]) - bt[over]);
        over++;
    }

    awt = (float)wsum / n;
    atat = (float)tsum / n;

    printf("Average Waiting time=%f\n", awt);
    printf("Average turnaround time=%f\n", atat);

    return 0;
}