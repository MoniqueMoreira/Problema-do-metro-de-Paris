# include <stdio.h>
# include <stdlib.h>

void imprimirM(int matriz[14][14])
{
    for (int i=0; i<14;i++)
    {
        for(int j=0;j<14;j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    return;
}
