#ifndef CALCULADORABIR_H
#define CALCULADORABIR_H

#include <QWidget>  //lib from QT Creator to use Widgets

/*      FUNCTIONS       */

char *MakeCalculation(char expression[]);
int SintaxErrors (char check[]);
void SolveBrackets (char *expression);
void Calculate (char *expression);
float GetNumberAfter (char *expression, int i, char *expressionAux3);
float GetNumberBefore (char *expression, int i, char *expressionAux1, int negativetest);
void RemoveSpaces (char *expression);
void ReverseString (char *expression);

// It groups our main cpp project with the QT Creator

namespace Ui {

class CalculadoraBIR;
}

class CalculadoraBIR : public QWidget
{
    Q_OBJECT

public:
    explicit CalculadoraBIR(QWidget *parent = 0);
    ~CalculadoraBIR();

void EraseLCDAfterError();

private slots:

    void on_Button_0_clicked();
    void on_Button_1_clicked();
    void on_Button_2_clicked();
    void on_Button_3_clicked();
    void on_Button_4_clicked();
    void on_Button_5_clicked();
    void on_Button_6_clicked();
    void on_Button_7_clicked();
    void on_Button_8_clicked();
    void on_Button_9_clicked();
    void on_Button_AC_clicked();
    void on_Button_Dot_clicked();
    void on_Button_Plus_clicked();
    void on_Button_Minus_clicked();
    void on_Button_Times_clicked();
    void on_Button_Split_clicked();
    void on_Button_OpenBracket_clicked();
    void on_Button_CloseBracket_clicked();
    void on_Button_Backspace_clicked();
    void on_Button_Equal_clicked();

private:
    Ui::CalculadoraBIR *ui;
};

#endif // CALCULADORABIR_H
