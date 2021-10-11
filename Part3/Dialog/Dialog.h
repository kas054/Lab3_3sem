//
// Created by PC on 03.10.2021.
//

#ifndef LAB3_3SEM_DIALOG_H
#define LAB3_3SEM_DIALOG_H
#include "Vector3.h"
using namespace Prog3;
namespace Menu {
    int chooseVariant(const char *msgs[], int N);
    void start(Vector3 &vector);
    int D_AddElement(Vector3 &vector);
    int D_Print(Vector3 &vector);
    int D_Add_Sub(Vector3 &vector);
    int D_InputParameters(Vector3 &vector);
    int D_Scalar(Vector3 &vector);
    int D_Copy(Vector3 &vector);
    int D_Norm(Vector3 &vector);
    template <class V> int getInt(V &a);
}
#endif //LAB3_3SEM_DIALOG_H
