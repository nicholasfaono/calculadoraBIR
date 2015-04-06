// Calling the headers

#include "calculadorabir.h"
#include "ui_calculadorabir.h"
#include <iostream>
#include <stdio.h>

#define CHAR_SIZE 128   // maximum size of expression


CalculadoraBIR::CalculadoraBIR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculadoraBIR)
{
    ui->setupUi(this);

}

// cleaning the calculator until beginning
CalculadoraBIR::~CalculadoraBIR()
{
    delete ui;
}

// what happens when clicking each button

void CalculadoraBIR::on_Button_0_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(0));
}

void CalculadoraBIR::on_Button_1_clicked()
{
    EraseLCDAfterError();

    ui->LCD->setText(ui->LCD->text()+QString::number(1));
}

void CalculadoraBIR::on_Button_2_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(2));
}

void CalculadoraBIR::on_Button_3_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(3));
}

void CalculadoraBIR::on_Button_4_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(4));
}

void CalculadoraBIR::on_Button_5_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(5));
}

void CalculadoraBIR::on_Button_6_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(6));
}

void CalculadoraBIR::on_Button_7_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(7));
}

void CalculadoraBIR::on_Button_8_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(8));
}

void CalculadoraBIR::on_Button_9_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+QString::number(9));
}

void CalculadoraBIR::on_Button_AC_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText("");
}

void CalculadoraBIR::on_Button_Dot_clicked()
{
    EraseLCDAfterError();

    int dot = 0, exit =0;

    const char *checkingdot = ui->LCD->text().toStdString().c_str();
    for(signed int i = strlen(checkingdot);i>=0 ;--i){

        if(checkingdot[i]=='+' || checkingdot[i]=='-' || checkingdot[i]=='*'
                || checkingdot[i]=='/' || checkingdot[i]=='('
                || checkingdot[i]==')'|| checkingdot[i]==','|| checkingdot[i]=='.')
        {
            for(unsigned int j = i;j<strlen(checkingdot);++j)
            {
                if(checkingdot[j]==',' || checkingdot[j]== '.')
                {
                    dot =1;
                    break;
                }
                exit =1;
            }

        }
        if(exit==1)
        {
            break;
        }
    }

    if(dot==0){
        ui->LCD->setText(ui->LCD->text()+",");
    }
}

void CalculadoraBIR::on_Button_Plus_clicked()
{
    EraseLCDAfterError();
    const char *checkingoperator = ui->LCD->text().toStdString().c_str();
    if(checkingoperator[strlen(checkingoperator)-1]=='+' || checkingoperator[strlen(checkingoperator)-1]=='-'
            || checkingoperator[strlen(checkingoperator)-1]=='*' || checkingoperator[strlen(checkingoperator)-1]=='/')
    {
        return;
    }else{
        ui->LCD->setText(ui->LCD->text()+"+");
    }
}

void CalculadoraBIR::on_Button_Minus_clicked()
{
    EraseLCDAfterError();
    const char *checkingoperator = ui->LCD->text().toStdString().c_str();
    if(checkingoperator[strlen(checkingoperator)-1]=='+' || checkingoperator[strlen(checkingoperator)-1]=='-'
            || checkingoperator[strlen(checkingoperator)-1]=='*' || checkingoperator[strlen(checkingoperator)-1]=='/')
    {
        return;
    }else{
        ui->LCD->setText(ui->LCD->text()+"-");
    }
}

void CalculadoraBIR::on_Button_Times_clicked()
{
    EraseLCDAfterError();
    const char *checkingoperator = ui->LCD->text().toStdString().c_str();
    if(checkingoperator[strlen(checkingoperator)-1]=='+' || checkingoperator[strlen(checkingoperator)-1]=='-'
            || checkingoperator[strlen(checkingoperator)-1]=='*' || checkingoperator[strlen(checkingoperator)-1]=='/')
    {
        return;
    }else{
        ui->LCD->setText(ui->LCD->text()+"*");
    }
}

void CalculadoraBIR::on_Button_Split_clicked()
{
    EraseLCDAfterError();
    const char *checkingoperator = ui->LCD->text().toStdString().c_str();
    if(checkingoperator[strlen(checkingoperator)-1]=='+' || checkingoperator[strlen(checkingoperator)-1]=='-' || checkingoperator[strlen(checkingoperator)-1]=='*' || checkingoperator[strlen(checkingoperator)-1]=='/')
    {
        return;
    }else{
        ui->LCD->setText(ui->LCD->text()+"/");
    }
}

