#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void genere_cellules(int cellule[4][6]);
int main()
{
    int i,j;
    int cellule[4][6]={0};
    genere_cellules(cellule);
    for (i=0;i<4;i++)
    {
        printf("\n");
        for (j=0;j<6;j++)
        {
            printf("%d ",cellule[i][j]);
        }
    }
        return 0;
}
void genere_cellules(int cellule[4][6])
{
    int i,j,a,b,t,M;
    srand (time(NULL));
    for (i=0;i<4;i++)
    {
        for (j=0;j<6;j++)
        {
            M=rand()%24;
            t=0;
            for (a=0;a<4;a++)
                {
                    for (b=0;b<6;b++)
                    {
                        if (M==cellule[a][b])
                        {
                                while (t==0)
                                {
                                    M=rand()%24;
                                 
                                    for (a=0;a<4;a++)
                                    {
                                        for (b=0;b<6;b++)
                                        {
                                            if (M==cellule[a][b])
                                            {
                                                t=0;
                                            }
                                            else
                                            {
                                                t=1;
                                                cellule[i][j]=M;
                                                 
                                            }
                                        }
                                    }
                                }
                            }
                        else
                        {
                            cellule[i][j]=M;
                        }
                    }
                }
            }
        }
}