
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program       : fseek function is used to change the file position which is used for further reading or writing.
//  Fucntion      : FILE *fopen(const char *file_name, const char *mode_of_operation);
//                  fseek(FILE *pointer, long int offset, int position);
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
//                 int fseek(FILE *pointer, long int offset, int position)
//                 pointer : pointer to a FILE object that identifies the stream.
//                 offset  : number of bytes to offset from position
//                 position: position from where offset is added.
//                 returns : zero if successful, or else it returns a non-zero value 
//
//  Date          : 29/06/2021
//  Author        : Pranav Anil Waghmare
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include<stdio.h>

int main()
{
	FILE *fp = NULL;
	int ret;
	char ch;

	fp = fopen("file.txt","r+");
	if(fp == NULL)
	{
		printf("Unable to open file\n");
	}

	// Print the contents of file
	printf("File contents before fseek are\n");
	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}

	ret = fseek(fp,5,SEEK_SET);
	// First parameter :	File pointer
	// Second parameter :	Number of bytes to seek (It can be negative also)
	// Third parameter :	It indecates from where we have to seek
	// Third parameter is as follows :
	// SEEK_SET :	Seek from begining of the file (0)
	// SEEK_CUR :	Seek from current position (1)
	// SEEK_END :	Seek from end of the file (2)

	if(ret != 0)
	{
		printf("Unable to seek\n");
	}

	// Write character 'z' at the new position
	fputc('z',fp);

	printf("\n\nFile contents before fseek are\n");

	// Set the file position to the begining
	fseek(fp,0,SEEK_SET);

	// The above effect can be achived through the function rewind
	// rewind() function sets file position indecator to start of the file

	rewind(fp);

	while((ch = fgetc(fp))!=EOF)
	{
		printf("%c",ch);
	}
	return 0;
}
