//including the headers and inputing libs

#include "calculadorabir.h"
#include <QApplication>
#include <iostream>
#include <string>

// main program

int main(int argc, char *argv[])
{
    if(argc==1)
    {
        QApplication a(argc, argv);
        CalculadoraBIR w;
        w.show();

        return a.exec();
    }else
    {

        for(int index=1;index<argc;++index)
        {
            std::string result(argv[index]);

                        char* str = new char[result.size() + 1];
            memcpy(str, result.c_str(), result.size() + 1);

            result = MakeCalculation(str);
            std::cout<<"result "<<argv[index]<< " = " << result <<std::endl;

        }
    }
    return 0;
}
