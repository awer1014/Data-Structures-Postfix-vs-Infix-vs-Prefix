//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#define max_size 100
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;




//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
String Stack[max_size];

String Stack_another[max_size];

int top = -1;

int top_another = -1;



void print_stack_another()

{ int i;

String data1 = "", data2 = "" ;

  for (i = 0; i <= top; i++) data1 += Stack[i]+" ";

  for (i = 0; i <= top_another; i++) data2 += Stack_another[i]+" ";

  Form1->Memo1->Lines->Add("Stack 1 => "+data1);

  Form1->Memo1->Lines->Add("Stack 2 => "+data2);

}

void push(int flag, String data)

{ switch (flag)

  {   case (1):

         if (top == max_size-1) Form1->Memo1->Lines->Add("Full");

         else Stack[++top] = data;

         break;

      case (2):

         if (top_another == max_size-1) Form1->Memo1->Lines->Add("Full");

         else Stack_another[++top_another] = data;

         break;

 }

 if (Form1->CheckBox1->Checked) print_stack_another();

}



String pop(int flag)

{ switch (flag)

  {   case (1):

           if (top == -1) Form1->Memo1->Lines->Add("Empty");

           else return Stack[top--];

           break;

      case (2):

           if (top_another == -1) Form1->Memo1->Lines->Add("Empty");

           else return Stack_another[top_another--];

           break;

  }

}



int p(String op)

{ if ((op == '+') || (op == '-') ) return 3 ;

  if ((op == '*') || (op == '/') ) return 4 ;

  if ((op == '^') || (op == '&') || (op == '|') ) return 5 ;

  if ((op == '(') ) return 8 ;

  if (op == '#') return 0 ;

}

int q(String op)

{ if ((op == '+') || (op == '-') ) return 3 ;

  if ((op == '*') || (op == '/') ) return 4 ;

  if ((op == '^') || (op == '&') || (op == '|') ) return 5 ;

  if ((op == '(')) return 1 ;

  if (op == '#') return 0 ;

}

void get_fix(String x, int flag)

{ String a = pop(2);

     a = (flag == 1) ? x+pop(2)+a : pop(2)+a+x;

     push(2, a) ;

}



boolean IsOperand(String s)

{ if (   (s!="+") && (s!="-") && (s!="*") && (s!="/")

   && (s!="(") && (s!=")")  && (s!="&") && (s!="|")

   && (s!="^") ) return true;

  return false;

}

String postfixTOprefix(String postfix)

{  int n = postfix.Length();

   int i;

 String s, x;

     for (i=1; i<=n; i++)

     {   s = postfix[i];

         if ( IsOperand(s) ) push(2, s);

         else get_fix(s, 1);

     }

     return pop(2);

}



String postfixTOinfix(String postfix)

{  int n = postfix.Length();

   int i;

 String s, s1, s2, x, y, prev = "#";

    for (i=1; i<=n; i++)

    {   s = postfix[i];

        if (IsOperand(s))

        { push(2, s);

          push(1, "#");

        }

        else {  s1 = pop(1);

                s2 = pop(1);

                x  = pop(2);

                y  = pop(2);

                if (p(s) > p(s1) && x.Length() > 1) x = "("+x+")";

                if (p(s) > p(s2) && y.Length() > 1) y = "("+y+")";

                if (Form1->CheckBox1->Checked)

                    Form1->Memo1->Lines->Add("p("+s+")="+IntToStr(p(s))+"("+s1+")="+

                    IntToStr(p(s1))+"  p("+s2+")="+IntToStr(p(s2))+"  s1="+s1+"  s2="+

                    s2+"  x="+x+"  y="+y);

                push(2, y+s+x);

                push(1, s);

             }

     }

     while (top != -1) x = pop(1);

     return pop(2);

}



String prefixTOpostfix_reverse(String prefix)

{  int n = prefix.Length();

   int i, counter = 0;

 String s, post;

     for (i=n; i>=1; i--)

     {  s = prefix[i];

        if ( IsOperand(s) )

           push(2, s);

        else {  post = pop(2);

                post += pop(2)+s;

                if (Form1->CheckBox2->Checked) Form1->Memo1->Lines->Add(post);

                push (2, post);

             }

     }

     return pop(2);

}

String transformation(String infix, int flag)

{ int n = infix.Length();

  int i, j;

  String s, x;

     push(1, "#");

     for (i=1; i<=n; i++)

     {  s = infix[i];

        if ( IsOperand(s) ) push(2, s);

        else if (s == ")")  //將堆疊中第一個 ( 之前的運算子皆pop出並印出之

                 while ((x=pop(1))!="(") get_fix(x, flag);

             else

             {     while ( p(s) <= q(Stack[top]) )

                   {    x = pop(1);

                        get_fix(x, flag);

                    }

                    push(1, s);

             }

     }

     while (Stack[top]!= "#")

     { x = pop(1);

       get_fix(x, flag);

     }

     pop(1);

     return pop(2);

}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	 String infix = Edit1->Text;

	String prefix = transformation(infix, 1);

	 Edit2->Text = prefix;

 Memo1->Lines->Add("infix:   "+infix);

 Memo1->Lines->Add("prefix:  "+prefix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     String infix = Edit1->Text;

 String postfix = transformation(infix, 2);

 Edit3->Text = postfix;

 Memo1->Lines->Add("infix:   "+infix);

 Memo1->Lines->Add("postfix: "+postfix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	 String prefix;

 String postfix = Edit7->Text;

 Memo1->Lines->Add("postfix: "+postfix);

 prefix = postfixTOprefix(postfix);

 Edit8->Text = prefix;

 Memo1->Lines->Add("prefix:  "+prefix);


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	/*String postfix;

 String prefix = Edit3->Text;

 Memo1->Lines->Add("prefix:  "+prefix);

 postfix = prefixTOpostfix(prefix);

 Memo1->Lines->Add("postfix: "+postfix); */
 String postfix;
 String infix;

 String prefix = Edit4->Text;


 postfix = prefixTOpostfix_reverse(prefix);
 infix = postfixTOinfix(postfix);
  Edit6->Text = infix;

 Memo1->Lines->Add("infix:   "+infix);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	String infix;

 String postfix = Edit7->Text;

 infix = postfixTOinfix(postfix);

 Edit9->Text = infix;

 Memo1->Lines->Add("infix:   "+infix);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	 String postfix;

 String prefix = Edit4->Text;

 Memo1->Lines->Add("prefix:  "+prefix);

 postfix = prefixTOpostfix_reverse(prefix);

 Edit5->Text = postfix;

 Memo1->Lines->Add("postfix: "+postfix);
}
//---------------------------------------------------------------------------

