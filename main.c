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
	char body[STR_SIZE-1];
	char prefix[3];
	char macro[5];

	fp = fopen("入力.txt","r");
	if (fp==NULL) {
		printf("ファイルが開けませんでした\n確認してください\n");
		return 1;
	}

	while(fscanf(fp, "%s", str) != EOF) {
		getstr(str, 0, 2, prefix, sizeof(prefix));
		getstr(str, 2, STR_SIZE-2, body, sizeof(body));
		if (!strcmp(prefix,"##")) {
			printf("タイトル:%s\n", body);
		}
		else if (!strcmp(prefix,">>")) {
			printf("発行人:%s\n", body);
		}
		else if (!strcmp(prefix,"<<")) {
			printf("宛先:%s\n", body);
		}
		else if (!strcmp(prefix,"--")) {
			printf("箇条書き:%s\n", body);
		}
		else if (!strcmp(prefix,"$$")) {
			getstr(body, 0, 4, macro, sizeof(macro));
			printf("マクロ名:%s\n",macro);
		}
		else {
			printf("本文:%s\n", str);
		}
	}

	fclose(fp);

	return 0;
}
