// main.c (RakuRakuFormat)
//
// Yuto.Yazawa (008900012151b5yr@gl.pen-kanagawa.ed.jp)
//
// This software is released under the MIT License, see LICENSE.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stredit.h"
#define STR_SIZE 1600

int main(void){

	FILE *fp;
	char str[STR_SIZE+1];
	char prefix[3];

	fp = fopen("入力.txt","r");
	if (fp==NULL) {
		printf("ファイルが開けませんでした\n確認してください\n");
		return 1;
	}

	while(fscanf(fp, "%s", str) != EOF) {
		extract(str, 0, 2, prefix, sizeof(prefix));
		if (strcmp(prefix,"##")==0) {
			printf("タイトル！\n");
		}
	}

	fclose(fp);

	return 0;
}
