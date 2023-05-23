#define _CRT_SECURE_NO_WARNINGS  //scanf_s() 또는 printf_s()를 사용하지 않아서 발생하는 오류 무시

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char  filename[512] = "notepad.exe report1.txt";
	char* command;

	//gets(filename);   
	command = filename;
	system(command);   // 	system("notepad.exe report.txt");  system("notepad.exe D:\\report.txt");
	
	return 0;
}