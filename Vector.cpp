//
// Created by PC on 03.10.2021.
//

#include "Vector.h"
#include <iostream>
namespace Prog3{
    void Vector::inputParameters(int size, double *values, double value)
    {
        if (size == 1) // передали одно значение
        {
            current_size = 1;
            vector[0] = value;
        }
        else  // передали вектор значений
        {
            current_size = size;
            for (int i = 0; i < size; i ++) vector[i] = values[i];
        }
    }

    void Vector::printVector() const
    {
        for (int j = 0; j < current_size; j ++) std::cout << vector[j] << "  ";
        std::cout << std::endl;
    }

    std::ostream & Vector::print(std::ostream &s) const
    {
        for (int i = 0; i < current_size; i++)
            s << vector[i] << ' ';
        s << std::endl;
        return s;
    }

    double *Vector::addition(Vector summand)
    {
        if (current_size < summand.current_size)
        {
            for (int i = 0; i < current_size; i++) vector[i] += summand.vector[i];
            for ( int i = current_size; i < summand.current_size; i ++) vector[i] = summand.vector[i];
            current_size = summand.current_size;
        }
        else if (current_size >= summand.current_size)
            for (int i = 0; i < summand.current_size; i++) vector[i] += summand.vector[i];
        return vector;
    }

    double *Vector::subtraction(Vector deductible)
    {
        if (current_size < deductible.current_size)
        {
            for (int i = 0; i < current_size; i++) vector[i] -= deductible.vector[i];
            for ( int i = current_size; i < deductible.current_size; i ++) vector[i] = -1 * deductible.vector[i];
            current_size = deductible.current_size;
        }

        else if (current_size >= deductible.current_size)
            for (int i = 0; i < deductible.current_size; i++) vector[i] -= deductible.vector[i];

        while (vector[current_size - 1] == 0 && current_size > 0) current_size -= 1;

        return vector;
    }

    double Vector::scalarProduct(Vector multiplier) const
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

    Vector & Vector::operator = (const Vector &vector)
    {
        if (this == &vector) return *this;
        current_size = vector.current_size;
        for (int i = 0; i < current_size; i ++) this->vector[i] = vector.vector[i];
        return *this;
    }
}