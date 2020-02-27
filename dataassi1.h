	
//Defining the struct
struct node1
{
	char data;
	struct node1*right;
	struct node1*down;
};

//needed functions
struct node1 *createmolecule1();
void insertdna(struct node1**headr1,struct node1**headr2,char a,int loc);
int len(struct node1**headr1);	
void printmolecule(struct node1**headr1,struct node1**headr2);
void printchain1(struct node1**headr1);
void printchain2(struct node1**headr1);
void deletenucl(struct node1**headr1,struct node1**headr2,int loc);
struct node1* splitmole(struct node1**headr1,struct node1**headr2,int choose);


 
//miscellaneous
void append( struct node1**headr1,struct node1**headr2,char a);
void insertbegin(struct node1** headr1,struct node1**headr2,char a);
void createmolecule(struct node1**headr1,struct node1**headr2,int length);




//defining the needed functions

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
		printf("Invalid character entered\n");
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
			printf("Invalid character entered\n");	
		
	}
	
}

int len(struct node1**headr1)
{
	struct node1*temp;
	int i=0;
	temp=*headr1;
	while(temp!=NULL)
	{
		temp=temp->right;
		i++;
	}
	
	return i;	
}	
		
void printchain(struct node1**headr1)
{
	struct node1* temp;
	temp=*headr1;
	while(temp!=NULL)
	{
		printf("%c->",temp->data);
		temp=temp->right;
	}
	printf("\n");
	temp=*headr1;
	while(temp!=NULL)
	{
		printf("|  ");
		temp=temp->right;
	}
	printf("\n");
}				

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

void printmolecule(struct node1**headr1,struct node1**headr2)
{
	printchain1(headr1);
	printchain2(headr2);
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
	printf("Invalid character entered");		
}		
		
void insertdna(struct node1**headr1,struct node1**headr2,char a,int loc)
{
	
	struct node1*temp1;
	struct node1*temp2;
	int i=1,j;
	temp1=(struct node1*)malloc(sizeof(struct node1));
	temp2=(struct node1*)malloc(sizeof(struct node1));
	
	temp1->data=a;
	temp1->right=NULL;
	temp1->down=NULL;
	temp2->down=NULL;
	struct node1*p1;
	struct node1*p2;
	p1=*headr1;
	p2=*headr2;
	j=len(headr1);
	if(loc>j+1)
	{
		printf("Entered location is invalid\n");
		printf("The molecule consists of only %d nucleotides\n",j);
	}
	else if(loc==1)
	insertbegin(headr1,headr2,a);
	else if(loc==j+1)
	append(headr1,headr2,a);
	else if(loc<1)
	printf("Invalid location entered");
	else
	{
		while(i<loc-1)
		{
			p1=p1->right;
			p2=p2->right;
			i++;
		}	
		if(a=='A')
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='T';
			temp2->right=p2->right;
			p2->right=temp2;
		}
		else if(a=='T')
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='A';
			temp2->right=p2->right;
			p2->right=temp2;
		}
		else if(a=='G')
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='C';
			temp2->right=p2->right;
			p2->right=temp2;
		}
		else if(a=='C')
		{
			temp1->right=p1->right;
			p1->right=temp1;
			temp2->data='G';
			temp2->right=p2->right;
			p2->right=temp2;
		}	
		else
		printf("Invalid nucleotide entered");
	}
}							
		
void createmolecule(struct node1**headr1,struct node1**headr2,int length)
{
	int i=0;
	
	char arr[length];
	printf("Enter the nucleotides\n");
	scanf("%s",&arr);
		
		
		
	
	for(i=0;i<length;i++)
	{
		append(headr1,headr2,arr[i]);
	}	
}		
		
void deletenucl(struct node1**headr1,struct node1**headr2,int loc)
{
	struct node1*temp1,*r1;
	struct node1*temp2,*r2;
	temp1=*headr1;
	temp2=*headr2;
	int i=0,j;
	j=len(headr1);
	if (*headr1==NULL)
	printf("The entered molecule has no nucleotides");
	else if (loc==0)
	{
		*headr1=temp1->right;
		*headr2=temp2->right;
		free(temp1);
		free(temp2);
	}
	else
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
		}
		else
		{
			struct node1*p1=temp1->right->right;	
			struct node1*p2=temp2->right->right;
			free(temp1->right);
			free(temp2->right);
			temp1->right=p1;
			temp2->right=p2;
		}
	}	
}
		
struct node1* splitmole(struct node1**headr1,struct node1**headr2,int choose)
{
	struct node1*p1;
	struct node1*p2;
	struct node1*headr11=NULL;
	struct node1*headr21=NULL;
	struct node1*headr12=NULL;
	struct node1*headr22=NULL;
	p1=*headr1;
	p2=*headr2;
	
	if(p1==NULL)
	{
		printf("There's no molecule to split");
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (choose==1)
		{
			while(p1!=NULL)
			{
				append(&headr11,&headr21,p1->data);
				append(&headr12,&headr22,p1->data);
				p1=p1->right;
				p2=p2->right;
				*headr1=NULL;
				*headr2=NULL;
			}
			return headr11;
		}	
		else if(choose==2)
		{
			while(p1!=NULL)
			{
				append(&headr11,&headr21,p1->data);
				append(&headr12,&headr22,p1->data);
				p1=p1->right;
				p2=p2->right;
				*headr1=NULL;
				*headr2=NULL;
			}
			return headr12;			
		}
		else
		{
			printf("Invalid input");
			exit(EXIT_FAILURE);
		}
	}
						
		
	
	
}		
	
	
	
	
					
			
struct node1* createmolecule1()
{
	
	
	struct node1*alpha=NULL;
	struct node1*beta=NULL;
	//struct molecule*mol=NULL;
	int i,length;
	//mol->headr1=alpha;
	//mol->headr2=beta;
	printf("Enter 1 to enter your nucleotides into alpha chain or 2 to enter them into beta chain\n");
	scanf("%d",&i);
	
	
	
	
	if(i==1)
	{
		printf("Enter the length of the chain you want to create\n");
		scanf("%d",&length);
		createmolecule(&alpha,&beta,length);
		printmolecule(&alpha,&beta);
		return alpha;
		
	}	
		

	else if(i==2)
	{
		printf("Enter the length of the chain you want to create\n");
		scanf("%d",&length);
		createmolecule(&beta,&alpha,length);
		printmolecule(&beta,&alpha);
		return beta;		
	}	
	else
	{
		printf("Invalid input\n");
		exit(EXIT_FAILURE);
	}
	
		
	
	
}	
	
	
			  
		  
		  
			
		
			
		
		
		
			
			
				
		
	
		
	
	
	
		
	
		
				
			
	
		
	
	
		          
										
					
		
		
		
	
