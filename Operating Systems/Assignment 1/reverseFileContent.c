/*===========================================================================
 * File Name: reverseFileContent.c
 * Instructor: Nguyen Thai
 * Student: Piyusha Jahagirdar
 * Date: 02/08/2017
 * Description:This program reads the characters from the input file and writes the	
 *	       characters to the output file in reverse order
 *
 *==========================================================================*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ( int argc, char *argv[]) {
	int inputFile, outputFile, fileSize;
	char buffer;
	int pointer;
	int bytes;

  /* Check for correct user's inputs. */
	if( argc !=3 ) {
		fprintf(stderr, "USAGE: %s inputFile outputFile.\n", argv[0]);
		exit(-1);
	}

  /* Make sure input file exists. */
	if( (inputFile = open(argv[1], O_RDONLY)) == -1) {
	  fprintf(stderr, "Input file doesn't exist.\n");	
		exit(-1);
	}

  /* Create output file, if it doesn't exist.  Empty the file, if it exists. */
	if((outputFile = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644))==-1) {
		close(inputFile);
		exit(-1);
	}

  /* Find the size of the input file. */
	fileSize = lseek(inputFile, (off_t)0, SEEK_END);
	
  /* Read input file and write to output file in reversed order.
   * Use lseek() to move the file pointer to the ith position.
	 * To set the file pointer to a position use the SEEK_SET flag in lseek().
	 */
	for(pointer=fileSize-1; pointer>=0; pointer--) {

		/* Setting the pointer to theith position */
		lseek(inputFile, (off_t) pointer, SEEK_SET);
		/* Reading data from the input file*/
		bytes = read(inputFile, &buffer, 1);
		if(bytes == -1)
		{
			fprintf(stderr, "Error in reading the input file\n");
			exit(-1);
		}		
		/*Writing data to output file*/
		bytes = write(outputFile, &buffer, 1);
		if(bytes == -1)
		{
			fprintf(stderr, "Error in writing to the output file\n");
			exit(-1);
		}		
	}

	close(inputFile);
	close(outputFile);

	return(0);
}

