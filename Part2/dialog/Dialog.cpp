//
// Created by PC on 03.10.2021.
//

#include "Dialog.h"
#include <iostream>
namespace Menu {
    void start(Prog3::Vector &vector)
    {
        int rc;
        const char *msgs[] = {"0. Quit", "1. Add element", "2. Print", "3. Add or sub", "4. Input parameters", "5. Scalar product", "6. Copy", "7. Norma of vector"};
        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
        std::cout << "Max size of vector: " << vector.getMaxSize() << std::endl;
        int (*fptr[])(Prog3::Vector &vector) = { nullptr, D_AddElement, D_Print,  D_Add_Sub,  D_InputParameters, D_Scalar, D_Copy, D_Norm };
        while(rc = chooseVariant(msgs, NMsgs)){
            if(!fptr[rc](vector))
                break;
        }
    }

    int chooseVariant(const char *msgs[], int N){
        const char *errmsg = "";
        int rc;
        int i, n;
        do{

            std::cout << errmsg << std::endl;
            errmsg = "You are wrong. Try again, please!";

            for(i = 0; i < N; ++i)
                std::cout << msgs[i] << std::endl;
            puts("Make your choice: --> ");
            n = getInt<int>(rc);
            if(n == 0)
                rc = 0;
        } while(rc < 0 || rc >= N);
        return rc;
    }

    template <class V> int getInt(V &a){
        int n;
        do {
            std::cin >> a;
            n = std::cin.good();
            if (n < 0)
                return 0;
            if (n == 0) {
                printf("%s\n", "Error, try again:");
                std::cin.clear();
                scanf("%*s", 0);
            }
        } while (!n);
        return 1;
    }

    int D_AddElement(Prog3::Vector &vector){
        int count = 0, element;
        std::cout << "Count of elements: " << std::endl;
        getInt(count);
        try{
            for (int i = 0; i < count; ++i)
            {
                std::cout << "Enter number: " << std::endl;
                getInt(element);
                vector.addElement(element);
            }
        }
        catch (int)
        {
            std::cout << "Vector overflow" << std::endl;
        }
        D_Print(vector);
        return 1;
    }

    int D_Print(Vector &vector)
    {
        vector.print(std::cout);
        std::cout << std::endl << std::endl;
        return 1;
    }

    int D_Add_Sub(Vector &vector)
    {
        Vector vector_2, *answer;
        double *numbers = nullptr;
        int size = 0;
        std::cout << "Max size of vector: " << vector.getMaxSize() << std::endl;
        std::cout << "Input count of numbers: " << std::endl;
        do
        {
            std::cin.clear();
            getInt(size);
        } while (size > vector.getMaxSize());

        std::cout << "Input numbers: " << std::endl;
        numbers = new double[size];

        for (int i = 0; i < size; i ++)
        {
            getInt<double>(numbers[i]);
        }
        vector_2.inputParameters(size, numbers);
        delete [] numbers;

        std::cout << "vector1 + vector2 =  " << std::endl;
        answer =  vector.addition(vector_2);
        D_Print(*answer);
        delete answer;
        *answer = vector + vector_2;
        D_Print(*answer);
        delete answer;

        std::cout << "vector1 - vector2 =  " << std::endl;
        answer =  vector.subtraction(vector_2);
        D_Print(*answer);
        delete answer;
        *answer = vector - vector_2;
        D_Print(*answer);
        delete answer;

        return 1;
    }

    int D_InputParameters(Vector &vector)
    {
        Vector vector_2, vector_3;
        double *numbers = nullptr;
        int size = 0;
        std::cout << "Max size of vector: " << vector.getMaxSize() << std::endl;
        std::cout << "Input count of numbers: " << std::endl;
        do
        {
            getInt(size);
        } while (size > vector.getMaxSize());
        numbers = new double[size];

        std::cout << "Input count of numbers: " << std::endl;
        for (int i = 0; i < size; i ++)
        {
            getInt<double>(numbers[i]);
        }

        std::cout << "First vector: " << std::endl;
        vector_2.inputParameters(size, numbers);
        D_Print(vector_2);
        std::cout << "Second vector: " << std::endl;
        vector_3.inputParameters(1, nullptr, numbers[0]);
        D_Print(vector_3);
        delete [] numbers;
        return 1;
    }

    int D_Scalar(Vector &vector)
    {
        Vector vector_2;
        double *numbers = nullptr;
        int size = 0;
        std::cout << "Max size of vector: " << vector.getMaxSize() << std::endl;
        std::cout << "Input count of numbers: " << std::endl;
        do
        {
            getInt(size);
        } while (size > vector.getMaxSize());

        std::cout << "Input numbers: " << std::endl;
        numbers = new double[size];
        for (int i = 0; i < size; i ++)
        {
            getInt<double>(numbers[i]);
        }
        vector_2.inputParameters(size, numbers);
        std::cout << vector.scalarProduct(vector_2) << std::endl;
        delete [] numbers;
        return 1;
    }

    int D_Copy(Vector &vector)
    {
        Vector vector_2;
        double *numbers = nullptr;
        int size = 0;
        std::cout << "Max size of vector 2: " << vector.getMaxSize() << std::endl;
        std::cout << "Input count of numbers: " << std::endl;
        do
        {
            getInt(size);
        } while (size > vector.getMaxSize());

        std::cout << "Input numbers: " << std::endl;
        numbers = new double[size];
        for (int i = 0; i < size; i ++)
        {
            getInt<double>(numbers[i]);
        }
        vector_2.inputParameters(size, numbers);
        delete [] numbers;

        std::cout << "Vector 1: " << std::endl;
        D_Print(vector);
        //vector = Vector(vector_2);
        vector = vector_2;
        std::cout << "New vector 1: " << std::endl;
        D_Print(vector);
        return 1;
    }

    int D_Norm(Vector &vector)
    {
        D_Print(vector);
        std::cout << "Norma of vector: " << vector.normOfVector() << std::endl;
        return 1;
    }

}
