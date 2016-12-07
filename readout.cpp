#include <stdio.h>
#include "readds1820.h"

int main(){
	double value;
	double *temp;
	temp=&value;
	if (getTemp(*temp)!=0)
		return 1;
	printf("%1.2f\n", *temp);
	return 0;
}
