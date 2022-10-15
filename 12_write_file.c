
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This program demonstate open system call and uses fcntl.h header file declares the following 
//					functions for creating, opening, rewriting, and manipulating files.
//  Fucntion      : open(PATH,mode);
//                  write();
//                  lseek(PATH,size_in_bytes,position);
//
//  Description   :  The open() function shall establish the connection between a file and a file descriptor. 
//                   It shall create an open file description that refers to a file and a file descriptor that refers to that open file description. 
//                   The file descriptor is used by other I/O functions to refer to that file.
//
//					 write() : We can write the contents to the file by using write system call which accept first parameter as file descriptor
//					 second parameter is filled buffer
// 					 Third parameter is number of bytes to write
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

int main(void)
{
	int fd;
	int ret;
	int offset;

	char buff[] = "New contens in the file\n";
	char buff2[sizeof(buff)];

	// If file is opened in write mode we can read the contents from 0 byte offset
	fd = open("file.txt",O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file \n");
		return -1;
	}


	ret = write(fd,buff,sizeof(buff));

// read system call returns no of bytes successfully write.
// It returns -1 if it fails to write

	if(ret != sizeof(buff))
	{
		printf("Unable to write contents\n");
	}

	lseek(fd,0,SEEK_SET);

	ret = read(fd,buff2,sizeof(buff2));
	printf("Written contents are : %s\n",buff2);
	close(fd);
	close(ret);

	return 0;
}
