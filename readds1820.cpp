#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "readds1820.h"
using namespace std;

int getTemp(double &temperaturepointer)
{
    int i = 0;
    fstream f;
    char cstring[256];
    char check[265];
    char value[256];
    f.open("/sys/bus/w1/devices/28-031644c493ff/w1_slave", ios::in);
	if (f.is_open()){
    	while (!f.eof())
    	{
       	 f.getline(cstring,sizeof(cstring));
       	 if (i==0)
       	     strncpy(check,cstring,sizeof(check));
       	 if (i==1)
       	     strncpy(value,cstring,sizeof(value));
       	 i++;
    	}
	}
	else
		return 1;
    f.close();
    char * pos;
    pos=strchr(check,'N');
    if(pos!=NULL){
        cout<<"Error! CRC check failed!"<<endl;
        return 1;
    }
    pos=strtok(value, "=");
    i=0;
    char temp[10];
    while(pos!=NULL){
        if (i==1)
            strncpy(temp,pos,sizeof(temp));
        pos=strtok(NULL,"=");
        i++;
    }
    temp[3]='\0';
    double temperature = atof(temp);
	temperature/=10;
    temperaturepointer=temperature;
	return 0;
}

