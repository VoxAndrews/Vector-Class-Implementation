// VECTOR.H - A template class to store vectors
// author Darcy Wilson

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

/**
* @class Vector
* @brief A template class which represents a dynamically allocating array.
*
* It can take in any type, store it and dynamically resize itself, with bounding checks.
*
* @author Darcy Wilson
* @version 01
* @date 03/04/2022 Darcy Wilson
*/

//TEMPLATE CLASSES SOMETIMES HAVE THE DECLARATIONS & IMPLEMENTATIONS WITHIN THE HEADER FILE

template <class T> //Creates a template class of name T
class Vector { //This is NOT the std::vector
public:
        /**
        * @brief Vector Constructor
        *
        * This is a default construct for the Vector Class
        */
    Vector();

        /**
        * @brief Vector Copy Constructor
        *
        * This is a default copy construct for the Vector Class (Implements a Deep Copy)
        *
        * @param  const Vector &inputVector - Vector to be copied from
        */
    Vector(const Vector &inputVector);

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

        /**
        * @brief Deletes the Vector and sets it back to a size of 1
        *
        * @return void
        */
    void ClearVector(); //Clears the vector of all elements and sets size back to 0
        /**
        * @brief [] OPERATOR OVERLOADING - Used to set the values for the Vector
        *
        * @return T& operator
        *
        * @param  unsigned index - Index of the data
        */
    T operator [](unsigned index); //Set METHOD - Used to set the values
        /**
        * @brief [] OPERATOR OVERLOADING - Used to return the values from the Vector
        *
        * @return const T operator
        *
        * @param  unsigned index - Index of the data
        */
    T& operator [](unsigned index) const; //GET METHOD - Returns the value using overloading of [] operator
        /**
        * @brief = OPERATOR OVERLOADING - Used to make one vector equal to another
        *
        * @return void
        *
        * @param  const Vector &inputVector - Vector to be copied from
        */
    void operator=(const Vector &inputVector);
private:
    T* data; //Showing the data that is going to go into the vector

    unsigned vecSize; //Size of the vector

    unsigned elementAmount; //The current number of elements in the vector

    unsigned vecSizeMultiplier; //The multiplier used to adjust the vector resizing

    void CopyVector(const Vector &inputVector);
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
Vector<T>::Vector(const Vector &dataOriginal)
{
    CopyVector(dataOriginal);
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
    data = nullptr; //Nulls the vector out
}

template <class T>
void Vector<T>::CopyVector(const Vector &inputVector)
{
    vecSize = inputVector.vecSize; //Copys the Vector Size from the original vector
    elementAmount = inputVector.elementAmount; //Copys the Element Amount from the original vector
    vecSizeMultiplier = inputVector.vecSizeMultiplier; //Copys the Vector Multiplier from the original vector

    data = new T[inputVector.vecSize]; //Creates a new vector with the size of the old vector
    *data = *(inputVector.data);
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

        for(unsigned i = 0; i < vecSize; i++) //Adding array elements to the temporary data
        {
            tmpData[i] = data[i];
        }

        delete[] data; //Delete the previous array
        data = nullptr; //Nulls the vector out

        vecSize *= vecSizeMultiplier; //Resize the array to a new multiple

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
    if(elementAmount > 0)
    {
        T* tmpData = new T[elementAmount]; //Create a temporary vector to store the values

        for(unsigned i = 0; i < elementAmount; i++) //Adding array elements to the temporary data
        {
            tmpData[i] = data[i];
        }

        delete[] data; //Delete the previous array
        data = nullptr; //Nulls the vector out

        vecSize = elementAmount; //Resize the array to the amount of elements currently in the array

        data = tmpData; //Make the original array equal to the new temporary array ()
    }
    else
        cout << "ERROR: Amount of elements is less than 1, shrinking unnecessary" << endl;
}

template <class T>
void Vector<T>::ClearVector() //Clears the vector of all elements and sets size back to 0
{
    if(elementAmount > 0)
    {
        T* tmpData = new T[1]; //Create a temporary vector of size 1

        delete[] data; //Delete the array, freeing memory
        data = nullptr; //Nulls the vector out

        vecSize = 1; //Sets the indicated size
        elementAmount = 0; //Sets the number of elements within the vector

        data = tmpData; //Make the original array equal to the new temporary array ()
    }
    else
        cout << "ERROR: Amount of elements is less than 1, shrinking unnecessary" << endl;
}

template <class T>
T Vector<T>::operator [](unsigned index) //Set METHOD - Used to set the values
{
    //Checks to see if the element that is being searched for is within bounds
    if(index >= vecSize)
    {
        throw std::out_of_range("ERROR: Vector out of bounds!");
    }
    else
        return data[index]; //Returns Vector element
}

template <class T>
T& Vector<T>::operator [](unsigned index) const //GET METHOD - Returns the value using overloading of [] operator
{
    //Checks to see if the element that is being searched for is within bounds
    if(index >= vecSize)
    {
        throw std::out_of_range("ERROR: Vector out of bounds!");
    }
    else
        return data[index]; //Returns Vector element
}

template <class T>
void Vector<T>::operator=(const Vector &inputVector)
{
    CopyVector(inputVector); //Calls the Copy Vector function
}

#endif
