#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
FILE *fp1;
FILE *fout;
char oneword[100];
char c;
int t;
bool quote;
bool comment;
char *instructions[] = {"mov", "int", "push", "ret", "pop", "call",
                    "lea", "cmp", "add", "jmp", "sub", "shr", "inc",
                    "dec","imul","shl","neg","not","div","and", "xor",
                    "or","JE","JLE", "JMP","loop"};
char *blah[] = {"small", ".stack", ".data", "db", ".code", "@data"} ;

    if( argc == 3 ){
		printf("The argument supplied are %s%s\n", argv[1],argv[2]);
		fp1 = fopen(argv[1], "r");
		fout = fopen(argv[2], "w");
	}
	else if( argc > 3 ){
		printf("Too many arguments supplied(gintvile to nors zinau ka sitas zodis reiskia), expected two.\n");
		printf("Using default: TENLINES.txt, out.html.\n");
		fp1 = fopen("TENLINES.txt", "r");
		fout = fopen("out.html", "w");
	}
	else{
    	printf("Two argument expected.\n");
		printf("Using default: TENLINES.txt, out.html.\n");
		fp1 = fopen("TENLINES.txt", "r");
		fout = fopen("out.html", "w");
	}
	fp1 = fopen("TENLINES.txt", "r");
    fout = fopen("out.html", "w");

    fprintf(fout,"<HTML>\n");
	fprintf(fout, "   <head> \n");
	fprintf(fout, "		<title>Assembler symtax</title> \n");
	fprintf(fout, "		<link href=\"special.css\" rel=\"stylesheet\" type=\"text/css\"> \n");
	fprintf(fout, "   </head> \n");
	fprintf(fout, "<body> \n");
	fprintf(fout, "<pre>\n");


 /*   while (c != EOF){
        c = fscanf(fp1,"%s",oneword);

        if ( (   (strcasecmp(oneword,"mov") == 0) //instructions
            || (strcasecmp(oneword,"int") == 0)
            || (strcasecmp(oneword,"push") == 0)
            || (strcasecmp(oneword,"ret") == 0)
            || (strcasecmp(oneword,"pop") == 0)
            || (strcasecmp(oneword,"call") == 0)
            || (strcasecmp(oneword,"lea") == 0)
            || (strcasecmp(oneword,"cmp") == 0)
            || (strcasecmp(oneword,"add") == 0)
            || (strcasecmp(oneword,"jmp") == 0)
            || (strcasecmp(oneword,"sub") == 0)
            || (strcasecmp(oneword,"shr") == 0)
            || (strcasecmp(oneword,"inc") == 0)
            || (strcasecmp(oneword,"dec") == 0)
            || (strcasecmp(oneword,"imul") == 0)
            || (strcasecmp(oneword,"shl") == 0)
            || (strcasecmp(oneword,"neg") == 0)
            || (strcasecmp(oneword,"not") == 0)
            || (strcasecmp(oneword,"div") == 0)
            || (strcasecmp(oneword,"and") == 0)
            || (strcasecmp(oneword,"xor") == 0)
            || (strcasecmp(oneword,"or") == 0)
            || (strcasecmp(oneword,"JE") == 0)
            || (strcasecmp(oneword,"JLE") == 0)
            || (strcasecmp(oneword,"JMP") == 0)
            || (strcasecmp(oneword,"loop") == 0)
            || (oneword[0] == '\n')))
        {
            if (comment)
                {
                    fprintf(fout, "<font color = 'orange'> %s </font>", oneword);
                }
            else
            {
                if(quote)
                 {
                    fprintf(fout, "<font color = 'purple'> %s </font>", oneword);
                 }
                else
                {
                    fprintf(fout,"<br>");
                    fprintf(fout,"<font color = 'blue'> %s </font>" , oneword); //<font color ="blue">',Zd[i],'</font>'
                    }
             }
        }
        else if (  (strcasecmp(oneword,"small") == 0)
                || (strcasecmp(oneword,".stack") == 0)
                || (strcasecmp(oneword,".data") == 0)
                || (strcasecmp(oneword,"db") == 0)
                || (strcasecmp(oneword,".code") == 0)
                || (strcasecmp(oneword,"@data") == 0)
                || (oneword[0] == '\n')

            )
            {
                if (comment)
                {
                    fprintf(fout, "<font color = 'orange'> %s </font>", oneword);
                }
                else
                {
                    if(quote)
                    {
                        fprintf(fout, "<font color = 'purple'> %s </font>", oneword);
                    }
                    else
                    {
                            fprintf(fout,"<br>");
                            fprintf(fout,"<font color = 'cyan'> %s </font>" , oneword);
                    }

                 }
             }
        else if( (strcasecmp(oneword,"ax,") == 0)
                  || (strcasecmp(oneword,"ah,") == 0)
                  || (strcasecmp(oneword,"dx,") == 0)
                  || (strcasecmp(oneword,"ds,") == 0)
                  || (strcasecmp(oneword,"ax") == 0)
                  || (strcasecmp(oneword,"bx") == 0)
                  || (strcasecmp(oneword,"cx") == 0)
                  || (strcasecmp(oneword,"dx") == 0)
                  || (strcasecmp(oneword,"al") == 0)
                  || (strcasecmp(oneword,"bl") == 0)
                  || (strcasecmp(oneword,"cl") == 0)
                  || (strcasecmp(oneword,"dl") == 0)
                  || (strcasecmp(oneword,"ah") == 0)
                  || (strcasecmp(oneword,"bh") == 0)
                  || (strcasecmp(oneword,"ch") == 0)
                  || (strcasecmp(oneword,"dh") == 0)
                  || (strcasecmp(oneword,"sp") == 0)
                  || (strcasecmp(oneword,"bp") == 0)
                  || (strcasecmp(oneword,"si") == 0)
                  || (strcasecmp(oneword,"di") == 0)
                  || (strcasecmp(oneword,"bp,") == 0)
                  || (strcasecmp(oneword,"si") == 0)
                  || (strcasecmp(oneword,"ax,") == 0)
                  || (strcasecmp(oneword,"bx,") == 0)
                  || (strcasecmp(oneword,"cx,") == 0)
                  || (strcasecmp(oneword,"dx,") == 0)
                  || (strcasecmp(oneword,"al,") == 0)
                  || (strcasecmp(oneword,"bl,") == 0)
                  || (strcasecmp(oneword,"cl,") == 0)
                  || (strcasecmp(oneword,"dl,") == 0)
                  || (strcasecmp(oneword,"ah,") == 0)
                  || (strcasecmp(oneword,"bh,") == 0)
                  || (strcasecmp(oneword,"ch,") == 0)
                  || (strcasecmp(oneword,"dh,") == 0)
                  || (strcasecmp(oneword,"sp,") == 0)
                  || (strcasecmp(oneword,"bp,") == 0)
                  || (strcasecmp(oneword,"si,") == 0)
                  || (strcasecmp(oneword,"di,") == 0)
                  || (strcasecmp(oneword,"si,") == 0)
                )
                {
                    if (comment)
                    {
                        fprintf(fout, "<font color = 'orange'> %s </font>", oneword);

                    }
                    else
                    {
                        if(quote)
                        {
                          fprintf(fout, "<font color = 'purple'> %s </font>", oneword);
                        }

                       else
                       {
                            fprintf(fout, "<font color = 'green'> %s </font>", oneword);

                       }
                    }

                }

        else
        {
            if(oneword[0] == 59)//kabliataskis
            {
               // fprintf(fout,"<br>");
                fprintf(fout, "<font color = 'orange'> %s </font>", oneword);
                comment = true;
                if (strcasecmp(oneword,"\n"))
                    {
                        fprintf(fout, "<br>");
                        comment = false;
                    }
            }
            else if (comment)
            {
                //fprintf(fout, "<br>");
                fprintf(fout, "<font color = 'orange'> %s </font>", oneword);
                  if (!strcasecmp(oneword,"\n"))
                    {
                        fprintf(fout, "<br>");
                        comment = false;
                    }
            }
            else
            {
                if((oneword[0] == 39) &&  !quote)
                {
                    fprintf(fout, "<font color = 'purple'> %s </font>", oneword);
                    quote = true;
                    if (!strcasecmp(oneword,"\n"))
                    {
                        fprintf(fout, "kabliataskio br");
                        comment = false;
                    }
                }
                if(quote)
                {
                    if((oneword[strlen(oneword) - 1] == 39) || (oneword[strlen(oneword) - 2] == 39))
                    {
                        quote = false;
                        //fprintf(fout,"<br>");
                    }
                    if(oneword[0] != 39)
                    {
                        fprintf(fout, "<font color = 'purple'> %s </font>", oneword);
                        if (!strcasecmp(oneword,"\n"))
                        {
                            fprintf(fout, "yolo");
                            comment = false;
                        }
                    }
                }
                else if ((oneword[0] >= 48) && (oneword[0] <= 57))
                {

                    fprintf(fout, "<font color = 'red'> %s </font>", oneword);
                     if (!strcasecmp(oneword,"\n"))
                    {
                        fprintf(fout, "<br>");
                        comment = false;
                    }
                }

                else
                {
                 //   fprintf(fout,"<br>");
                    fprintf(fout,"%s ",oneword);
                    //fprintf(fout,"%i" , atol(oneword));
                      if (!strcasecmp(oneword,"\n"))
                    {
                        fprintf(fout, "<br>");
                        comment = false;
                    }
                }

             }
            //first or last
        }
            //}
    }    /repeat until EOF          */

  /*  char * line = NULL;
    size_t len = 0;
    int i ;
    size_t read;
    while((read = getline(&line, & len, fp1)) != -1){
        c = line[i];
        if (isspace(c)) c = ' ';
        //printf(" help...\n");
        putchar(c);
        //fprintf(fout, "%s", line);
    }


    char *pch;
    pch = strtok (line,  ", ");
    int i = 0;*/
    int i = 0;
    char* line;
    while((fgets(line, sizeof(line), fp1) != NULL))
    {
        c = line[i];
        if(isspace(c)) c = '\n';
        printf("%c", c);
    }

    fprintf(fout, "</pre> \n");
    fprintf(fout,"</body></html>");
    fclose(fp1);

fclose(fout);

return 0;
}
