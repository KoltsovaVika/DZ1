#include <stdio.h>

int main()
{
	int *arr,str,stl,i,j;
	char f,k;
	FILE *fl;
	fl=fopen("tet.gv","w");
	fputs("digraph test {\n",fl);
	printf("Enter \n");
	scanf("%d",&str);
	stl=str;
	arr=(int*)malloc(str*stl*sizeof(int));
	for(i=0; i<str; i++)
	{
		f='A';
		k='A';
		f+=i;
		for(j=0; j<stl; j++)
		{
			printf("Enter %c->%c\n", f,k);
			scanf("%d", (arr+i*stl+j));
			if(*(arr+i*stl+j)==1)
			{
				fprintf(fl,"%c->%c\n",f,k);
		    }
			k++;   
	    }
    }
	for(i=0; i<str; i++)
	{
		f='A';
		k='A';
		f+=i;
		for(j=0; j<stl; j++)
		{
			printf("(%c->%c)= %d ",f,k,*(arr+i*stl+j));
			if(j==stl-1)
			{
				printf("\n\n");
			}
			k++;
		}
	}
	fputs("}",fl);
	fclose(fl);
		return 0;
}
