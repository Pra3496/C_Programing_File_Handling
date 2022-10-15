
/////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This program uses fcntl.h header file declares the following 
//					functions for creating, opening, rewriting, and manipulating files.
//
//  Description   : Creating new file
// 					If the file does not exist it will be created.  
// 					The owner (user ID) of the file is set to the effective user ID of the process.
//					open() and creat() return the new file descriptor, or -1 on failure.
//  Date          : 15/06/2021
//  Author        : Pranav Anil Waghmare
//
/////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd;

	

	fd = creat("second.txt",0x777);	// 0x777 : "rwx rwx rwx" (permissions of user, owner, group)

	if(fd == -1)
	{
		printf("Unable to create the file\n");
	}
	else
	{
		printf("File is successfully created with file descriptor %d \n",fd);
	}

	// closing the file.
	close(fd);
}
