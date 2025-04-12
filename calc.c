
#include "STD_TYPES.h"
#include <util/delay.h>
#include "KPD_interface.h"
#include "LCD_interface.h"

#define MAX_SIZE 100

typedef struct {
    u8 Data[MAX_SIZE];
    int top;
} Stack;



static void stack_init    (Stack *List);
static u8 stack_isEmpty   (Stack *List);
static u8 stack_isFull    (Stack *List);
static u8 stack_Top       (Stack *List);
static void stack_Pop     (Stack * List);
static void stack_Push    (Stack * List, u8 Data);
static float Calc_res     (u8 num1, u8 num2, u8 Operator);
static u8 Get_Length(float Number);
static void evaluate(void);

u8 infix[60];
static u8 postfix[100];
LCD_8bit lcd ;


static void stack_init(Stack *List)
{
	List->top = 0;
}

static u8 stack_isEmpty (Stack *List)
{
	return List->top == 0;
}

static u8 stack_isFull (Stack *List)
{
	return List->top >= MAX_SIZE;
}

static void stack_Push(Stack * List, u8 Data)
{
	List->Data[(List->top)++] = Data;
}

static void stack_Pop(Stack * List)
{
	(List->top)--;
}

static u8 stack_Top(Stack *List)
{
	return (List->Data[List->top - 1]);
}




static u8 priority (u8 Operator)
	 {
	 	switch (Operator)
	 	{
	 	case '*' :
	 	case '/' : return 2;
	 	case '+' :
	 	case '-' : return 1;
	 	}
	 }

static uint8_t Get_Length(float Number)
{
	uint8_t str[10] = {0};
	int Decimal;
	Decimal = (int)Number;
	sprintf(str, "%d", Decimal);
	volatile uint8_t length = 0;
	while(str[length++] != '\0');
	return length;
}

void infixToPostfix(u8 *infix, u8 *postfix) {
    Stack s;
    stack_init(&s);
    int i, j = 0;
    u8 ch, x;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if ((ch <= '9' && ch >= '0') || ch == '.' )
        {
            while ((ch <= '9' && ch >= '0'))
            {
            	postfix[j++] = ch;
            	ch = infix[++j];
            }
            postfix[i++] = ' ';
        }

        else if (ch == '(')
        {
            stack_Push(&s, ch);
        }

        else if (ch == ')')
        {
        	while ((x = pop(&s)) != '(')
        	{
        		postfix[j++] = x;
        	}
        }

        else
        {

        	while(!(stack_isEmpty(&s)) && priority(ch) <= priority(static_Top(&s)))
        	            			{
        	            				postfix[i++] = stack_Top(&s);
        	            				static_Pop(&s);
        	            			}
        }


	static float Calc_res(u8 num1, u8 num2, u8 Operator)
	{
		 switch (Operator)
		  {
		  case '+' :
		      return num1+num2 ;
		      break;
		  case '-' :
			  return num1-num2 ;
		      break;
		  case '*' :
			  return num1*num2 ;
			  break;
		  case '/' :
			  return num1/num2 ;
			default : break;
		 }
	}

static void evaluate (u8 *postfix)
{

	int i = 0;
	int Num = 0;
	u8 operator = ' ';
	u8 Check = 1;
	int Operand1, Operand2;
	u8 Res;

	while (postfix[i] != '\0')
		{
			u8 ch = postfix[i];

			if (ch <= '9' && ch >= '0')
			{
				while (ch <= '9' && ch >= '0')
				{
					Num = (Num * 10) + (int)(ch - '0');
					ch = postfix[++i];
				}
			    if (ch == ' ')
				   {

			        	//Check++;
				    	stack_Push(&s, Num);
				    	Num = 0;
 				    	//Float_Num = 0;
			        	i++;
					    continue;
					}
			}
			else
					{
						operator= ch;
						Operand2 = stack_Top(&s);
						stack_Pop(&s);
						Operand1 = stack_Top(&s);
						stack_Pop(&s);
						stack_Push(&s, Calc_res(Operand1, Operand2, operator));
						i++;
					}
		}

	        Res = stack_Top(&s);
			stack_Pop(&s);
			int length = Get_Length(Res);

			CLCD_voidSetPosition (&lcd, 2, 16-(length + 2));
			 LCD_Print_String  (&lcd , Res    );


		}
}


