//Memory-Management-Simulator---First-Fit-Algorithm
//Simulator for the memory management portion of an operating system with fixed partition scheme using first-fit algorithm


/*
Memory: 32 KB
Scheme: Fixed
Algorithm: First-Fit 
No. of Partitions: 
                    Partition 1: 4 KB
                    Partition 1: 4 KB
                    Partition 1: 8 KB
                    Partition 1: 16 KB
*/

#include <stdio.h>

int main(void){
	int SIZE = 100;
	int total_time_m3p2 = 0;
	int m3p2_exe = 0;
	int m3p2_not_exe = 0;
	
	int jobs[SIZE][2];
	int i, j;
	for(i = 0; i < SIZE; i++){
		jobs[i][0] = rand()%15+2;
		jobs[i][1] = rand()%20+1;
	}
	
	
	int m3p2[4][2];
	m3p2[0][0] = 0;
	m3p2[0][1] = 4;
	m3p2[1][0] = 0;
	m3p2[1][1] = 4;
	m3p2[2][0] = 0;
	m3p2[2][1] = 8;
	m3p2[3][0] = 0;
	m3p2[3][1] = 16;
	int k;
	for(i = 0; i < SIZE; i++){
		if(jobs[i][1] > 16){
			m3p2_not_exe++;
		}
		else if(jobs[i][1] > 8 && jobs[i][1] <= 16){
			m3p2[3][0] = jobs[i][0];
			m3p2_exe++;
			total_time_m3p2 += jobs[i][0];
		}
		else if(jobs[i][1] > 4 && jobs[i][1] <= 8){
			if(m3p2[2][0] <= m3p2[3][0]){
				m3p2[2][0] = jobs[i][0];
				m3p2_exe++;
				total_time_m3p2 += jobs[i][0];
			}
			else{
				m3p2[3][0] = jobs[i][0];
				m3p2_exe++;
				total_time_m3p2 += jobs[i][0];
			}
		}
		else{
			k = small(m3p2[0][0], m3p2[1][0], m3p2[2][0], m3p2[3][0]);
			m3p2[k][0] = jobs[i][0];
			m3p2_exe++;
			total_time_m3p2 += jobs[i][0];
		}
	}
	
	printf("Number of jobs executed: %d\n", m3p2_exe);
	printf("Number of jobs not executed: %d\n", m3p2_not_exe);
	printf("Total time of execution: %d\n", total_time_m3p2);
	return 0;
}

int small(int a, int b, int c, int d){
	int arr[4];
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	int temp = 0;
	int i, j;
        
        for(i = 0; i < 4; i++){
            for(j = 0; j < 3; j++){
                if(arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
       if(arr[0] == a){
       	return 0;
       }
       else if(arr[0] == b){
       	return 1;
       } 
       else if(arr[0] == c){
       	return 2;
       }
       else if(arr[0] == d){
       	return 3;
       }
}
