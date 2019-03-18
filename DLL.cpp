#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h> 
#include<stdio.h>
using namespace std;
struct emp{
	char SSN[12];
	char fname[50];
	char dept[50];
	char designation[50];
	float salary;
	int phone_no;
	struct emp *llink;
	struct emp *rlink;

};
typedef struct emp EMP;

EMP *read_data()
{

	int phone_no;
	float salary;
	EMP *temp;
	temp=(EMP*)malloc(sizeof(EMP));
	cout<<"Enter the Employees Details \n";
	cout<<"Enter the SSN\n";
	cin>>temp->SSN;
	cout<<"Enter the First Name\n";
	cin>>temp->fname;
	cout<<"Enter the Department\n";
	cin>>temp->dept;
	cout<<"Enter the Designation\n";
	cin>>temp->designation;
	cout<<"Enter the Salary\n";
	cin>>temp->salary;
	cout<<"Enter the Phone Number\n";
	cin>>temp->phone_no;
	temp->rlink=NULL;
	temp->llink=NULL;
	return temp;
}

EMP *insert_front(EMP *head)
{
	EMP *temp, *next;
	temp=read_data();
	if(head->rlink!=NULL)
	{
		next=head->rlink;
		head->rlink=temp;
		temp->llink=head;
		next->llink=temp;
		temp->rlink=next;
	}
	else
	{
		temp->llink=head;
		head->rlink=temp;
		temp->rlink=NULL;
	}
	return head;
}

EMP *delete_end(EMP *head)
{
	EMP *cur,*prev;
	if(head->rlink==NULL)
	cout<<"List is empty"<<endl;
	else
	{
		cur=head->rlink;
		
		if(cur->rlink==NULL)
		head->rlink=NULL;
		else
		{
			while(cur->rlink!=NULL)
			{
				prev=cur;
				cur=cur->rlink;
			}
			prev->rlink=NULL;	
		}
		free(cur);
	}
	return head;
}

EMP *delete_front(EMP *head)
{
	EMP *cur,*next;
	if(head->rlink==NULL)
	cout<<"List is empty|n";
	else
	{
		cur=head->rlink;
		if(cur->rlink==NULL)
		head->rlink=NULL;
		else
		{
			next=cur->rlink;
			next->llink=head;
			head->rlink=next;
		}
		free(cur);
	}
	return head;
}

EMP *insert_end(EMP *head)
{
	EMP *cur,*temp;
	temp=read_data();
	cur=head;
	while(cur->rlink!=NULL)
	cur=cur->rlink;
	cur->rlink=temp;
	temp->llink=cur;
	temp->rlink=NULL;
	return head;
}

void display(EMP *head)
{
	EMP*cur;
	int count=0;
	if(head->rlink==NULL)
	cout<<"List is empty\n"<<endl;
	else
	{
		cur=head->rlink;
		cout<<"SSN\tName \tDepartment \tDesignation \tSalary \tPhone_No\n"<<endl;
		while(cur!=NULL)
		{
			cout<<cur->SSN<<" \t"<<cur->fname<<"\t"<<cur->dept<<"\t"<<cur->designation<<"\t"<<cur->salary<<"\t"<<cur->phone_no<<endl;
			cur=cur->rlink;
			count++;
		}
		cout<<"Number of nodes is ="<<count<<endl;
	}
}


int main()
{
	int ch,n,i;
	EMP *head;
	head=(EMP*)malloc(sizeof(EMP));
	head->rlink=head->llink=NULL;
	cout<<"Creation of DLL\n";
	cout<<"Enter number of employees\n";
	cin>>n;
	for(i=1;i<=n;i++)
		head=insert_end(head);
	while(1)
	{
		cout<<"1.Display\n2.Insert End\n3.Delete end\n4.Insert front\n5.Delete front\n6.Exit\n";
		cout<<"Enter the choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:display(head);
				break;
			
			
			
			case 2:head=insert_end(head);
				cout<<"Node inserted at end"<<endl;
				break;
			
			
			
			case 3:head=delete_end(head);
				cout<<"Node deleted at end"<<endl;
				break;
			
			
			case 4:head=insert_front(head);
				cout<<"Node inserted at front"<<endl;
				break;
			
			
			
			case 5:head=delete_front(head);
				cout<<"Node deleted at front"<<endl;
				break;
		
			
			case 6:exit(0);
		}
	}
}







