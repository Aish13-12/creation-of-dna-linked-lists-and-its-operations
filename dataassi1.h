//THIS FILE IS SAVED WITH A .h FORMAT.THIS FILE WILL BE INCLUDED AS A HEADER FILE IN THE TEST FILE.	
//Defining the struct
struct node1
{
	char data;
	struct node1*right;
	struct node1*down;
};

struct node1*arr[1000];
int h=0;


//needed functions
void createmolecule1();
void insertnucleo();
void deletenucleo();
void printmolecule1();
void printallmolecules();
void splitmolecule();
void insertdna(struct node1**headr1,struct node1**headr2,char a,int loc);
int len(struct node1**headr1);	
void printmolecule(struct node1**headr1,struct node1**headr2);
void printchain1(struct node1**headr1);
void printchain2(struct node1**headr1);
void deletenucl(struct node1**headr1,struct node1**headr2,int loc);
struct node1* splitmole(struct node1**headr1,struct node1**headr2);



 
//miscellaneous
void append( struct node1**headr1,struct node1**headr2,char a);
void insertbegin(struct node1** headr1,struct node1**headr2,char a);
void createmolecule(struct node1**headr1,struct node1**headr2,int length);
void appendchain(struct node1**headr,char a);




//defining the needed functions

//Function for creating a molecule
void createmolecule1()
{
	
	//Creating two head/root  pointers for the two chains in DNA
	struct node1*alpha=NULL;
	struct node1*beta=NULL;
	int length;
	printf("Enter the length of the chain you want to create\n");
	scanf("%d",&length);
	createmolecule(&alpha,&beta,length);//Calling createmolecule function defined below
	arr[h]=alpha;
	
	printf("A molecule with chain id %d has been created\n",h+1);
	h++;
		
}

void insertnucleo()
{
	int k,l;
	int s;
	char z;
	printf("Enter the molecule id\n");
	scanf("%d",&k);
	printf("\nEnter the nucleotide you want to insert\n");
	scanf(" %c",&z);
	printf("Enter the location at which you want to insert\n");
	scanf("%d",&l);
	printf("Enter the chain id(1 for alpha and 2 for beta chain)\n");
	scanf("%d",&s);
	if (s==1)
	insertdna(&arr[k-1],&arr[k-1]->down,z,l);
	else if(s==2)
	insertdna(&arr[k-1]->down,&arr[k-1],z,l);
	else
	printf("Invalid input\n");
	
	
}	

void deletenucleo()
{
	int k,l;
	int s;
	
	printf("Enter the molecule id\n");
	scanf("%d",&k);
	
	printf("Enter the location at which you want to delete:\n");
	scanf("%d",&l);
	
	
	deletenucl(&arr[k-1],&arr[k-1]->down,l);
	
	
	
}	

void printmolecule1()
{
	int g;
	printf("Enter molecule id\n");
	scanf("%d",&g);
	if(g-1>=h)
	printf("Selected molecule does not exist\n");
	else
	printmolecule(&arr[g-1],&arr[g-1]->down);
}	
	
void printallmolecules()
{
	int i=0;
	while(arr[i]!=NULL)
	{
		printf("Molecule id:%d\n\n",i+1);
		printmolecule(&arr[i],&arr[i]->down);
		printf("\n");
		
		i++;
	}
}		
	
//Defing a function to insert nucleotides into chain

