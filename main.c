#include <stdio.h>
#include "stredit.h"

int main(void){

	FILE *fp;
	int chr;
	char prefix[3];

	fp = fopen("入力.txt","r");
	if (fp==NULL) {
		printf("ファイルが開けませんでした\n確認してください\n");
		return 1;
	}

	while ((chr = fgetc(fp)) != EOF) {
		putchar(chr);
	}

	fclose(fp);

	//puts(extract("##abcdef", 0, 2, prefix, sizeof(prefix)));

	return 0;
}
