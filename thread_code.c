#include<stdio.h>
#include<pthread.h>

int print(int i)
{
	int j;
	if(i == 2)
		j=25000;
	else
		j=i+25000;
	
	int a,b,count1=0;;
	for(a=i; a<=j; a++){
		int count=0;
		for(b=2; b<a; b++){
			if(a%b == 0){
				count++;
				break;
			}	
		}
		if(count == 0)
			count1++;
	}

	return count1;
}
int main()
{
	
	pthread_t show1,show2,show3,show4;

	pthread_create(&show1, NULL, print, 2);
	pthread_create(&show2, NULL, print, 25001);
	pthread_create(&show3, NULL, print, 50001);
	pthread_create(&show4, NULL, print, 75001);

	int *a;
	pthread_join(show1, &a);
	printf("\ntotal prime number in range(2-25000) : %d\n", a);
	pthread_join(show2, &a);
	printf("\ntotal prime number in range(25001-50000) : %d\n", a);
	pthread_join(show3, &a);
	printf("\ntotal prime number in range(50001-75000) : %d\n", a);
	pthread_join(show4, &a);
	printf("\ntotal prime number in range(75001-100000) : %d\n", a);

	return 0;
}
