/*record the system time in the file*/
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
struct time_record{
	int index;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};                                                                            
int main(int argc,char*argv[])
{
	char filename[]="/home/zhao/practice/text";
	FILE *pfile=NULL;
	struct time_record *storage=NULL; 
	int temp_index=1;
	time_t system_time=0;
	struct tm*ptime=NULL;
	int count=0;
	while(1){
		time(&system_time);
		ptime=localtime(&system_time);
		storage=(struct time_record*)calloc(1,
			sizeof(struct time_record));
		if((pfile=fopen(filename,"r+"))==NULL){	/*first record*/
			if((pfile=fopen(filename,"w"))==NULL){
				fprintf(stderr,"%s error open",filename);
				exit(1);
			}
			storage->index=1;
			storage->year=ptime->tm_year+1900;
			storage->month=ptime->tm_mon+1;
			storage->day=ptime->tm_mday;
			storage->hour=ptime->tm_hour;
			storage->minute=ptime->tm_min;
			storage->second=ptime->tm_sec;
			fwrite(storage,sizeof(struct time_record),1,pfile);
			fclose(pfile);
			free(storage);
			storage=NULL;
			count++;
		}
		else{					/*other record*/
			storage=(struct time_record*)calloc(1,
				sizeof(struct time_record));
			fseek(pfile,-sizeof(struct time_record),SEEK_END);
			fread(storage,sizeof(struct time_record),1,pfile);
			temp_index=storage->index+1;
			storage->index=temp_index;
			storage->year=ptime->tm_year+1900;
			storage->month=ptime->tm_mon+1;
			storage->day=ptime->tm_mday;
			storage->hour=ptime->tm_hour;
			storage->minute=ptime->tm_min;
			storage->second=ptime->tm_sec;
			fwrite(storage,sizeof(struct time_record),1,pfile);
			fclose(pfile);
			free(storage);
			storage=NULL;
			count++;
		}
		printf("the row number is %d\n",count);
		sleep(1);
	}
	return 0;
}	
