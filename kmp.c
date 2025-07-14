#include <stdio.h>
#include <string.h>

void get_next(char T[], int next[]) {
    int len = strlen(T);
    int j = 0;  // j 记录匹配的前缀长度
    int i = 1;
    next[1] = 0;
    
    while (i < len ) {  
        if (j == 0 || T[i-1] == T[j-1]) {  
            i++;
            j++;
            next[i] = j;  
        } else {  
            j = next[j];  // 发生不匹配时回溯
        }
    }
}
int KMP(char T[],char S[],int next[]){
	int lenT=strlen(T);
	int lenS=strlen(S);
	int i=1,j=1;
	while(i<=lenS&&j<=lenT){
		if(S[i-1]==T[j-1]){
			j++;
			i++;
		}
		else
			j=next[j];			
		if(j==lenT){
			 return i-j;
		}
	}
	 return -1;
}

int main() {
	int i;
    char T[20];
    char S[20];
    char T1[20];
    printf("请输入主串：");
     scanf("%s",S);
     printf("请输入模式串:"); 
    scanf("%s", T);
     int len = strlen(T);
    
    int next[20];
    get_next(T, next);
    
    for ( i = 1; i <=len; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");
    int result=KMP (T,S,next);
    if(result!=-1){
    		printf("已找到该字符串下标为%d",result);
	}
	else printf("没有找到该字符串。");
    return 0;
}


