#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // For exit()

int main()
{
    int flag = 0;
    int flag2 = 0;
    FILE *fptr;

    char filename[100], c;

    printf("Enter the filename to open \n");
    scanf("%s", filename);

    // Open file
    fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        
        if(c != ' ' ){

            if (flag == 0)
            {
            
                printf("\nToken: ");
                flag = 1;
                flag2 = 0;

            }
            

            printf("%c", toupper(c));

        }
        
        if( c == ' ') 
        {

            if(flag2 == 0 ){

                printf("\n");
                flag2 = 1;
            }
            
            flag = 0;

        }

        if (c == '\n')
        {

            printf("\nToken: ");
            if (flag2 == 0)
            {

                printf("\n");
                
                flag2 = 1;
            }

            flag = 0;
        }

        c = fgetc(fptr);

    }

    fclose(fptr);
    return 0;
}