void insertdna(struct node1**headr1,struct node1**headr2,char a,int loc)
{
	
//Defining temporary variables to hold the data entered and its conjugate in the DNA	
	struct node1*temp1;
	struct node1*temp2;
	int i=1,j;//Defining two integer variables
	temp1=(struct node1*)malloc(sizeof(struct node1));
	temp2=(struct node1*)malloc(sizeof(struct node1));
	//Entering the data given into the newly created node
	temp1->data=a;
	temp1->right=NULL;
	temp1->down=NULL;
	temp2->down=NULL;
	struct node1*p1;//creating local pointer variables to traverse through the linked list/molecule
	struct node1*p2;
	p1=*headr1;//Initializing the local pointer variables
	p2=*headr2;
	j=len(headr1);//Finding the length of the molecule by using the "len" function defined below and storing it in the integer variable
	if(loc>j+1)//Notifying the user if the entered value of location is more than the number of nucleotides in the molecule
	{
		printf("\nEntered location is invalid\n");
		printf("The molecule consists of only %d nucleotides\n",j);
	}
	else if(loc==1)//If location value is 1 the using the "insertbegin" function defined below
	insertbegin(headr1,headr2,a);
	else if(loc==j+1)//To add at the end of the molecule using the append gunction defined below
	append(headr1,headr2,a);
	else if(loc<1)//Notifying the user if the entered location value is less than 1
	printf("\nInvalid location entered\n");
	else
	{
		while(i<loc-1)//Traversing through both the chains until we reach the node present in the location just before the location specified 
		{
			p1=p1->right;
			p2=p2->right;
			i++;
		}	
		if(a=='A')//If the entered character is A then T should be the other nucleotide in the corresponding node in the other chain
		{
			temp1->right=p1->right;//Inserting the new node 
			p1->right=temp1;
			temp2->data='T';
			temp2->right=p2->right;
			p2->right=temp2;
			printf("\nEntered nucleotide has been inserted\n");
		}
		else if(a=='T')
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='A';
			temp2->right=p2->right;
			p2->right=temp2;
			printf("\nEntered nucleotide has been inserted\n");
		}
		else if(a=='G')//If the entered character is G then C should be the other nucleotide in the corresponding node in the other chain
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='C';
			temp2->right=p2->right;
			p2->right=temp2;
			printf("\nEntered nucleotide has been inserted\n");
		}
		else if(a=='C')
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='G';
			temp2->right=p2->right;
			p2->right=temp2;
			printf("\nEntered nucleotide has been inserted\n");
		}	
		else//Notifying the user if the entered character is neither among the characters A,T,G,C.
		printf("\nInvalid nucleotide entered\n");
	}
}
//Function to obtain the length of the molecule

int len(struct node1**headr1)
{
	struct node1*temp;//Defining a temporary variable to traverse through the loop
	int i=0;//Initializing the integer variable
	temp=*headr1;
	while(temp!=NULL)//Traversing through the loop until we reach the last node
	{
		temp=temp->right;
		i++;//Increasing the integer value as we traverse
	}
	
	return i;//returning the value of i which is the length of the molecule to the function	
}

//Function to print a molecule
void printmolecule(struct node1**headr1,struct node1**headr2)
{
	
	printchain1(headr1);
	printchain2(headr2);
}



