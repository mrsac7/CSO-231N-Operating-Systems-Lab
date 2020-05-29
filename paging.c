#include<stdio.h>
int main()
{
	int memsize;
	printf("Enter the logical memory size:");
	scanf("%d",&memsize);
	int pagesize, nofpage, p[100] = {0}, pageno,offset, logadd, phyadd, i, choice=0;
	printf("\nYour memsize is %d ", memsize);
	printf("\nEnter page size: ");
	scanf("%d", &pagesize);

	nofpage = memsize / pagesize;

	for(i = 0; i < nofpage; i++) {
		printf("\nEnter the frame of page%d: ",i+1);
		scanf("%d", &p[i]);
	}

	do {
		printf("\nEnter a logical address:");
		scanf("%d",&logadd);
		pageno = logadd / pagesize;
		offset = logadd % pagesize;
		phyadd = p[pageno] * pagesize + offset;
		if (logadd >= 0 && logadd < memsize) printf("\nPhysical address is:%d",phyadd);
		else printf("Error!!!Enter valid logical address...");

		printf("\nDo you want to continue(1/0)?:");
		scanf("%d",&choice);
	} while(choice == 1);
}