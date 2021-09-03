#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char buff[255];
    fp = fopen("CRLRelatorio.txt", "r");
    for (int i = 0; i < 20; i++)
    {
        int ret = fgets(buff, 255, (FILE*)fp);
        if(ret != NULL)
        {
            printf("%d: %s\n", ret, buff );
        }
        else
        {
            i = 20;
        }
    }
    fclose(fp);

    return 0;
}