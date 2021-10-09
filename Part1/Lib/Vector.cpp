//
// Created by PC on 03.10.2021.
//

#include "Vector.h"
#include <iostream>
namespace Prog3{
    void Vector::inputParameters(int size, double *values, double value)
    {
        if (size == 0) // передали одно значение
        {
            current_size = 1;
            vector[0] = value;
        }
        else  // передали вектор значений
        {
            if (size > max_size) size = max_size;
            current_size = size;
            for (int i = 0; i < size; i ++) vector[i] = values[i];
        }
    }

    std::ostream & Vector::print(std::ostream &s) const
    {
        for (int i = 0; i < current_size; i++)
            s << vector[i] << ' ';
        s << std::endl;
        return s;
    }

    Vector *Vector::addition(const Vector &summand)
    {
        Vector *summa = new Vector;
        current_size < summand.current_size ? summa->current_size = summand.current_size : summa->current_size = current_size;
        if (current_size < summand.current_size)
        {
            for (int i = 0; i < current_size; i++) (summa->vector)[i] = vector[i] + summand.vector[i];
            for ( int i = current_size; i < summand.current_size; i ++) (summa->vector)[i] = summand.vector[i];
        }
        else if (current_size >= summand.current_size)
        {
            for (int i = 0; i < summand.current_size; i++) (summa->vector)[i] = vector[i] + summand.vector[i];
            for (int i =summand.current_size; i < current_size; i++) (summa->vector)[i] = vector[i];
        }
        return summa;
    }

    Vector *Vector::subtraction(const Vector &deductible)
    {
        Vector *subtraction = new Vector;
        current_size < deductible.current_size ? subtraction->current_size = deductible.current_size : subtraction->current_size = current_size;

        if (current_size < deductible.current_size)
        {
            for (int i = 0; i < current_size; i++) (subtraction->vector)[i] = vector[i] - deductible.vector[i];
            for ( int i = current_size; i < deductible.current_size; i ++) (subtraction->vector)[i] = -1 * deductible.vector[i];
        }

        else if (current_size >= deductible.current_size)
        {
            for (int i = 0; i < deductible.current_size; i++)
                (subtraction->vector)[i] = vector[i] - deductible.vector[i];
            for ( int i = deductible.current_size; i < current_size; i ++)
                (subtraction->vector)[i] = vector[i];
        }

        while ((subtraction->vector)[subtraction->current_size - 1] == 0 && subtraction->current_size > 0) subtraction->current_size -= 1;

        return subtraction;
    }

    double Vector::scalarProduct(const Vector &multiplier) const
    {
        double scalar = 0;
        if (current_size < multiplier.current_size)
            for (int i = 0; i < current_size; i ++) scalar += vector[i] * multiplier.vector[i];
        else
            for (int i = 0; i < multiplier.current_size; i ++) scalar += vector[i] * multiplier.vector[i];
        return scalar;
    }

    double Vector::normOfVector() const
    {
        double norm = std::abs(vector[0]);
        for (int i = 0; i < current_size; i ++)
            if (std::abs(vector[i]) > norm) norm = std::abs(vector[i]);
        return norm;
    }

    void Vector::addElement(double value)
    {
        if (current_size < max_size)
        {
            vector[current_size] = value;
            current_size += 1;
        }
        else
            throw -1; // vector overflow
    }

    bool Vector::getNumbers(const Vector &vector_2) const
    {
        bool answer = true;
        if (this->current_size != vector_2.current_size) answer = false;
        else
            for (int i = 0; i < current_size; i ++)
                if (vector[i] != (vector_2.vector)[i]) answer = false;
        return answer;
    }
}
