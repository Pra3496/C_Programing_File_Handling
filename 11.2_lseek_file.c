
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This program demonstate open system call and uses fcntl.h header file declares the following 
//					functions for creating, opening, rewriting, and manipulating files.
//  Fucntion      : open(PATH,mode);
//                  lseek(PATH,size_in_bytes,position);
//
//  Description   :  The open() function shall establish the connection between a file and a file descriptor. 
//                   It shall create an open file description that refers to a file and a file descriptor that refers to that open file description. 
//                   The file descriptor is used by other I/O functions to refer to that file.
//                   
//                   The lseek() function shall set the file offset for the open file description associated with the file descriptor fildes
//                   If whence is SEEK_CUR, the file offset shall be set to its current location plus offset. 
//
//					 SEEK_SET means staring offset of file.
//					 SEEK_CUR means current offset of file.
//					 SEEK_END means last byte offset of file.
//                  
//  Date          : 15/06/2021
//  Author        : Pranav Anil Waghmare
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <fcntl.h>
#include<stdio.h>

char buf1[] = "First line";
char buf2[] = "Last line";

int main(void)
{
	int fd;
	int offset;

	fd = open("new.txt",O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}

	// File is opened in read or write mode current file offset
	// is always zero
	// Means we open a file which is already existing and we write something
	// in that file then data gets overwritten
	
	// To change the current file offset we can use lseek function	

	offset = lseek(fd,0,SEEK_SET);
	printf("offset is %d\n",offset);


	// We can change the file offset 50 bytes from the starting position by 

	offset = lseek(fd,50,SEEK_SET);
	printf("Now current offset is %d\n",offset);

	// We can also move the current byte offset in backward direction

	offset = lseek(fd,-20,SEEK_CUR);
	printf("After backward traversal offset is %d\n",offset);

	// To check the last byte offset of the file we can call lseek function as

	offset = lseek(fd,0,SEEK_END);
	printf("Last byte offset is %d\n",offset);

	return 0;
}
