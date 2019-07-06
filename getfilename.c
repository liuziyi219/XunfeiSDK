#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/io.h>
FILE *fp=NULL;
int readfilelist(char *basePath)
{
	DIR *dir;
	struct dirent *ptr;
	char base[1000];
	if((dir=opendir(basePath))==NULL)
	{
		perror("Open dir error...");
		exit(1);
	}
	while((ptr=readdir(dir))!=NULL)
	{
		if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
                      continue;
                else if(ptr->d_type == 8)    ///file
                {
                    
                       printf("d_name:%s\n",ptr->d_name);
		       fprintf(fp,"%s\n",ptr->d_name);
               }
           }
       
	closedir(dir);
	return 1;
}
int main(void)
{
	DIR *dir;
	char basePath[1000];
	memset(basePath, '\0', sizeof(basePath));
	getcwd(basePath, 999);
	printf("the current dir is : %s\n", basePath);
        fp=fopen("name.txt","w");
	memset(basePath,'\0',sizeof(basePath));
	strcpy(basePath,"./xwlb0302");
	readfilelist(basePath);
        fclose(fp);
	return 0;
}