//Functions to print a chain		
void printchain1(struct node1**headr1)
{
	struct node1* temp;
	temp=*headr1;//Creating a temporary variable to traverse through the chain
	while(temp!=NULL)//Traversing through the chain until the last node
	{
		printf("%c->",temp->data);//While traversing printing the nucleotides in the chain
		temp=temp->right;
	}
	printf("\n");
	temp=*headr1;
	while(temp!=NULL)
	{
		printf("|  ");//While traversing printing the links below the nucleotides in the chain
		temp=temp->right;
	}
	printf("\n");
}				
//This function is similar to the previous one but is used to print the links above the nucleotides
void printchain2(struct node1**headr2)
{
	struct node1* temp;
	temp=*headr2;
	
	while(temp!=NULL)
	{
		printf("|  ");
		
		
		temp=temp->right;
	}
	printf("\n");
	temp=*headr2;
	while(temp!=NULL)
	{
		printf("%c->",temp->data);
		
		temp=temp->right;
	}
	
	
	printf("\n");
}				
//Function to delete a nucleotide pair in a given location
void deletenucl(struct node1**headr1,struct node1**headr2,int loc)
{
	struct node1*temp1,*r1;//Defining local struct node variables
	struct node1*temp2,*r2;
	temp1=*headr1;//Initializing two local struc variables to travers through the chain
	temp2=*headr2;
	int i=0,j;
	j=len(headr1);//Finding the length of the given molecule using "len" defined above
	if (*headr1==NULL)//Notifying the user if the given molecule has no nucleotides to delete
	printf("\nThe entered molecule has no nucleotides\n");
	else if (loc==1)
	{
		*headr1=temp1->right;
		*headr2=temp2->right;
		free(temp1);
		free(temp2);
	}
	else if(loc>1)
	{
		for(i=1;temp1!=NULL && i<loc-1;i++)
		{
			r1=temp1;
			temp1=temp1->right;
			r2=temp2;
			temp2=temp2->right;
		}
		if(temp1==NULL)
		{
			printf("\nEntered location is not valid\n");
			printf("The molecule consists of %d pairs of nucleotides\n",j);
		}
		else if(temp1->right==NULL)
		{
			r1->right=NULL;
			r2->right=NULL;
			free(temp1);
			free(temp2);
			printf("The nucleotide in the entered location has been deleted.\n");
		}
		else
		{
			struct node1*p1=temp1->right->right;	
			struct node1*p2=temp2->right->right;
			free(temp1->right);
			free(temp2->right);
			temp1->right=p1;
			temp2->right=p2;
			printf("The nucleotide in the entered location has been deleted.\n");			
		}
	}
	else
	printf("\nInvalid location\n");	
}	
void append( struct node1**headr1,struct node1**headr2,char a)
{
	
	
	struct node1*temp1;
	struct node1*temp2;
	temp1=(struct node1*)malloc(sizeof(struct node1));
	temp2=(struct node1*)malloc(sizeof(struct node1));
	
	temp1->data=a;
	temp1->right=NULL;
	temp1->down=NULL;
	temp2->down=NULL;

	
	if(*headr1==NULL)
	{
		if(a=='A')
		{
			
			*headr1=temp1;
			temp2->data= 'T';
			temp2->right=NULL;
			*headr2=temp2;
			temp1->down=temp2;
			temp2->down=temp1;
			
		}
		else if(a=='T')
		{
			
			*headr1=temp1;
			temp2->data= 'A';
			temp2->right=NULL;
			*headr2=temp2;
			temp1->down=temp2;
			temp2->down=temp1;
			
		}
		else if(a=='G')
		{
			
			*headr1=temp1;
			temp2->data= 'C',
			temp2->right=NULL;
			*headr2=temp2;
			temp1->down=temp2;
			temp2->down=temp1;
			
		}
		else if(a=='C')
		{
			
			*headr1=temp1;
			temp2->data= 'G';
			temp2->right=NULL;
			*headr2=temp2;
			temp1->down=temp2;
			temp2->down=temp1;
			
			
		}
		else
		printf("\nInvalid character entered\n");
	}													
	else
	{
			struct node1*p1	;
			struct node1*p2;
			p1=*headr1;
			p2=*headr2;
			
			
			while(p1->right!=NULL)
			{
				p1=p1->right;
			}
			while(p2->right!=NULL)
			{
				p2=p2->right;
			}
			
			if(a=='A')
			{
				temp1->data=a;
				p1->right=temp1;
				temp2->data='T';
				p2->right=temp2;
				temp1->down=temp2;
				temp2->down=temp1;
				
			}
			else if(a=='T')
			{
				temp1->data=a;
				p1->right=temp1;
				temp2->data='A';
				p2->right=temp2;
				temp1->down=temp2;
				temp2->down=temp1;								
			}
			else if(a=='G')
			{
				temp1->data=a;
				p1->right=temp1;
				temp2->data='C';
				p2->right=temp2;
				temp1->down=temp2;
				temp2->down=temp1;
			}
			else if(a=='C')
			{
				temp1->data=a;
				p1->right=temp1;
				temp2->data='G';
				p2->right=temp2;
				temp1->down=temp2;
				temp2->down=temp1;
			}	
			else
			printf("\nInvalid character entered\n");	
		
	}
	
}

	
	