void CalculadoraBIR::on_Button_OpenBracket_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+"(");
}

void CalculadoraBIR::on_Button_CloseBracket_clicked()
{
    EraseLCDAfterError();
    ui->LCD->setText(ui->LCD->text()+")");
}

void CalculadoraBIR::on_Button_Backspace_clicked()
{
    EraseLCDAfterError();
    const char* auxchar=ui->LCD->text().toStdString().c_str();
    char backspace[CHAR_SIZE];
    strcpy(backspace, auxchar);
    backspace[strlen(backspace)-1]='\0';
    ui->LCD->setText(backspace);

}

//---------------------------------------------------------------------------------

// begin of solving the expression
void CalculadoraBIR::on_Button_Equal_clicked()
{
    EraseLCDAfterError();

    const char* auxchar=ui->LCD->text().toStdString().c_str();
    char solving[CHAR_SIZE];

    strcpy(solving, auxchar);


    ui->LCD->setText(MakeCalculation(solving));

}

//---------------------------------------------------------------------------------

// begin of solving the expression
char* MakeCalculation(char expression[])
{
    int checked=1;

    checked=SintaxErrors(expression);

    if(checked==0)
    {
        std::cout<<"SINTAX ERROR: "<< expression<<std::endl;
        expression="SINTAX ERROR";
        return expression;
    }
    SolveBrackets(expression);


    while(expression[strlen(expression)-1]=='0' || expression[strlen(expression)-1]==','
          || expression[strlen(expression)-1]=='.')
    {

        if(expression[strlen(expression)-1]==',' || expression[strlen(expression)-1]=='.'){

            expression[strlen(expression)-1]='\0';
            break;
        }
        expression[strlen(expression)-1]='\0';
    }


    return expression;

}

//---------------------------------------------------------------------------------

