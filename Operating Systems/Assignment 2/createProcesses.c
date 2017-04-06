#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	pid_t pid, pid1, pid2;

	/* fork a child proccess*/
	pid=fork();

	if(pid<0)/*error occured*/
	{
		printf("Fork Failed");
		return 1;
	}
	else if (pid==0)/*Child process*/
	{
		printf("\nCHILD");		
		printf("\nChild : pid = %d\n",pid);

		/* fork a child proccess*/
		pid1=fork();
	
		if(pid1<0)/*error occured*/
		{
			printf("Fork Failed");
			return 1;
		}
		else if (pid1==0)/*Child process*/
		{
			printf("\nCHILD->CHILD");		
			printf("\nChild : pid = %d\n",pid1);
			exit(0);
		}
		else/*Parent process*/
		{
			printf("\nCHILD->PARENT");			
			printf("\nParent : pid= %d\n", pid1);
			wait(NULL);/*Parent waiting for child to complete*/
			exit(0);
		}
	}
	else/*Parent process*/
	{
		printf("\nPARENT");		
		printf("\nParent : pid = %d\n",pid);
		wait(NULL);/*Parent waiting for child to complete*/
		pid2=fork();
	
		if(pid2<0)/*error occured*/
		{
			printf("Fork Failed");
			return 1;
		}
		else if (pid2==0)/*Child process*/
		{
			printf("\nPARENT->CHILD");		
			printf("\nChild : pid = %d\n",pid2);
			exit(0);
		}
		else/*Parent process*/
		{
			printf("\nPARENT->PARENT");			
			printf("\nParent : pid= %d\n", pid2);
			wait(NULL);/*Parent waiting for child to complete*/
			exit(0);
		}	
	}	
return 0;
}


