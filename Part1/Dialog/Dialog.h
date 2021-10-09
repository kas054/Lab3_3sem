//
// Created by PC on 03.10.2021.
//

#ifndef LAB3_3SEM_DIALOG_H
#define LAB3_3SEM_DIALOG_H
#include "Vector.h"
using namespace Prog3;
namespace Menu {
    int chooseVariant(const char *msgs[], int N);
    void start(Vector &vector);
    int D_AddElement(Vector &vector);
    int D_Print(Vector &vector);
    int D_Add_Sub(Vector &vector);
    int D_InputParameters(Vector &vector);
    int D_Scalar(Vector &vector);
    int D_Copy(Vector &vector);
    int D_Norm(Vector &vector);
    template <class V> int getInt(V &a);
}
#endif //LAB3_3SEM_DIALOG_H