// function to look if have sintax errors
int SintaxErrors (char check[])
{

    if(check[strlen(check)-1]=='-'|| check[strlen(check)-1]=='+'||                  //1 check, operator in the end of the sentence
            check[strlen(check)-1]=='/'|| check[strlen(check)-1]=='*')
    {

        std::cout<< "ERROR, operator in the end of the sentence: "<<check[strlen(check)-1]<<std::endl;
        return 0;
    }
//--------------------------------------------
    int countbracket=0;

    for(unsigned int i=0; i<strlen(check); ++i)                                     //2 check, operator at the beggining of the sentence
    {
        if(check[0]=='+'||check[0]=='/'||check[0]=='*')
        {
            std::cout<<"ERROR, operator at the beginning of the sentence: "<< check[0] <<std::endl;
            return 0;
        }
//---------------------------------------------

        if(     check[i]!='9' && check[i]!='8' && check[i]!='7' && check[i]!='6' && //3 check, diferent kind of charactere
                check[i]!='5' && check[i]!='4' && check[i]!='3' && check[i]!='2' &&
                check[i]!='1' && check[i]!='0' && check[i]!='+' && check[i]!='-' &&
                check[i]!='*' && check[i]!='/' && check[i]!='(' && check[i]!=')' &&
                check[i]!=',' && check[i]!='.')
        {
            std::cout<<"ERROR, please type a number among these:  9 8 7 6 5 4 3 2 1 0 + - * / ) ( . "<<std::endl;
            return 0;
        }
//---------------------------------------------

        if(check[i]=='(')                                                           //4 check, if have just openning bracket
        {
            countbracket++;
        }
        if(check[i]==')')
        {
            countbracket--;
        }

//---------------------------------------------

        if(check[i]=='+' || check[i]=='-' || check[i]=='*' || check[i]=='/')    //5 check, two operators together
        {
            if(check[i+1]=='+'||check[i+1]=='-'||check[i+1]=='*'||check[i+1]=='/')
            {
                std::cout<<"ERROR, two operator together:  "<<check[i]<<check[i+1]<<std::endl;
                return 0;
            }
        }


//---------------------------------------------


        if(check[i]=='(')                                                       //6 check, just operator in the bracket(openning)
        {
            if(check[i+1]=='+'||check[i+1]=='*'||check[i+1]=='/')
            {
                std::cout<< "ERROR, operator after the opening bracket! "<<check[i+1]<<std::endl;
                return 0;
            }
        }
        if(check[i]==')')
        {
            if(check[i-1]=='+'||check[i-1]=='-'||check[i-1]=='*'||check[i-1]=='/')//6.1 check,just operator in the bracket(closing)
            {
                std::cout<<"ERROR, operator before the close bracket! "<<check[i-1]<<std::endl;
                return 0;
            }
        }


//--------------------------------------------

        if(check[i]=='(')                                                          //7 check, number befor bracket
        {
            if(i>0 && check[i-1]!='+'&& check[i-1]!='-'&& check[i-1]!='*'&& check[i-1]!='/' && check[i-1]!='(' )
            {

                std::cout<< "ERROR, number before bracket!"<<std::endl;
                return 0;
            }
        }

//--------------------------------------------

        if(check[i]==')')                                                         //8 check, number after bracket
        {
            if(i>0 && check[i+1]!='+'&& check[i+1]!='-'&& check[i+1]!='*'&& check[i+1]!='/' && check[i+1]!=')' && check[i+1]!='\0')
            {
                std::cout<< "ERROR, number after bracket!"<<std::endl;
                return 0;
            }
        }

//--------------------------------------------

        if(check[i]==',' || check[i]=='.')                                      //9 check, 2 or more dots in one number
        {
            for(unsigned int j = i+1;j<strlen(check);++j)
            {
                if(check[j]=='+'||check[j]=='-'||check[j]=='*'||check[j]=='/'||check[j]=='('||check[j]==')')
                {

                    break;
                }else if(check[j]==','|| check[j]=='.' )
                {
                    std::cout<< "ERROR, two or more dots in the same number!"<<std::endl;
                    return 0;

                }
            }

            for(int j = i-1;j>0;--j)
            {
                if(check[j]=='+'||check[j]=='-'||check[j]=='*'||check[j]=='/'||check[j]=='('||check[j]==')')
                {

                    break;
                }else if(check[j]==','|| check[j]=='.' )
                {
                    std::cout<< "ERROR, two or more dots in the same number!"<<std::endl;
                    return 0;

                }
            }

        }
//--------------------------------------------

    }

    if(countbracket<0)                                                          //4º.1 check, just the closing bracket
    {
        std::cout<< "ERROR,  need to open a bracket"<<std::endl;
        return 0;
    }

    if(countbracket!=0)                                                         //4º.2 check, just the closing bracket
    {
        std::cout<<"ERROR, need to close a bracket"<<std::endl;
        return 0;
    }


    return 1;

}

//---------------------------------------------------------------------------------

// function to solve bracket
void SolveBrackets(char* expression)
{

    char expressionaux[CHAR_SIZE]= {""}, expressionaux2[CHAR_SIZE]= {""}, expressionaux3[CHAR_SIZE]= {""};
    int countbracket=0, aux=0;                                                  //1 found brackets and count them
    for(unsigned int i=0; i<strlen(expression); ++i)                            //2 count how many brackets
    {
        if(expression[i]=='(')
        {
            countbracket++;
        }
    }
    if(countbracket==0)                                                         //3 having no one go away
    {
        Calculate(expression);
        if(expression[0]=='E')
        {
            expression = "Erro de divisão por 0";
            return;
        }

        strcpy(expression, expression);
        return;
    }
    else                                                                        //4 if have calculate inside of it
    {
        int k=0, closingbracketposition=0, openingbracketposition=0;

        for(unsigned int i=0; i<strlen(expression); ++i)
        {
            if(expression[i] == ')')
            {
                closingbracketposition=i+1;
                for(int j=i; j>0; --j)
                {
                    if(expression[j] == '(')
                    {
                        openingbracketposition=j+1;
                        aux=1;
                        break;
                    }
                }
                if(aux==1)
                {
                    i=strlen(expression);
                }
            }
        }

        if(openingbracketposition-1<0)
        {
            for(int i=1; i<openingbracketposition-1; ++i) //segura a 1º função(antes do parenteses)
            {
                expressionaux[i]=expression[i];
            }
            expression[0]=' ';
        }
        else
        {
            for(int i=0; i<openingbracketposition-1; ++i) //segura a 1º função(antes do parenteses)
            {
                expressionaux[i]=expression[i];
            }

        }

        for(int i=openingbracketposition; i<closingbracketposition-1; ++i) //segura a 2º função(a que vai ser resolvida)
        {
            expressionaux2[k]=expression[i];
            ++k;
        }
        Calculate(expressionaux2);
        if(expressionaux[strlen(expressionaux)-1]=='-')
        {
            float deny;
            expressionaux[strlen(expressionaux)-1]='\0';
            deny=atof(expressionaux2);

            deny=(-1)*deny;
            if(deny>=0)
            {
                char positive[2]= {"+"};
                sprintf(expressionaux2, "%f", deny);
                strcat(positive, expressionaux2);
                strcpy(expressionaux2, positive );
            }
            else
            {
                sprintf(expressionaux2, "%f", deny);
            }

        }
        k=0;

        for(unsigned int i=closingbracketposition; i<strlen(expression); ++i) //segura a 3º função(depois do parenteses)
        {
            expressionaux3[k]=expression[i];
            k++;
        }

        strcat(expressionaux, expressionaux2);
        strcat(expressionaux, expressionaux3);
        SolveBrackets(expressionaux);
    }
    strcpy(expression, expressionaux);
    return;
}

