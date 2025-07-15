#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 30
#define Max 2*N-1
typedef struct 
{
    double weight;//权值
    char s;//所代表的字符
    int parent,lchild,rchild;//父亲，左孩子，右孩子
    /* data */
}HTNode;
typedef HTNode Huffmantree[Max+1];
void Select (Huffmantree ht,int x,int *m1,int *m2);//找出森林集合中权值最小的两个

void CreatHuffmanTree (Huffmantree ht,int n);//构建哈夫曼树

void HuffmanCoding(Huffmantree ht,char **hc,int n);//哈夫曼编码

void printHuffmanCode(Huffmantree ht,char **hc,int index);//先序打印

void HuffmanDecoding(Huffmantree ht,int n,char *pwd);//在生成的哈夫曼树中查询目标

void Select (Huffmantree ht,int x,int *m1,int *m2)
{
    double min1=999999;
    double min2=999999;
    int j;
    //找到最小的那一个权值
    for(j = 1;j <= x;j++){
        if(ht[j].weight < min1 && ht[j].parent == 0){
            min1 =ht[j].weight;
            *m1 = j;
        }
    }
    
    //找到不等于min1的最小数min2
    int k;
    for(k = 1;k <= x; k++){
        if(ht[k].weight < min2 &&k!=*m1 && ht[k].parent ==0){
            min2 = ht[k].weight;
            *m2 = k;
        }
    }
}

void CreatHuffmanTree(Huffmantree ht ,int n)
{
    int i;
    for( i=n+1;i <=2*n -1;i++){
         
        int m1,m2;
        Select(ht,i-1,&m1,&m2);
        //从n+1开始创建根
        ht[i].weight = ht[m1].weight + ht[m2].weight;
        ht[i].lchild = m1;
        ht[i].rchild = m2;
        ht[i].parent = 0;
        ht[m1].parent = i;
        ht[m2].parent = i;
    }
}
//哈夫曼编码
void HuffmanCoding(Huffmantree ht,char **hc,int n)
{
    char * cd =(char * )malloc(n*sizeof(char));
    //临时存放哈夫曼编码
    cd[n-1] = '\0';//根节点为空

    int now = 1;
    int p = 0;
    int start;
    int i = 0;
    while(i < n){

        start = n-1;
        now = i+1;
        p = ht[now].parent;
        while( p!=0){

            start--;
            if(ht[p].lchild == now){
                cd[start] = '0'; 
            }
            else{
                cd[start] = '1';
            }
            now = p;
            p = ht[now].parent;

        }
        hc[i+1] = (char*)malloc((n-start)*sizeof(char));
        strcpy(hc[i+1],&cd[start]);
        i++;
    }

}
//先序打印
void printHuffmanCode(Huffmantree ht,char **hc,int index)
{
    if(index >= 1){ 
        if(ht[index].lchild == 0 && ht [index].rchild == 0){
            printf("%c:%s\n",ht[index].s,hc[index]);
            return ;
        }
        printHuffmanCode(ht,hc,ht[index].lchild);
        printHuffmanCode(ht,hc,ht[index].rchild);
    }
}

void HuffmanDecoding(Huffmantree ht,int n,char *pwd){
    printf("original:");
    int len = strlen(pwd);
    int i =0;
    int node = 2*n-1;
    while(i < len){
        if(pwd[i] == '0'){
            node = ht[node].lchild;
            i++;
            if(ht[node].lchild == 0&& ht[node].rchild == 0){
                printf("%c",ht[node].s);
                node = 2*n-1;
            }
        }
        if(pwd[i] == '1'){
            node = ht[node].rchild;
            i++;
            if(ht[node].lchild == 0&& ht[node].rchild == 0){
                printf("%c",ht[node].s);
                node =2*n-1;
            }
        }
    }
}
int main( ) {
    Huffmantree ht;
    int n;
    scanf("%d",&n);
    getchar();
    char *hc[n+1];
    int i;
    for(i = 1;i <= n;i++){
        scanf("%c%lf",&ht[i].s,&ht[i].weight);//输入字符和频率
        getchar();
        ht[i].lchild = 0;
        ht[i].rchild = 0;
        ht[i].parent = 0;
    }

    char pwd[9999];
    scanf("%s",pwd);
    //创建二叉树
    CreatHuffmanTree(ht,n);
    //编码
    HuffmanCoding(ht,hc,n);
    //前序输出
    printHuffmanCode(ht,hc,2*n-1);
    //译码
    HuffmanDecoding(ht,n,pwd);

    return 0;
}