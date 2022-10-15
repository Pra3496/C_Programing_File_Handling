

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : This program demonstate how to read line or how to write line into the file.
//  Fucntion      : FILE *fopen(const char *file_name, const char *mode_of_operation);
//                  fgets(char *str, int n, FILE *stream);
//                  fputs(const char *str, FILE *stream);
//  Input         : The method accepts two parameters of character type.
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
//                  fgets: The standard C library also provides us with yet another function, the fgets() function. 
//                  The function reads a text line or a string from the specified file or console. 
//                  And then stores it to the respective string variable.
//                  parameters are :
//                  str - It is the variable in which the string is going to be stored
//                  n   - It is the maximum length of the string that should be read
//                  stream - It is the filehandle, from where the string is to be read.
//
//                  fputs: The C library function int fputs(const char *str, FILE *stream) writes a string to the specified stream up to but not including the null character.
//                  parameters are :
//                  str − This is an array containing the null-terminated sequence of characters to be written.
//                  stream − This is the pointer to a FILE object that identifies the stream where the string is to be written.
//
//                  fclose: It is used to close to file. 
//
//  Date          : 27/06/2021
//  Author        : Pranav Anil Waghmare
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>

int main()
{

	FILE *fp;
	char str[50];
	char *p;
	int ret;

	// open the file in read mode
	fp = fopen("file.txt","r");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
		return -1;
	}

	// fgets function read the string from file till new line character occurs or length satisfies
	p = fgets(str,10,fp);
	// First parameter :	Array in which data is to be read
	// Second parameter :	Number of character to read
	// Third parameter :	File pointer

	// If there is some error then it returns NULL
	if(p == NULL)
	{
		printf("Error in fgets\n");
		return -1;
	}


	printf("Contents read by fgets are :\n%s",str);

	fclose(fp);

	// open the file in write mode
	fp = fopen("file.txt","w");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
		return -1;
	}

	ret = fputs("New line inserted in file",fp);
	// First parameter :	String which is to be written in file
	// Second parameter :	File pointer

	// IF therere is some error it reaturns EOF
	if(ret == EOF)
	{
		printf("Unable to write contents in file\n");
		return -1;
	}

	return 0;	
}
