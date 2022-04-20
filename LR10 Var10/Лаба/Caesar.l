%option noyywrap
%{
char tempChar = 0;
char tempCounter = 0;
%}
%%
[a-wA-W]  {
	   printf("%c", yytext[0] + 3);
	  }

[x-z]     {
	   tempChar = 'a' + (yytext[0] + 3 - 'z') - 1;
	   printf("%c", tempChar);
	  }

[X-Z]     {
	   tempChar = 'a' + (yytext[0] + 3 - 'z') - 1;
	   printf("%c", tempChar);
	  }

.	  {
	   tempCounter += 1;
	   printf("%c", yytext[0]);
	  }	
%%
int main()
{
 yylex(); 
 printf("%d", tempCounter);
 return 0;
}