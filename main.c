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
#define PUB "<p id=\"publ\"></p>"
#define DEST "<p id=\"dest\"></p>"
#define TITLE "<p id=\"titl\"></p>"
#define MAIN "<p id=\"main\"></p>"

int main(void){

	FILE *fp;
	char str[STR_SIZE+1];
	char body[STR_SIZE-1];
	char html[512];
	char temp[STR_SIZE] = "<html>\n<head>\n<link rel=\"stylesheet\" href=\"style.css\">\n</link>\n</head>\n<body>\n</body>\n</html>\n";
	char puff[64];
	char prefix[3];
	char macro[5];
	char kmain[STR_SIZE]="・";
	char atag[STR_SIZE*2];
	char btag[16];
	char tempb[STR_SIZE];

	fp = fopen("入力.txt","r");
	if (fp==NULL) {
		printf("ファイルが開けませんでした\n確認してください\n");
		return 1;
	}

	while(fscanf(fp, "%s", str) != EOF) {
		getstr(str, 0, 2, prefix, sizeof(prefix));
		getstr(str, 2, STR_SIZE-2, body, sizeof(body));
		if (!strcmp(prefix,"##")) {
			getstr(TITLE, 0, 13, atag, sizeof(atag));
			getstr(TITLE, 13, 4, btag, sizeof(btag));
			strcat(atag,body);
			strcat(atag,btag);
			strcat(html,atag);
		}
		else if (!strcmp(prefix,">>")) {
			getstr(PUB, 0, 13, atag, sizeof(atag));
            getstr(PUB, 13, 4, btag, sizeof(btag));
			strcat(atag,body);
            strcat(atag,btag);
			strcat(html,atag);
		}
		else if (!strcmp(prefix,"<<")) {
			getstr(DEST, 0, 13, atag, sizeof(atag));
            getstr(DEST, 13, 4, btag, sizeof(btag));
			strcat(atag,body);
            strcat(atag,btag);
			strcat(html,atag);
		}
		else if (!strcmp(prefix,"--")) {
			getstr(MAIN, 0, 13, atag, sizeof(atag));
            getstr(MAIN, 13, 4, btag, sizeof(btag));
			strcat(kmain,body);
			strcat(atag,body);
            strcat(atag,btag);
			strcat(html,atag);
		}
		else if (!strcmp(prefix,"$$")) {
			getstr(MAIN, 0, 13, atag, sizeof(atag));
            getstr(MAIN, 13, 4, btag, sizeof(btag));
			getstr(body, 0, 4, macro, sizeof(macro));
			getstr(body, 4, STR_SIZE-6, body, sizeof(body));
			strcat(atag,str);
            strcat(atag,btag);
			strcat(html,atag);
		}
		else {
			getstr(MAIN, 0, 13, atag, sizeof(atag));
            getstr(MAIN, 13, 4, btag, sizeof(btag));
			strcat(atag,str);
            strcat(atag,btag);
			strcat(html,atag);
		}
	}
	getstr(temp, 0, 77, tempb, sizeof(tempb));
	getstr(temp, 77, sizeof(temp)-77, temp, sizeof(temp));
	strcat(tempb,html);
	strcat(tempb,temp);
	printf("\n%s\n",tempb);

	fclose(fp);

	fp = fopen("出力.html", "w");

	fprintf(fp, "%s\n", tempb);

	fclose(fp);

	return 0;
}
