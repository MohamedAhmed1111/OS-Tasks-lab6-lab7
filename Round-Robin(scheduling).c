#include <stdio.h>
 
int main()
{
   int i, total = 0, x=4, limit=4, counter = 0, t_quantum = 10;
   int wait_time = 0, turnaround_time = 0, arrival_time[4]={0,3,4,9}, burst_time[4]= {60,30,40,10}, temp[4]={60,30,40,10};
 
   float average_wait_time, average_turnaround_time;
 
   printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
   for (total = 0, i = 0; x != 0;)
   {
      if (temp[i] <= t_quantum && temp[i] > 0)
      {
         total = total + temp[i];
         temp[i] = 0;
         counter = 1;
      }
      else if (temp[i] > 0)
      {
         temp[i] = temp[i] - t_quantum;
         total = total + t_quantum;
      }
 
      if (temp[i] == 0 && counter == 1)
      {
         x--;
         printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
 
         wait_time = wait_time + total - arrival_time[i] - burst_time[i];
 
         turnaround_time = turnaround_time + total - arrival_time[i];
         counter = 0;
      }
 
      if (i == limit - 1)
      {
         i = 0;
      }
      else if (arrival_time[i + 1] <= total)
      {
         i++;
      }
      else
      {
         i = 0;
      }
   }
 
   average_wait_time = wait_time *1.0 / limit;
   average_turnaround_time = turnaround_time *1.0 / limit;
 
   printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
   printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
 
   return 0;
}
