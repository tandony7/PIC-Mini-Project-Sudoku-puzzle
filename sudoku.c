/**
Code Author: Yash Tandon
Guided By: Vaibhav Vasani
College: K J Somaiya College of Engineering
Date of Submission: 12-05-2019
*/
#include<stdio.h>
void selectpuzzle();
int checkrows();
int checkcolumns();
int checkboxes();
int a[9][9];
void main()
{
    int i,j,r,c,f,g,h,m=186,n=205,o=206,x=1,b[9][9];
    selectpuzzle();
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)//Meant to store positions of fixed/pre-entered numbers.
        {
            if(a[i][j]==0)
                b[i][j]=0;
            else
                b[i][j]=1;
        }
    }
    while(x==1)
    {
        for(i=0;i<9;i++)//Displaying the sudoku puzzle
        {
            if(i==0)
            {
                printf(" ");
                for(j=1;j<=9;j++)
                {
                    if(j%3==1)
                    printf("  %d ",j);
                    else
                        printf("%d ",j);
                }
                printf("\n\n");
            }
            printf("%d  ",i+1);
            for(j=0;j<9;j++)
            {
                printf("%d ",a[i][j]);
                if(j==2 || j==5)
                    printf("%c ",m);
            }
            printf("\n");
            if(i==2 || i==5)
            {
                printf("   ");
                for(j=0;j<11;j++)
                {
                    if(j==3 || j==7)
                    printf("%c%c",o,n);
                    else
                    printf("%c%c",n,n);
                }
                printf("\n");
            }
        }
        for(;;)//Conditions for solving a sudoku
        {
        printf("Enter row number:");
        scanf("%d",&r);
        printf("Enter column number:");
        scanf("%d",&c);
        if(r<1 || r>9 || c<1 ||c>9)
        {
            printf("Invalid choice please enter again.");
            continue;
        }
        r--;
        c--;
        if(b[r][c]==0)
        break;
        else
        printf("Fixed position. Enter again.\n");
        }
        for(;;)
        {
        printf("Enter number from 1 to 9:");
        scanf("%d",&a[r][c]);
        if(a[r][c]<1 || a[r][c]>9)
            printf("Invalid input. Please enter again.");
        else
            break;
        }
        printf("Enter 1 to continue solving:");
        scanf("%d",&x);
    }
    for(i=0;i<9;i++)
        {
            if(i==0)
            {
                printf(" ");
                for(j=1;j<=9;j++)
                {
                    if(j%3==1)
                    printf("  %d ",j);
                    else
                        printf("%d ",j);
                }
                printf("\n\n");
            }
            printf("%d  ",i+1);
            for(j=0;j<9;j++)
            {
                printf("%d ",a[i][j]);
                if(j==2 || j==5)
                    printf("%c ",m);
            }
            printf("\n");
            if(i==2 || i==5)
            {
                printf("   ");
                for(j=0;j<11;j++)
                {
                    if(j==3 || j==7)
                    printf("%c%c",o,n);
                    else
                    printf("%c%c",n,n);
                }
                printf("\n");
            }
        }
    f=checkrows();
    g=checkcolumns();
    h=checkboxes();
    if(f==0 || g==0 || h==0)
    {
        printf("Sudoku incorrectly solved.");
    }
    else
    {
        printf("Sudoku correctly solved.");
    }
}
void selectpuzzle()
{
    int ch,i,j;
    int a1[9][9]={{0,1,0,0,0,0,0,0,3},{3,0,0,5,0,4,8,0,0},{0,0,2,0,6,0,0,9,7},{9,0,0,0,3,0,0,4,6},{0,3,7,0,0,2,0,5,0},{8,0,0,7,1,0,0,0,0},{0,4,5,0,7,0,2,0,0},{0,0,0,4,0,8,0,1,0},{0,6,0,0,0,9,3,0,4}};
    int a2[9][9]={{7,0,0,9,0,3,4,0,2},{4,0,9,0,0,2,0,0,0},{0,0,8,1,0,0,5,6,0},{0,1,3,0,6,5,8,7,0},{0,8,0,3,0,0,0,9,0},{2,0,0,0,4,0,0,0,3},{6,4,0,0,3,0,0,2,0},{0,0,0,7,9,8,0,0,5},{0,9,5,0,0,0,3,1,0}};
    int a3[9][9]={{0,0,3,0,5,0,4,0,0},{2,0,0,8,0,9,6,5,0},{0,0,1,7,0,0,0,0,3},{8,0,9,4,0,0,0,3,0},{0,0,0,6,0,5,1,0,0},{7,0,6,0,1,0,0,0,2},{0,4,0,0,0,2,0,0,0},{0,6,5,1,0,0,8,0,9},{9,0,0,0,0,3,7,0,0}};
    for(;;)
    {
    printf("Enter 1, 2 or 3 to select respective puzzle:");
    scanf("%d",&ch);
    if(ch<=3 && ch>=1)
    break;
    else
    printf("Invalid choice.");
    }
    switch(ch)
    {
    case 1:
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            a[i][j]=a1[i][j];
        }
    }
    break;
    case 2:
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            a[i][j]=a2[i][j];
        }
    }
    break;
    case 3:
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            a[i][j]=a3[i][j];
        }
    }
    break;
    }
}
int checkrows()
{
    int i,j,k,x;
    for(i=0;i<9;i++)
    {
        for(j=1;j<=9;j++)
        {
            x=0;
            for(k=0;k<9;k++)
            {
                if(a[i][k]==j)
                   x++;
            }
            if(x!=1)
                return 0;
        }
    }
    return 1;
}
int checkcolumns()
{
    int i,j,k,x;
    for(i=0;i<9;i++)
    {
        for(j=1;j<=9;j++)
        {
            x=0;
            for(k=0;k<9;k++)
            {
                if(a[k][i]==j)
                   x++;
            }
            if(x!=1)
                return 0;
        }
    }
    return 1;
}
int checkboxes()
{
    int i,j,k,l,m,x;
    for(i=0;i<9;i+=3)
    {
        for(j=0;j<9;j+=3)
        {
            for(k=1;k<=9;k++)
            {
                x=0;
                for(l=i;l<i+3;l++)
                {
                    for(m=j;m<j+3;m++)
                    {
                        if(a[l][m]==k)
                            x++;
                    }
                }
                if(x!=1)
                    return 0;
            }
        }
    }
    return 1;
}
