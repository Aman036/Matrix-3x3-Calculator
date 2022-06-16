#include <stdio.h>
main()
{
    FILE *p;
    char name[100], s;
    int num,nom;

    int a[3][3], b[3][3], c[3][3], i, j, k;
    
    printf("****** 3x3 MATRIX MULTILICATION CALCULATOR ******\n");
before:
    printf("Type 1 to see the history:\nType 2 to solve a problem: \n");
    scanf("%d", &num);
    if (num == 1)
    {
        p = fopen("mul.txt", "r");
        while ((s = fgetc(p)) != EOF)
        {
            printf("%c", s);
        }
        fclose(p);
        goto before;
    }
    else if (num == 2)
    {
        p = fopen("mul.txt", "a+");
        printf("Enter the name who is using this program: \n");
        scanf("%s", name);
        printf("Enter the unique number: \n");
        scanf("%d", &nom);
        fprintf(p, "NAME : %s  NUMBER : %d\n", name,nom);
        fclose(p);
        goto start;
    }
    else
    {
        printf("ENter the correct option");
        goto before;
    }

start:
    printf("Enter the first matrix value:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter a[%d][%d] value: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The first matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    p = fopen("mul.txt", "a+");
    fprintf(p, "The first matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            fprintf(p, "%4d", a[i][j]);
        }
        fprintf(p, "\n");
    }
    fclose(p);

    printf("Enter second matrix value: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter b[%d][%d] value: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    printf("The second matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", b[i][j]);
        }
        printf("\n");
    }

    p = fopen("mul.txt", "a+");
    fprintf(p, "The second matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            fprintf(p, "%4d", b[i][j]);
        }
        fprintf(p, "\n");
    }
    fclose(p);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][i];
            }
        }
    }

    printf("The multiplicated matrix is : \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", c[i][j]);
        }
        printf("\n");
    }

    p = fopen("mul.txt", "a+");
    fprintf(p, "The multiplucated matrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            fprintf(p, "%4d", c[i][j]);
        }
        fprintf(p, "\n");
    }
    fclose(p);
}