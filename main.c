#include <stdio.h>
#include "stredit.h"

int main(void){
	char result[3];
	puts(extract("##abcdef", 0, 2, result, sizeof(result)));

	return 0;
}
