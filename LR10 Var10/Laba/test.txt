%option noyywrap
%{
#include <stdio.h>
#include <string.h>
int k = 0;
FILE *file, *yyin, *temp, *out, *temp2;
char str[20];
char buf[200];

#define SHIFT 3;

%}

%%
	[a-z]:        {Cezar(i, buf[i]);}
%%

void Cezar(int i, char buf[200]){
	if (((buf[i]>='A') && (buf[i]<='Z')) || ((buf[i]>='a') && (buf[i]<='z'))){
	  buf[i] = buf[i] + SHIFT;
	 }
}

void main(){
	file = fopen("work/input.txt", "r");
	while (!feof(file)) {
		fscanf(file, "%s", str);
		strcat(buf, str);
		strcat(buf, "  ");
	}
	temp = fopen("temp.txt", "w");
	fprintf(temp, "%s", buf);
	fclose(temp);
	fclose(file);

	yyin = fopen("temp.txt", "r");
	yyout = fopen("temp2.txt", "w");
	out = fopen("work/output.txt", "w");

	buf[strlen(buf) - 2] = buf[strlen(buf) - 1] = '\n';
	i++;
	yylex();
	fprintf(out, "%s", buf);

	fclose(yyin);
	fclose(yyout);
	fclose(out);

}