//---------------------------------------------------------------------------------

// function to calculate the expression(spliting each part in 2 parts)
void Calculate (char* expression)
{
    int timesandsplitcounter=0, plusandminuscounter=0, operatorsum=0, negativetest=0;
    char  expressionaux2[50]= {""};
    float part1=0, part2=0, result=0;
    RemoveSpaces(expression);
    if(expression[0]=='-')
    {
        negativetest=1;
    }
    else
    {
        negativetest=0;
    }

    for(unsigned int i=negativetest; i<strlen(expression); ++i)
    {
        if(expression[i]== '*' ||expression[i]== '/' )
        {
            timesandsplitcounter++;
        }
        if(expression[i]== '+' ||expression[i]== '-' )
        {
            plusandminuscounter++;
        }
    }

    operatorsum=plusandminuscounter+timesandsplitcounter;

    for(int t=0; t<operatorsum; ++t)
    {
        char expressionaux1[CHAR_SIZE]= {""},expressionaux3[CHAR_SIZE]= {""};

        if(expression[0]=='-')
        {
            negativetest=1;
        }
        else
        {
            negativetest=0;
        }

        for(unsigned int i=negativetest; i<strlen(expression); ++i)
        {
            if(expression[i]== '+' && plusandminuscounter > 0 && timesandsplitcounter == 0)
            {
                part1=GetNumberBefore(expression, i, expressionaux1, negativetest);
                part2=GetNumberAfter(expression, i, expressionaux3);



                if(negativetest==1)
                {
                    expressionaux1[0]=' ';
                    RemoveSpaces(expressionaux1);
                }

                result=part1+part2;

                sprintf(expressionaux2, "%f", result);//transforma float em char
                plusandminuscounter--;
                strcat(expressionaux1, expressionaux2);
                strcat(expressionaux1, expressionaux3);
                strcpy(expression, expressionaux1);
                break;
            }
            else if(expression[i]== '-' && plusandminuscounter > 0 && timesandsplitcounter == 0)
            {
                part1=GetNumberBefore(expression, i, expressionaux1, negativetest);
                part2=GetNumberAfter(expression, i, expressionaux3);

                if(negativetest==1)
                {
                    expressionaux1[0]=' ';
                    RemoveSpaces(expressionaux1);
                }

                result=part1-part2;
                sprintf(expressionaux2, "%f", result);//transforma float em inteiro
                plusandminuscounter--;
                strcat(expressionaux1, expressionaux2);
                strcat(expressionaux1, expressionaux3);
                strcpy(expression, expressionaux1);
                break;
            }
            else if(expression[i]== '*' && timesandsplitcounter > 0)
            {
                int depoisNegativo = 0;
                if(expression[i+1]=='-')
                {
                    expression[i+1]=' ';
                    depoisNegativo=1;
                }

                part1=GetNumberBefore(expression, i, expressionaux1, negativetest);
                part2=GetNumberAfter(expression, i, expressionaux3);


                if(negativetest==1)
                {
                    expressionaux1[0]=' ';
                    RemoveSpaces(expressionaux1);
                }

                if(depoisNegativo==0)
                {
                    result=part1*part2;
                }
                else
                {
                    result=part1*part2*(-1);
                }

                timesandsplitcounter--;
                sprintf(expressionaux2, "%f", result);//transforma float em inteiro
                strcat(expressionaux1, expressionaux2);
                strcat(expressionaux1, expressionaux3);
                strcpy(expression, expressionaux1);
                break;
            }
            else if(expression[i]== '/' && timesandsplitcounter > 0)
            {
                int depoisNegativo = 0;
                if(expression[i+1]=='-')
                {
                    expression[i+1]=' ';
                    depoisNegativo=1;
                }

                part1=GetNumberBefore(expression, i, expressionaux1, negativetest);
                part2=GetNumberAfter(expression, i, expressionaux3);



                if(part2==0)
                {
                    strcpy(expression, "Divisão por 0 não definido");
                    return;
                }

                if(negativetest==1)
                {
                    expressionaux1[0]=' ';
                    RemoveSpaces(expressionaux1);
                }


                if(depoisNegativo==0)
                {
                    result=part1/part2;
                }
                else
                {
                    result=part1/part2*(-1);
                }

                timesandsplitcounter--;
                sprintf(expressionaux2, "%f", result);//transforma float em inteiro
                strcat(expressionaux1, expressionaux2);
                strcat(expressionaux1, expressionaux3);
                strcpy(expression, expressionaux1);
                break;
            }
        }
    }
}

