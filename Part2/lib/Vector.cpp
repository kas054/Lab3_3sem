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

    Vector Vector::addition(const Vector &summand)
    {
        Vector summa;
        current_size < summand.current_size ? summa.current_size = summand.current_size : summa.current_size = current_size;
        if (current_size < summand.current_size)
        {
            for (int i = 0; i < current_size; i++) (summa.vector)[i] = vector[i] + summand.vector[i];
            for ( int i = current_size; i < summand.current_size; i ++) (summa.vector)[i] = summand.vector[i];
        }
        else if (current_size >= summand.current_size)
        {
            for (int i = 0; i < summand.current_size; i++) (summa.vector)[i] = vector[i] + summand.vector[i];
            for (int i =summand.current_size; i < current_size; i++) (summa.vector)[i] = vector[i];
        }
        return summa;
    }

    Vector Vector::subtraction(const Vector &deductible)
    {
        Vector subtraction;
        current_size < deductible.current_size ? subtraction.current_size = deductible.current_size : subtraction.current_size = current_size;

        if (current_size < deductible.current_size)
        {
            for (int i = 0; i < current_size; i++) (subtraction.vector)[i] = vector[i] - deductible.vector[i];
            for ( int i = current_size; i < deductible.current_size; i ++) (subtraction.vector)[i] = -1 * deductible.vector[i];
        }

        else if (current_size >= deductible.current_size)
        {
            for (int i = 0; i < deductible.current_size; i++)
                (subtraction.vector)[i] = vector[i] - deductible.vector[i];
            for ( int i = deductible.current_size; i < current_size; i ++)
                (subtraction.vector)[i] = vector[i];
        }

        while ((subtraction.vector)[subtraction.current_size - 1] == 0 && subtraction.current_size > 0) subtraction.current_size -= 1;

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

    Vector operator + (double number, const Vector &summand) {
        Vector summa = summand;
        (summa.vector)[0] += number;
        return summa;
    }

    Vector  Vector::operator + (double number){
        Vector summa = *this;
        (summa.vector)[0] += number;
        return summa;
    }

    Vector  Vector::operator + (const Vector &summand){
        Vector summa;
        current_size < summand.current_size ? summa.current_size = summand.current_size : summa.current_size = current_size;
        if (current_size < summand.current_size)
        {
            for (int i = 0; i < current_size; i++) (summa.vector)[i] = vector[i] + summand.vector[i];
            for ( int i = current_size; i < summand.current_size; i ++) (summa.vector)[i] = summand.vector[i];
        }
        else if (current_size >= summand.current_size)
        {
            for (int i = 0; i < summand.current_size; i++) (summa.vector)[i] = vector[i] + summand.vector[i];
            for (int i =summand.current_size; i < current_size; i++) (summa.vector)[i] = vector[i];
        }
        return summa;
    }

    Vector  Vector::operator - (double number){
        Vector summa = *this;
        (summa.vector)[0] -= number;
        return summa;
    }

    Vector operator - (double number, const Vector &summand) {
        Vector summa = summand;
        (summa.vector)[0] -= number;
        for (int i = 0; i < summand.current_size; i ++){
            (summa.vector)[i] *= (-1);
        }
        return summa;
    }

    Vector  Vector::operator - (const Vector &deductible){
        Vector subtraction;
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

        subtraction.inputParameters(size, numbers);
        while ((subtraction.vector)[subtraction.current_size - 1] == 0 && subtraction.current_size > 0) subtraction.current_size -= 1;
        return subtraction;
    }

    double  Vector::operator * (double number){
        double answer;
        Vector vector = *this;
        answer = (vector.vector)[0] * number;
        return answer;
    }

    double operator * (double number, const Vector &vector) {
        return number * (vector.vector)[0];
    }

    double Vector::operator * (const Vector & multiplier){
        double scalar = 0;
        if (current_size < multiplier.current_size)
            for (int i = 0; i < current_size; i ++) scalar += vector[i] * multiplier.vector[i];
        else
            for (int i = 0; i < multiplier.current_size; i ++) scalar += vector[i] * multiplier.vector[i];
        return scalar;
    }

    std::ostream & operator << (std::ostream &s, const Vector &vec)
    {
        if (vec.current_size == 0)
            s << "Vector is empty";
        else
            for (int i = 0; i < vec.current_size; i ++)
                s << vec.vector[i] << ' ';
        s << std::endl;
        return s;
    }

    std::istream & operator >> (std::istream &in, Vector &vector)
    {
        int count;
        double number;
        in >> count;
        if (count > vector.max_size) count = vector.max_size;
        for (int i = 0; i < count; i ++){
            in >> number;
            vector.addElement(number);
        }
        return in;
    }


}
