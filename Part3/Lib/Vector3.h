//
// Created by PC on 11.10.2021.
//

#ifndef VECTOR2_VECTOR2_H
#define VECTOR2_VECTOR2_H
#include <iostream>
namespace Prog3
{
    class Vector3{
    private:
        static const int QUOTA = 10;
        int max_size; // максимальный размер вектора
        int current_size;
        double *vector;
    public:
        Vector3() : current_size(0), vector (new double [QUOTA]), max_size(QUOTA) {};
        Vector3(double elem) : current_size(1), vector (new double [QUOTA]), max_size(QUOTA) { vector[0] = elem; };
        Vector3(int size, double *numbers) : max_size(QUOTA)
        {
            while (size > max_size) max_size += QUOTA;
            current_size = size;
            vector = new double [max_size];
            for (int i = 0; i < current_size; i ++) vector[i] = numbers[i];
        }

        Vector3(const Vector3 &); // копирующий конструктор
        Vector3(Vector3 &&); // перемещающий конструктор
        Vector3 &operator =(const Vector3 &);
        Vector3 &operator =(Vector3 &&);
        ~Vector3() { delete[] vector; }; // деструктор

        int getMaxSize() const {return max_size;};
        int getCurSize () const {return current_size;}
        double getNum(int i) const {return vector[i];}
        bool getNumbers(const Vector3 &vector_2) const;

        std::ostream & print(std::ostream&) const;
        void inputParameters(int size = 0, double *values = nullptr, double value = 0);

        Vector3 *addition(const Vector3 &summand);
        Vector3 *subtraction(const Vector3 &deductible);
        double scalarProduct(const Vector3 &multiplier) const;
        double normOfVector() const;
        void addElement(double value);

    };
}
#endif //VECTOR3_H
