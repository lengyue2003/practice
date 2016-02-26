#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define TEXTMAX 10000
#define BUFMAX 100
struct list{
	char*word;
	int count;
	struct list*next;
};
struct list*check_word(struct list*head,char*word);
int main()
{
	char text[TEXTMAX+1];
	char buffer[BUFMAX];
	char endstr[]="*\n";
	char quote='\'';
	char space=' ';
	char *text_p=NULL;
	char *delim=NULL;
	char *word_single=NULL;
	struct list*word_get=NULL;
	struct list*head=NULL;
	struct list*current=NULL;
	struct list*previous=NULL;
	while(1){
		if(!strcmp(fgets(buffer,BUFMAX,stdin),endstr))
			break;
		if((strlen(text)+strlen(buffer)+1)>TEXTMAX)
			printf("Maximum capacity for text exceeded.Terminating program");
		strcat(text,buffer);
	}
	for(int i=0;i<strlen(text);i++){
		text[i]=tolower(text[i]);
		if((text[i]==quote)||isalnum(text[i]))
			continue;
		text[i]=space;
	}
	text[strlen(text)-1]='\0';
	text_p=text;
	while(*text_p&&(*text_p==space))
		text_p++;
	while((delim=strchr(text_p,space))){
		*delim='\0';
		word_single=text_p;
		if(word_get=check_word(head,word_single))
			word_get->count++;
		else{
			current=(struct list*)calloc(1,sizeof(struct list));
			current->word=word_single;
			current->count=1;
			current->next=NULL;
			if(head==NULL)
				head=current;
			else
				previous->next=current;
		}
		text_p=delim+1;
		while(*text_p&&(*text_p==space))
			text_p++;
		previous=current;
	}	
	current=head;
	int i=1;
	while(current){
		printf("  %-15s%5d",current->word,current->count);
		current=current->next;
		if(i%3==0)
			printf("\n");	
		i++;
	}
	return 0;
}
struct list*check_word(struct list*head,char*word)
{
	struct list*x=head;
	while(x){
		if(!strcmp(x->word,word))
			break;
		x=x->next;
	}
	return x;
}
