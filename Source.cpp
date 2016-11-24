#include <omp.h>  // openmp header file
#include <stdio.h>
#include <iostream>
#include <math.h>
#define fin 10000000// 10 million

int prime = 2;


using namespace std;

bool is_prime(int n){
	int s = sqrt(n);
	for (int y = 3; (y <= s) ; y += 1){
		if (!(n%y)){
			 return false;
		}
	}



	return true;
}

void main()
{


	float time = omp_get_wtime();
#pragma omp parallel for num_threads(4)schedule  (static , 100)
	for (int x = 5; x <= fin; x += 2){
		if (is_prime(x)){
#pragma omp critical
{
	prime += 1;
}
		
		}
	}

	printf("%d ", prime);
	cout << endl << omp_get_wtime() - time;
	getchar();
	getchar();
	getchar();


}