// C program to reverse a 
// stack using recursion 
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define bool int 


typedef char str[100];
// structure of a stack node
struct datas
{
	str uid;
	int pid;
	int ppid;
	int c;
	str stime;
	str tty;
	str time;
	str cmd;
};

struct sNode 
{ 
	struct datas info; 
	struct sNode *next; 
}; 

// Function Prototypes 
void push(struct sNode** top_ref, struct datas new_data); 
struct datas pop(struct sNode** top_ref); 
bool isEmpty(struct sNode* top); 
void print(struct sNode* top); 

// Below is a recursive function 
// that inserts an element 
// at the bottom of a stack. 
void insertAtBottom(struct sNode** top_ref, struct datas item) 
{ 
	struct datas temp;
	
	if (isEmpty(*top_ref)) 
		push(top_ref, item); 
	else
	{ 

		// Hold all items in Function Call 
		// Stack until we reach end of the 
		// stack. When the stack becomes 
		// empty, the isEmpty(*top_ref)becomes 
		// true, the above if part is executed 
		// and the item is inserted at the bottom 
		temp = pop(top_ref); 
		insertAtBottom(top_ref, item);

		// Once the item is inserted 
		// at the bottom, push all 
		// the items held in Function 
		// Call Stack 
		push(top_ref, temp); 
	} 
} 

// Below is the function that 
// reverses the given stack using 
// insertAtBottom() 
void reverse(struct sNode** top_ref) 
{ 	
	struct datas temp;
	
	if (!isEmpty(*top_ref)) 
	{ 
		// Hold all items in Function 
		// Call Stack until we 
		// reach end of the stack 
		temp = pop(top_ref);
		reverse(top_ref); 
		// Insert all the items (held in 
		// Function Call Stack) 
		// one by one from the bottom 
		// to top. Every item is 
		// inserted at the bottom 
		insertAtBottom(top_ref, temp); 
	} 
} 

// Driver Code 
int main() 
{ 
	struct sNode *s = NULL;
	struct datas new_one[1000];
	FILE *filer = fopen("data.txt","r");
	int count=0;
	
	if(filer == NULL)
	{
		puts("ERROR");
		fclose(filer);
		exit(0);
	}
	
	while(!feof(filer))
	{
		fscanf(filer,"%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s",
		&new_one[count].uid,
		&new_one[count].pid,
		&new_one[count].ppid,
		&new_one[count].c,
		&new_one[count].stime,
		&new_one[count].tty,
		&new_one[count].time,
		&new_one[count].cmd);
		
		count++;	
	}
	
	
	fclose(filer);
	
	while(0 <= count){
		push(&s,new_one[count]);
		count--;
	}

	printf("\t\t\tORIGINAL STACK\n");
	print(s); 
	reverse(&s); 
	printf("\n\t\t\tREVERSED STACK\n "); 
	print(s); 
	return 0; 
} 

// Function to check if 
// the stack is empty 
bool isEmpty(struct sNode* top) 
{ 
	return (top == NULL)? 1 : 0; 
} 

// Function to push an item to stack 
void push(struct sNode** top_ref, struct datas new_data) 
{ 
	
	// allocate node 
	struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode)); 

	if (new_node == NULL) 
	{ 
		printf("Stack overflow \n"); 
		exit(0); 
	} 

	// put in the data
	new_node->info.c = new_data.c;
	strcpy(new_node->info.cmd,new_data.cmd);
	new_node->info.pid = new_data.pid;
	new_node->info.ppid = new_data.ppid;
	strcpy(new_node->info.stime,new_data.stime);
	strcpy(new_node->info.time,new_data.time);
	strcpy(new_node->info.tty,new_data.tty);
	strcpy(new_node->info.uid,new_data.uid);
	
	
	
	// link the old list 
	// off the new node 
	new_node->next = (*top_ref); 

	// move the head to 
	// point to the new node 
	(*top_ref) = new_node; 
}

// Function to pop an item from stack 
struct datas pop(struct sNode** top_ref) 
{ 
	struct datas res; 
	struct sNode *top; 

	// If stack is empty then error 
	if (*top_ref == NULL) 
	{ 
		printf("Stack overflow \n"); 
		exit(0); 
	} 
	else
	{ 
		top = *top_ref; 
		res = top->info; 
		*top_ref = top->next; 
		free(top); 
		return res; 
	} 
} 

// Function to print a 
// linked list 
void print(struct sNode* top) 
{ 
	printf(" UID PID PPID C  STIME TTY  TIME\tCMD\n"); 
	
	while (top != NULL) 
	{ 
		printf("%s\t%d\t%d\t%d\t%s\t%s\t%s\t%s\n", 
		top->info.uid,
		top->info.pid,
		top->info.ppid,
		top->info.c,
		top->info.stime,
		top->info.tty,
		top->info.time,
		top->info.cmd);
		
		top = top->next; 
	} 
} 

