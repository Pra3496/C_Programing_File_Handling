
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This program demonstates block input and output from file by using fread,fwrite.
//					functions for creating, opening, rewriting, and manipulating files.
//  Fucntion      : fopen(PATH,mode);
//                  fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
//                  fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
//
//  Description   :  The fopen() function shall establish the connection between a file and a file descriptor. 
//                   It shall create an open file description that refers to a file and a file descriptor that refers to that open file description. 
//                   The file descriptor is used by other I/O functions to refer to that file.
//
//					 fwrite() : We can write the contents to the file by using write system call which accept first parameter as file descriptor
//					 second parameter is filled buffer
// 					 Third parameter is number of bytes to write
//                   
//                   fread() : The C library function fread() reads data from the given stream into the array pointed to, by ptr.
//                  
//                   Parameters are :
//                   ptr    − This is the pointer to a block of memory with a minimum size of size*nmemb bytes.
//                   size   − This is the size in bytes of each element to be read.
//                   nmemb  − This is the number of elements, each one with a size of size bytes.
//                   stream − This is the pointer to a FILE object that specifies an input stream.
//                  
//  Date          : 25/06/2021
//  Author        : Pranav Anil Waghmare
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include <string.h>

struct demo
{
int i;
char arr[6];
};

int main()
{

FILE *fp = NULL;
int ret;

struct demo obj1,obj2;
obj1.i = 10;
strcpy(obj1.arr,"Hello");

// open the file
fp = fopen("file.txt","wb");
// First parameter :	Name of file to open
// Second parameter :	Mode in which file should be open

if(fp == NULL)
{
	printf("Unable to open file\n");
}

// This function is used to write block in file.

ret = fwrite(&obj1,sizeof(obj1),1,fp);
// First parameter :	Data element to be write
// Second parameter :	Size of data element
// Third parameter :	No of data elements
// Fourth parameter : 	File pointer

// This function returns number of data elements written in file
 
if(ret != 1)
{
	printf("Error while writing the contents");
	return -1;
}

fclose(fp);

// open the file
fp = fopen("file.txt","rb");
if(fp == NULL)
{
	printf("Unable to open file\n");
}

fread(&obj2,sizeof(obj2),1,fp);

printf("  %d   %s\n",obj2.i,obj2.arr);

return 0;
}
