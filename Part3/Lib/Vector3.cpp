//
// Created by PC on 11.10.2021.
//

#include "Vector3.h"
using namespace Prog3;
// копирующий конструктор
Vector3::Vector3(const Vector3 &vector2) : current_size(vector2.current_size), max_size(vector2.max_size)
{
    vector = new double [current_size];
    for (int i = 0; i < current_size; i++)
        vector[i] = vector2.vector[i];
}
// перемещающий конструктор
Vector3::Vector3(Vector3 &&vector2) : current_size(vector2.current_size), max_size(vector2.max_size), vector(vector2.vector)
{
    vector2.vector = nullptr;
}

void Vector3::inputParameters(int size, double *values, double value)
{
    max_size = QUOTA;
    if (size == 0) // передали одно значение
    {
        vector = new double [QUOTA];
        current_size = 1;
        vector[0] = value;
    }
    else  // передали вектор значений
    {
        if (size > max_size) {
            max_size = size;
            vector = new double [size];
        }
        for (int i = 0; i < size; i ++) vector[i] = values[i];
        current_size = size;
    }
}

std::ostream & Vector3::print(std::ostream &s) const
{
    for (int i = 0; i < current_size; i++)
        s << vector[i] << ' ';
    s << std::endl;
    return s;
}

double Vector3::scalarProduct(const Vector3 &multiplier) const
{
    double scalar = 0;
    if (current_size < multiplier.current_size)
        for (int i = 0; i < current_size; i ++) scalar += vector[i] * multiplier.vector[i];
    else
        for (int i = 0; i < multiplier.current_size; i ++) scalar += vector[i] * multiplier.vector[i];
    return scalar;
}

double Vector3::normOfVector() const
{
    double norm = std::abs(vector[0]);
    for (int i = 0; i < current_size; i ++)
        if (std::abs(vector[i]) > norm) norm = std::abs(vector[i]);
    return norm;
}

bool Vector3::getNumbers(const Vector3 &vector_2) const
{
    bool answer = true;
    if (this->current_size != vector_2.current_size) answer = false;
    else
        for (int i = 0; i < current_size; i ++)
            if (vector[i] != (vector_2.vector)[i]) answer = false;
    return answer;
}

Vector3 *Vector3::addition(const Vector3 &summand)
{
    Vector3 *summa = new Vector3;
    double *numbers;
    int size;
    current_size < summand.current_size ? size = summand.current_size : size = current_size;
    numbers = new double [size];

    if (current_size < summand.current_size)
    {
        for (int i = 0; i < current_size; i++) numbers[i] = vector[i] + summand.vector[i];
        for ( int i = current_size; i < summand.current_size; i ++) numbers[i] = summand.vector[i];
    }
    else if (current_size >= summand.current_size)
    {
        for (int i = 0; i < summand.current_size; i++) numbers[i] = vector[i] + summand.vector[i];
        for (int i =summand.current_size; i < current_size; i++) numbers[i] = vector[i];
    }

    summa->inputParameters(size, numbers);
    return summa;
}

Vector3 *Vector3::subtraction(const Vector3 &deductible)
{
    Vector3 *subtraction = new Vector3;
    double *numbers;
    int size;
    current_size < deductible.current_size ? size = deductible.current_size : size = current_size;
    numbers = new double [size];

    if (current_size < deductible.current_size)
    {
        for (int i = 0; i < current_size; i++) numbers[i] = vector[i] - deductible.vector[i];
        for ( int i = current_size; i < deductible.current_size; i ++) numbers[i] = -1 * deductible.vector[i];
    }

    else if (current_size >= deductible.current_size)
    {
        for (int i = 0; i < deductible.current_size; i++)
            numbers[i] = vector[i] - deductible.vector[i];
        for ( int i = deductible.current_size; i < current_size; i ++)
            numbers[i] = vector[i];
    }

    subtraction->inputParameters(size, numbers);
    while ((subtraction->vector)[subtraction->current_size - 1] == 0 && subtraction->current_size > 0) subtraction->current_size -= 1;
    return subtraction;
}

void Vector3::addElement(double value){
    if (current_size == max_size) {
        max_size += QUOTA;
        double *old = vector;
        vector = new double [max_size];
        for (int i = 0; i < current_size; i ++) vector[i] = old[i];
        delete [] old;
    }
    vector[current_size] = value;
    current_size += 1;
}

Vector3 & Vector3::operator =(const Vector3 &st)
{
    if (this != &st){
        current_size = st.current_size;
        max_size = st.max_size;
        delete[] vector;
        vector = new double[max_size];
        for (int i = 0; i < current_size; ++i)
            vector[i] = st.vector[i];
    }
    return *this;
}

Vector3 & Vector3::operator =(Vector3 &&st)
{
    int tmp = current_size;
    current_size = st.current_size;
    st.current_size = tmp;
    tmp = max_size;
    max_size = st.max_size;
    st.max_size = tmp;
    double *ptr = vector;
    vector = st.vector;
    st.vector = ptr;
    return *this;
}
