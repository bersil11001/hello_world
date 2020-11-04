//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <math.h>

#include "laba2.h"
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Edit1->Text="";
 Edit2->Text="";
 Edit3->Text="";
 Memo1->Clear();
 RadioGroup1->ItemIndex=-1;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double x,z,a,b,f;
        z=StrToFloat(Edit1->Text);
        a=StrToFloat(Edit2->Text);
        b=StrToFloat(Edit3->Text);
        if(z<=0){
                x=pow(z,2)/2.;
        }else{
                x=sqrt(z);
        }
        switch(RadioGroup1->ItemIndex)
        {
                case 0:
                f=2*x;
                        break;
                case 1:
                f=pow(x,2);
                        break;
                case 2:
                f=x/3.;
                        break;
                default:
                Memo1->Lines->Add("Выберите функцию");


        }if(RadioGroup1->ItemIndex >=0){
        z=b*f/cos(x)+a*log(fabs(tan(x/2)));
        Memo1->Lines->Add("Результат : ");
        Memo1->Lines->Add(FloatToStr(z));}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   Edit1->Text="";
   Edit2->Text="";
   Edit3->Text="";
   Memo1->Clear();
}
//---------------------------------------------------------------------------
