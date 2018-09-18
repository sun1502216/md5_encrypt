#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"


int main(int argc, char** argv)
{
/*
	char test[10] = "123456";

	printf("%s\n", md5_encrypt(test, strlen(test));
*/
	if(2 != argc)
	{
		fprintf(stderr, "参数输入错误\n");
		exit(1);
	}

	int size = 0;
	char* buff = NULL;
	FILE* fp = fopen(argv[1], "r");
	if(NULL == fp)
	{
		perror("fopen");
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	buff = (char*)malloc(size);
	if(NULL == buff)
	{
		perror("malloc");
		fclose(fp);
		exit(1);
	}

	rewind(fp);

	if(fread(buff, 1, size, fp) != size)
	{
		fprintf(stderr, "read fail!\n");
		fclose(fp);
		exit(1);
	}

	printf("%s\n", md5_encrypt(buff, size));

	free(buff);
	fclose(fp);

	return 0;
}
