#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char * argv[]){
    int pid;
printf("argc value :%d\n",argc);
    
    //validation of the number of input files//
    
 if (atoi(argv[1])==0)
 {printf("Enter a valid number of input files");
     exit(0);
 }
    
    else
    {if (atoi(argv[1])==(argc-3))
    {
    printf("The number of input file= %d",(argc-3));
        
    //creating child process for each  input file to read and then write in the output file//
        
for (int i=0;i<(argc-3);i++)
{
pid=fork();
    
    //if fork() failed//
    
if (pid<0)
printf("The fork failed");
    
    //if fork() has created the child process successfully//
    
else if (pid==0)
{
//    printf("The child has created with:%d\n",(int) getpid());
    //Read the input file//
    FILE *fp;
    FILE *wp;
	fp=fopen(argv[i+2],"r");
    
	if(fp==NULL)
	{
        printf("Unable to open the file: %d",(i+2));
	exit(0);
	}
	else
	{
        char x;
	int count[26]={0};
	while ((x=fgetc(fp)) != EOF)
	{
 	if ( x>='a' && x<='z')
	++ count[x-'a'];
	else if (x>='A' && x<='Z')
	++count[x-'A'];
	}
        //write the frequency of the letters in the output file for each input file//
        
        wp=fopen(argv[argc-1],"a+");
        
        //if(wp==NULL)
       // {
        //    printf("not able to open file");
         //   exit(0);
        //}
//else
        fprintf(wp ," Occurence is file %s \n", argv[i+2]);
        for(int j=0;j<26;j++){
            char ch = j+ 97;
        fprintf(wp,"%c :", ch);
        fprintf(wp , "     %d \n", count[j]);
        }
}
    fclose(wp);
    fclose(fp);
    exit(0);
}
else
    // Parent process waits untill each child process get completed//
   {
wait(NULL);

   }
}
    printf("I am the parent:%d   write is done\n",(int) getpid());
    }
    

return 0;

}
