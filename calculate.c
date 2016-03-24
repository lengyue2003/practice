/*	this is a simple calculator.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define LINEMAX 100
int main()
{
	char buffer[LINEMAX];
	char*buffer_p=NULL;
	char endstr[]="quit\n";
	char operation;
	char translate[LINEMAX];
	double result=0.0;
	double choice=0.0;
	memset(buffer,0,LINEMAX);
	while(1){
		if(!strcmp(fgets(buffer,LINEMAX,stdin),endstr))
			break;
		buffer[strlen(buffer)-1]='\0';
		int i,j;
		for(i=0,j=0;buffer[i]!='\0';i++){
			if(buffer[i]==' ')
				continue;
			buffer[j++]=buffer[i];
		}
		buffer[j]='\0';
		buffer_p=buffer;
		if(*buffer_p=='=')
			buffer_p++;
		else{
			int i=0;
			i=0;
			while(isdigit(*buffer_p))
				translate[i++]=*buffer_p++;
			if(*buffer_p=='.'){
				translate[i++]=*buffer_p++;
				while(isdigit(*buffer_p))
					translate[i++]=*buffer_p++;
			}
			translate[i]='\0';
			result=atof(translate);
		}
		while(*buffer_p){
				int i=0;
				operation=*buffer_p++;
				i=0;
				while(isdigit(*buffer_p))
					translate[i++]=*buffer_p++;
				if(*buffer_p=='.'){
					translate[i++]=*buffer_p++;
					while(isdigit(*buffer_p))
						translate[i++]=*buffer_p++;
				}
				translate[i]='\0';
				choice=atof(translate);
			switch(operation){
			case '+':result+=choice;break;
			case '-':result-=choice;break;
			case '*':result*=choice;break;
			case '/':if(choice==0)
					printf("Division by zore error");
				 else
					result/=choice;
				 break;
			case '^':result=pow(result,choice);break;
			default:printf("Illegal operation!");break;
			}
			}
		printf("= %f\n",result);
		}	
	return 0;
}
