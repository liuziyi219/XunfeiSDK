#include <cstdio>
#include <cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;
#define MAX_LINE 1024
bool cmp(string s1,string s2)
{
	return s1<=s2;
}
int main()
{
	string a[100];
	int i=0;
 char buf[MAX_LINE];  /*缓冲区*/
 FILE *fp;       /*文件指针*/
 int len;             /*行字符个数*/
 if((fp = fopen("name.txt","r")) == NULL)
 {
 perror("fail to read");
 exit (1) ;
 }
 while(fgets(buf,MAX_LINE,fp) != NULL)
 {
 len = strlen(buf);
 buf[len-1] = '\0';  /*去掉换行符*/
 a[i]=buf;
 i++;
// printf("%s %d \n",buf,len - 1);
 }
 fclose(fp);
// for(int j=0;j<=i;j++)
// {cout<<a[j]<<endl;}
  sort(a,a+i,cmp);
  ofstream OutFile("sortname.txt");
  for(int j=0;j<=i;j++)
  {
  OutFile<<a[j]<<endl;
  }
  return 0;
}
