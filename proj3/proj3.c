#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>


char* arr[5][6];

int main(int argc,char* argv[])
{
	
int stdinp=dup(0);
int stdout=dup(1);
int stderr=dup(2);
	
int i=0;
int j=0;
int k=0;
int g=0;
int h=0;
		
	
for(g=0;g<5;g++) 
for(h=0;h<6;h++) {
if(h==5)
arr[g][h]="\0";
	}

int check_type=strcmp(argv[1],"silent");
int check_type1=strcmp(argv[1],"verbose");


if(check_type==0 ||  check_type1==0)
{
	
if(argc>2) { 
for(i=2;i<argc;i++) 
{
	
int check1=strcmp(argv[i],"GT");
int check2=strcmp(argv[i],"GTGT");
int check3=strcmp(argv[i],"GTAMP");
int check4=strcmp(argv[i],"LT");
int check5=strcmp("PIPE",argv[i]);

if(check5==0) 
{ 
	j++;
	k=0;
	}

 else if(check4==0) {

	int fd=open(argv[++i],O_RDONLY,0);
   
	if(fd==-1) {	
	}

	else {
   dup2(fd,0);		
   close(fd);
   
	
	}
}



else if(check3==0) {

	int fd=open(argv[++i],O_WRONLY|O_CREAT,0777);
	if(fd==-1) {	}

	else {
		
   dup2(fd,2);		
   close(fd);
   
	}

}

else if(check2==0) {

	int fd=open(argv[++i],O_WRONLY|O_APPEND,0777);
	if(fd==-1) {	
	}

	else {
		
   dup2(fd,1);		
   close(fd);
   
	}
}


else if(check1==0) {

	int fd=open(argv[++i],O_WRONLY|O_CREAT,0777);
	if(fd==-1) {	}

	else {
		
   dup2(fd,1);		
   close(fd);
   
	}
}


else {
arr[j][k]=argv[i];
k++;
}

}


if(j==0) {
	
int pida=fork();
if(pida==0) 
{	
execvp(arr[0][0],arr[0]);
}

	
}

else if(j==1) 
	{
int pipe_discriptors[2];
        
    pipe(pipe_discriptors);
       
       int pid = fork();       
        
      if(pid == 0)
      {
            close(pipe_discriptors[0]);
            dup2(pipe_discriptors[1],1);
            execvp(arr[0][0],arr[0]);
       }

wait(NULL);

        close(pipe_discriptors[1]);
   	int pid12 = fork();                
        if(pid12 == 0)
        {
        	
            dup2(pipe_discriptors[0],0);
		  execvp(arr[1][0],arr[1]);
  }

wait(NULL);

}

else if(j==2) {
	
int pipe_discriptors2[2];
        
        pipe(pipe_discriptors2);
        
        int pid2 = fork();       
        
        if(pid2 == 0)
        {
            close(pipe_discriptors2[0]);
            dup2(pipe_discriptors2[1],1);
            execvp(arr[0][0],arr[0]);
        }
        		wait(NULL);
        		close(pipe_discriptors2[1]);
        		
     int pipe_discriptors3[2];
        pipe(pipe_discriptors3);
        int pid3 = fork();                
        if(pid3 == 0)
        {
            close(pipe_discriptors3[0]);
            dup2(pipe_discriptors2[0],0);
            dup2(pipe_discriptors3[1],1);
            execvp(arr[1][0],arr[1]);
        }
        
 wait(NULL);
        close(pipe_discriptors2[0]);
        close(pipe_discriptors3[1]);
        int pid4 = fork();                
        if(pid4 == 0)
        {
            close(pipe_discriptors3[1]);
            dup2(pipe_discriptors3[0],0);
            execvp(arr[2][0],arr[2]);
        }
        wait(NULL);
        close(pipe_discriptors3[0]);

}





wait(NULL);
	dup2(stdout,1);
	dup2(stdinp,0);
	dup2(stderr,2);

if(check_type1==0)
{

//printf("%s,%d",arr[0][0],pid);


}


}

printf("\nCommand(s) execution complete.\n");

}



}