void insertbegin(struct node1** headr1,struct node1**headr2,char a)
{
	struct node1* temp1=NULL;
	struct node1* temp2=NULL;
	temp1=(struct node1*)malloc(sizeof(struct node1));
	temp2=(struct node1*)malloc(sizeof(struct node1));
	
	temp1->data=a;
	temp1->right=NULL;
	temp1->down=NULL;
	if(a=='A')
	{
		temp1->right=*headr1;
		*headr1=temp1;
		temp2->data='T';
		temp2->right=*headr2;
		*headr2=temp2;
		temp1->down=temp2;
		temp2->down=temp1;
	}	
	else if(a=='T')
	{
		temp1->right=*headr1;
		*headr1=temp1;
		temp2->data='A';
		temp2->right=*headr2;
		*headr2=temp2;
		temp1->down=temp2;
		temp2->down=temp1;
	}	
	else if(a=='G')
	{
		temp1->right=*headr1;
		*headr1=temp1;
		temp2->data='C';
		temp2->right=*headr2;
		*headr2=temp2;
		temp1->down=temp2;
		temp2->down=temp1;
	}	
	else if(a=='C')
	{
		
		temp1->right=*headr1;
		*headr1=temp1;
		temp2->data='G';
		temp2->right=*headr2;
		*headr2=temp2;
		temp1->down=temp2;
		temp2->down=temp1;
	}		
	else
	printf("\nInvalid character entered\n");		
}		
		
							
		
void createmolecule(struct node1**headr1,struct node1**headr2,int length)
{
	int i=0;
	
	char arr[length];
	printf("\nEnter the nucleotides\n");
	scanf("%s",&arr);
		
	for(i=0;i<length;i++)
	{
		append(headr1,headr2,arr[i]);
	}	
}		

void splitmolecule()
{
	int x;
	struct node1*d;
	printf("Enter the molecule id\n");
	scanf("%d",&x);
	if(x-1>=h)
	printf("Selected molecule does not exist\n");
	else
	{
		d=splitmole(&arr[x-1],&arr[x-1]->down);	
		arr[h]=d;
		printf("The molecule has been split and its daughter molecule has the id %d\n",h+1);
		h++;
	}	
	
	
	
	
}		

		
struct node1* splitmole(struct node1**headr1,struct node1**headr2)
{
	struct node1*temp1=NULL;
	struct node1*temp2=NULL;
	
	struct node1*p1=*headr1;
	struct node1*p2=*headr2;
	
	
	
	while(p1!=NULL)
	{
			
		appendchain(&temp1,p2->data);
		
		appendchain(&temp2,p1->data);
		//p1->down=NULL;
		//p2->down=NULL;
		p1=p1->right;
		p2=p2->right;
	}
	struct node1*l1=*headr1;
	struct node1*l2=*headr2;
	struct node1*f1=temp1;
	struct node1*f2=temp2;
	
	while(l1!=NULL)
	{
		
		l1->down=f1;
		f1->down=l1;
		l2->down=f2;
		f2->down=l2;				
		l1=l1->right;
		l2=l2->right;
	    f1=f1->right;
		f2=f2->right;
	}
	return temp2;
	
}		

	
		
		
		
		
		
	

		
			
					
				
				
				
				
void appendchain(struct node1**headr,char a)
{
	struct node1*temp;
	temp=(struct node1*)malloc(sizeof(struct node1));
	temp->data=a;
	temp->right=NULL;
	temp->down=NULL;
	if(*headr==NULL)
	*headr=temp;
	else
	{
		struct node1*p=*headr;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		
		p->right=temp;
	}
		
}					
			
			
				
							
			
		
		

			
	
	
	
			  
		  
		  
			
		
			
		
		
		
			
			
				
		
	
		
	
	
	
		
	
		
				
			
	
		
	
	
		          
										
					
		
		
		
	
