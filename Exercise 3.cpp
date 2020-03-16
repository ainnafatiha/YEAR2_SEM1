# include <iostream>
# include <cstring>

 using namespace std;

 struct node 
 {
    char data;
    node *next;
 };

 node *top=NULL;
 node *bottom=NULL;
 node *entry;
 node *last_entry;
 node *second_last_entry;

 void push(const char Symbol) 
 {
    entry = new node;
    entry->data = Symbol;
    entry->next = top;
    top = entry;
}


const char pop( )
 {
    if (!top) 
	{
        cout << "\n\n\n\t ***  Error : Stack is empty. \n" << endl;
        return ' ';
	}
    node* entry = top;
    top = top->next;
    char ch = entry->data;
    delete entry;
    return ch;
}

const bool is_empty() 
{
    return !top;
}

void infix_to_postfix(const char *Infix) 
{
    char Infix_expression[100]={NULL};
    char Postfix_expression[100]={NULL};

    strcpy(Infix_expression,"(");
    strcat(Infix_expression,Infix);
    strcat(Infix_expression,")");

    char Symbol[5]={NULL};
    char Temp[5]={NULL};

    for(int count=0;count<strlen(Infix_expression);count++)
	 {
        Symbol[0]=Infix_expression[count];

        if(Symbol[0]=='(')
            push(Symbol[0]);

        else if(Symbol[0]==')') 
		{
           Symbol[0]=pop( );

           while(Symbol[0]!='(')
              {
             strcat(Postfix_expression,Symbol);
			 Symbol[0]=pop( );
              }
        }

        else if(Symbol[0]=='^' || Symbol[0]=='*' || Symbol[0]=='/'
                    || Symbol[0]=='+' || Symbol[0]=='-')
        {
           if(Symbol[0]=='*' || Symbol[0]=='/')
              {
                Temp[0]=pop( );
				while(Temp[0]=='^' || Temp[0]=='*' || Temp[0]=='/')
                 {
                   strcat(Postfix_expression,Temp);

                   Temp[0]=pop( );
                 }

                push(Temp[0]);
              }

           else if(Symbol[0]=='+' || Symbol[0]=='-')
              {
                Temp[0]=pop( );
				while(Temp[0]!='(')
                {
                   strcat(Postfix_expression,Temp);
				   Temp[0]=pop( );
                }

              push(Temp[0]);
              }

          push(Symbol[0]);
        }

         else
        strcat(Postfix_expression,Symbol);
      }

       cout<<"\n\n Postfix Expression : "<<Postfix_expression;
}

 int main( ) 
 {
    char Infix_expression[100]={NULL};
    cout<<"\n\n Enter the Infix Expression : ";
    cin>>Infix_expression;
    infix_to_postfix(Infix_expression);
    return 0;
}

