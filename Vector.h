//
// Created by PC on 03.10.2021.
//

#ifndef LAB3_3SEM_VECTOR_H
#define LAB3_3SEM_VECTOR_H
#include <iostream>
#include <cmath>

namespace Prog3{
    class Vector{
    private:
        static const int max_size = 10;
        int current_size;
        double vector[max_size];

    public:
        Vector ()
        {
            current_size = 0;
        }
        Vector(double value)
        {
            current_size = 1;
            vector[0] = value;
        }

        Vector(int size, double *values)
        {
            current_size = size;
            for (int i = 0; i < size; i ++) vector[i] = values[i];
        }

        Vector(const Vector &source_vector)
        {
            current_size = source_vector.current_size;
            for (int i = 0; i < current_size; i ++) vector[i] = source_vector.vector[i];

        }

        int getMaxSize() const {return max_size;};
        int getCurSize () const {return current_size;}
        double getNum(int i) const {return vector[i];}
        std::ostream & print(std::ostream&) const;
        void inputParameters(int size = 0, double *values = nullptr, double value = 0);
        void printVector() const;
        double *addition(Vector summand);
        double *subtraction(Vector deductible);
        double scalarProduct(Vector multiplier) const;
        double normOfVector() const;
        void addElement(double value);
        Vector & operator = (const Vector &);
    };

}
#endif //LAB3_3SEM_VECTOR_H
