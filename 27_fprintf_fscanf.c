

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This program demonstate formatted input output from file by using fprint() & fscanf().
//  Fucntion      : FILE *fopen(const char *file_name, const char *mode_of_operation);
//                  fprintf(FILE *fptr, const char *str, ...);
//                  fscanf(FILE *ptr, const char *format, ...);
//
//  Description   :  file_name: This is of C string type and accepts the name of the file that is needed to be opened.
//					mode_of_operation: This is also of C string type and refers to the mode of the file access. 
//                  Below are the file access modes for C: 
//					“r” – Searches file. Opens the file for reading only.
//                        If the file is opened successfully fopen() loads it into memory and sets up a pointer which points to the first character in it. 
//                        If the file cannot be opened fopen() returns NULL.
//					“w” – Searches file. If the file exists already, its contents are overwritten.
//                        If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. 
//                        It creates a new file for writing only(no reading).
//					“a” – Searches file. If the file is opened successfully fopen() loads it into memory and sets up a pointer that points to the last character in it.
//                        If the file doesn’t exist, a new file is created. 
//                        Returns NULL, if unable to open the file.
//                        The file is opened only for appending(writing at end of file).
//					“r+” – Searches file. Opens the file for both reading and writing. 
//                         If opened successfully, fopen() loads it into memory and sets up a pointer which points to the first character in it.
//                         Returns NULL, if unable to open the file.
//					“w+” – Searches file. If the file exists, its contents are overwritten. 
//                         If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file.
//                         The difference between w and w+ is that we can also read the file created using w+.
//					“a+” – Searches file. If the file is opened successfully fopen( ) loads it into memory and sets up a pointer which points to the last character in it.
//                         If the file doesn’t exist, a new file is created. Returns NULL, if unable to open the file. 
//                         The file is opened for reading and appending(writing at end of file).
//					Return Value: The function is used to return a pointer to FILE if the execution succeeds else NULL is returned. 
//
//                 fprintf : fprinf is similar as printf but insted of writing the contents on STDOUT it writes the contents in file.
//                          It returns no of characters successfully written in file.
//
//                 fscanf : fscanf is similar as scanf but insted of reading the contents from STDIN it reads the contents from file.
//                          It returns no of characters successfully read from file.
//
//  Date          : 29/06/2021
//  Author        : Pranav Anil Waghmare
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	char str[]="New string";
	char ch;

	// open the file
	fp = fopen("file.txt","r+");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}


	fprintf(fp,"\t%s\n",str);


	fscanf(fp,"%c",&ch);
	printf("Character read by fscanf is : %c\n",ch);

	return 0;
}
