//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "io.h"
#include "fcntl.h"
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

double c[100];
double a[100][100];
int c_col,a_n,a_y;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 double tmp,por;
 int f,pos,ti;
 char buf[10000];
 if(OpenDialog1->Execute())
  {Memo1->Text=OpenDialog1->FileName;
   ti=-1;
   if((f=open(OpenDialog1->FileName.c_str(),O_RDONLY))>0)
     ti=read(f,buf,9999);
   if(ti<=0) {Memo1->Text=(AnsiString)"Oшибка чтения файла "+OpenDialog1->FileName;return;}
   buf[ti]=0;pos=0;
   c_col=0;
   while(buf[pos])
    {if((buf[pos]==' ')||(buf[pos]=='\r')||(buf[pos]=='\n')||(buf[pos]==',')){pos++; continue;}
     if(buf[pos]=='-') por=-1; else por=1;
     if((buf[pos]=='-')||(buf[pos]=='+')) pos++;

     for(tmp=0;(buf[pos]>='0')&&(buf[pos]<='9');pos++)
      {tmp*=10;
       tmp+=buf[pos]-'0';
      }
     if(buf[pos]=='.')
      {pos++;
       while ((buf[pos]>='0')&&(buf[pos]<='9'))
         {tmp*=10;
          tmp+=buf[pos]-'0';
          por*=10;
          pos++;
         };
      }
     tmp/=por;
     c[c_col++]=tmp;
    }

  }
 else
  {;}
/*
  for(int i=0;i<c_col;i++)
   Memo1->Text=Memo1->Text+","+c[i];
*/
}
//---------------------------------------------------------------------------