//---------------------------------------------------------------------------------

// getting number after the operator
float GetNumberAfter (char* expression, int i, char* expressionaux3)
{
    int o=0, l=i, j=0, h=0;
    char expressionaux[CHAR_SIZE]= {""};
    while(j==0)
    {
        if(expression[l+1]=='\0'|| expression[l+1]=='+' ||
                expression[l+1]=='('    || expression[l+1]==')' ||
                expression[l+1]=='-'    || expression[l+1]=='*' ||
                expression[l+1]=='/')
        {
            for(unsigned int k=l+1; k<strlen(expression); k++)
            {
                expressionaux3[h]=expression[k];
                h++;
            }
            break;
        }
        expressionaux[o]=expression[l+1];
        o++;
        l++;
    }
    return atof(expressionaux);
}

//---------------------------------------------------------------------------------

// getting the number before the operator
float GetNumberBefore (char* expression, int i, char* expressionaux1, int negativetest)
{

    int o=0, l=i, j=0,h=0;

    char expressionaux[CHAR_SIZE]= {""};

    while(j==0)
    {
        if(negativetest==1)
        {
            if(l-1==0)
            {
                expressionaux[o]=expression[l-1];
                o++;
                expression[l-1]=' ';

            }
        }
        if(expression[l-1]!='0'&& expression[l-1]!='1'&& expression[l-1]!='2'&& expression[l-1]!='3'&&
                expression[l-1]!='4'&& expression[l-1]!='5'&& expression[l-1]!='6'&& expression[l-1]!='7'&&
                expression[l-1]!='8'&& expression[l-1]!='9'&& expression[l-1]!=',' && expression[l-1]!='.')
        {
            for(int k=l-1; k>=0; k--)
            {
                expressionaux1[h]=expression[k];
                h++;
            }

            ReverseString(expressionaux1);
            break;
        }

        expressionaux[o]=expression[l-1];
        o++;
        l--;
    }
    ReverseString(expressionaux);

    if(negativetest==1)
    {
        return atof(expressionaux);
    }
    return atof(expressionaux);
}

//---------------------------------------------------------------------------------

//function that removes spaces
void RemoveSpaces (char *expression)
{
    char expressionwithoutspace[CHAR_SIZE]= {""};
    int j=0;

    for(unsigned int i=0; i<strlen(expression); ++i)
    {
        if(expression[i]!=' ')
        {
            expressionwithoutspace[j]=expression[i];
            ++j;
        }

    }
    expressionwithoutspace[j]='\0';
    strcpy(expression,expressionwithoutspace);

}

//---------------------------------------------------------------------------------

//function that reverses the string after bein catched by the solving brackets function
void ReverseString (char* expression)
{
    int i,n,aux=0;
    for(n=0; expression[n]!=0; n++);
    for(i=0; i<n/2; ++i)
    {
        aux=expression[i];
        expression[i]=expression[n-1-i];
        expression[n-1-i]=aux;
    }
}

//---------------------------------------------------------------------------------


void CalculadoraBIR::EraseLCDAfterError()
{
    std::string error=ui->LCD->text().toStdString();

    if(error == "SINTAX ERROR" || error == "Division by zero is undefined")
    {
        ui->LCD->setText("");

    }
}
