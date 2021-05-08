#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 1024
#define MAX_NUM 1024
int countw(){
	int words = 0;
	int min = 65525, max = 0,sum = 0;
	FILE* fp;  
	char buffer[MAX_LINE] ; 
	int len ;  
	int i;
	fp = fopen("text.txt","r");
    if(fp == NULL){
        printf("cannot open file!");
        exit(0);
    }
    while(! feof(fp)){
     	    if(fgets(buffer, MAX_LINE, fp) != NULL){
            len = strlen(buffer);
            words = 1;
            sum ++;
			for(i = 0; i < len - 1; i++){
	                if(buffer[i] == ' '){
                    words ++;
                    sum ++;
				}
			}
		}
 	if(min > words){
        min = words;
    }
    if(max < words){
        max = words;
    }
    }
    fclose(fp);
    printf("������: %d",sum);
}

void countc(){
		char buf[MAX_NUM];			//�ַ�������
	FILE *fp;            
	int len,total=0;           //ÿ���ַ�������������
	if((fp = fopen("text.txt","r")) == NULL){
		perror("the file fail to read");
		getchar();				//��ͣ��ʾ
		exit (1) ;
		}
	 while(!feof(fp) && !ferror(fp)){	//�ļ���ȡ������������˳�
		fgets(buf,MAX_NUM,fp);
		len = strlen(buf);
		if(buf[len-1] == '\n'){
			buf[len-1] = '\0';  
			len--;
		}
		if(len == 0) continue;	//�����հ���
		total+=len;
	 }
	printf("�ַ���: %d",total);
	fclose(fp);				//�ر��ļ�
	getchar();
}

int main(){
	char parameter[2];
	char filename[10];
	gets(parameter);
	gets(filename);
	if (parameter[1]=='w'){
		countw();
	}
	else{
		countc();
	}
}
