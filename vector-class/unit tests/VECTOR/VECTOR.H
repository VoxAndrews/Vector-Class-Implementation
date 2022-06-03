// VECTOR.H - A template class to store vectors
// author Darcy Lyndon Cukrov Wilson

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

// Exposing only what is needed instead of the whole std namespace
using std::cout;
using std::endl;

/**
* @class Vector
* @brief A template class which represents a dynamically allocating array.
*
* It can take in any type, store it and dynamically resize itself, with bounding checks.
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 03/04/2022 Darcy Lyndon Cukrov Wilson
*/

//TEMPLATE CLASSES SOMETIMES HAVE THE DECLARATIONS & IMPLEMENTATIONS WITHIN THE HEADER FILE

template <class T> //Creates a template class of name T
class Vector { //This is NOT the std::vector
        /**
        * @param  T* data - A primary template array which stores the data for the user
        */
    T* data; //Showing the data that is going to go into the vector (PRIVATE)

public:
        /**
        * @brief Vector Constructor
        *
        * This is a default construct for the Vector Class
        */
    Vector();

        /**
        * @brief Vector Destructor
        *
        * This is a destructor, to delete the data array
        */
    ~Vector();

        /**
        * @brief Returns the current size of the Vector
        *
        * @return const unsigned
        */
    unsigned GetSize() const;

        /**
        * @brief Returns the current amount of elements within the vector
        *
        * @return const unsigned
        */
    unsigned GetElementAmount() const;

        /**
        * @brief Sets an element within the vector
        *
        * If the vector requires more space, it will also handle resizing
        *
        * @return void
        *
        * @param  const Vector<T>& inData - Data to be input into the vector
        */
    void SetElement(const T& inData); //Also sets the values of 'vecSize' & 'elementAmount' when resizing and allocating

        /**
        * @brief Shrinks the vector to the size of the number of current elements
        *
        * @return void
        */
    void ShrinkVector(); //Shrinks the size of the vector to save memory

    T& operator [](unsigned index); //Set METHOD - Used to set the values

    T operator [](unsigned index) const; //GET METHOD - Returns the value using overloading of [] operator
private:
    unsigned vecSize; //Size of the vector

    unsigned elementAmount; //The current number of elements in the vector

    unsigned vecSizeMultiplier; //The multiplier used to adjust the vector resizing
};

template <class T>
Vector<T>::Vector()
{
    data = NULL; //Nulls the vector out

    data = new T[1]; //Sets the size of the vector to 1 to start with

    vecSize = 1; //Sets the indicated size
    elementAmount = 0; //Sets the number of elements within the vector
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <class T>
unsigned Vector<T>::GetSize() const
{
    return vecSize;
}

template <class T>
unsigned Vector<T>::GetElementAmount() const
{
    return elementAmount;
}

template <class T>
void Vector<T>::SetElement(const T& inData) //Also sets the values of 'vecSize' & 'elementAmount' when resizing and allocating
{
    vecSizeMultiplier = 2; //Sets the vector multiplier

    if(elementAmount == vecSize) //Checks to see if the size needs to be increased
    {
        T* tmpData = new T[vecSize * vecSizeMultiplier]; //Create a temporary vector to store the values

        for(int i = 0; i < vecSize; i++) //Adding array elements to the temporary data
        {
            tmpData[i] = data[i];
        }

        delete[] data; //Delete the previous array

        vecSize = vecSize * vecSizeMultiplier; //Resize the array to the same size, but increased by 200% (Multiply by 2)

        data = tmpData; //Make the original array equal to the new temporary array ()
        data[elementAmount] = inData; //Uses element amount as the index number, as it is one more than what is currently there

        elementAmount++; //Adds one to the element amount
    }
    else
    {
        data[elementAmount] = inData; //Uses element amount as the index number, as it is one more than what is currently there

        elementAmount++; //Adds one to the element amount
    }
}

template <class T>
void Vector<T>::ShrinkVector() //Shrinks the size of the vector to save memory
{
    T* tmpData = new T[elementAmount]; //Create a temporary vector to store the values

    for(int i = 0; i < elementAmount; i++) //Adding array elements to the temporary data
    {
        tmpData[i] = data[i];
    }

    delete[] data; //Delete the previous array

    vecSize = elementAmount; //Resize the array to the same size, but increased by 150% (Multiply by 1.5)

    data = tmpData; //Make the original array equal to the new temporary array ()
}

template <class T>
T& Vector<T>::operator [](unsigned index) //Set METHOD - Used to set the values
{
    //Checks to see if the element that is being searched for is within bounds
    if((index < 0) || (index >= vecSize))
    {
        throw std::out_of_range("ERROR: Vector out of bounds!");
    }
    else
        return data[index]; //Returns Vector element
}

template <class T>
T Vector<T>::operator [](unsigned index) const //GET METHOD - Returns the value using overloading of [] operator
{
    //Checks to see if the element that is being searched for is within bounds
    if((index < 0) || (index >= vecSize))
    {
        throw std::out_of_range("ERROR: Vector out of bounds!");
    }
    else
        return data[index]; //Returns Vector element
}

#endif
