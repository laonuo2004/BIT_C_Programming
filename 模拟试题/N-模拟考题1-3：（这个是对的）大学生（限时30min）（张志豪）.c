#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct STU{
	char name[6];
	int num;
	struct STU* next;
};
int main() {
	int n;
	scanf("%d",&n);
	int a[n];
	typedef struct STU stu;
	stu *head;
	head=(stu*)malloc(sizeof(stu));
	head->next=NULL;
	strcpy(head->name,"eijuy");
	stu *p,*q;
	for (int i=0;i<n;i++) {
		scanf("%d ",&a[i]);
	}
	p=head;
	for (int i=0;i<=n;i++) {
		
		if (i<n) {
			q=(stu*)malloc(sizeof(stu));
			q->num=i+1;
			scanf("%s",q->name);
			p->next=q;
			p=p->next;
			q->next=NULL;
		}
		else {
			q=(stu*)malloc(sizeof(stu));
			strcpy(q->name,"vrqfb");
			p->next=q;
			p=p->next;
			q->next=NULL;
		}
	}
	for (int i=0;i<n;i++) {
		p=head;
		while (p->next->num!=a[i]) {
			p=p->next;
		}
		printf("%s %s\n",p->name,p->next->next->name);
		
		q=p->next;
		p->next=p->next->next;
		free(q);
	}
}