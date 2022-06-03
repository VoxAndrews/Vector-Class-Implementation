// Results.H - Result class definition
// author Darcy Lyndon Cukrov Wilson

#ifndef RESULTS_H
#define RESULTS_H

#include <iostream>
#include <string>  // C++ string library

#include "UNIT.H"
#include "DATE.H"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

/**
* @class Results
* @brief Manages information for Unit Results, as well as taking a Unit Object
*
* A Results Object contains a Unit object and a Unit's results
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 21/03/2022 Darcy Lyndon Cukrov Wilson
*/

class Results {
public:
    /**
    * @brief Results Constructor
    *
    * This is a default construct for the Results Class
    */
  Results();

    /**
    * @brief Results Constructor, allowing for user input
    *
    * This is a default construct for the Results Class which allows for user inputs
    */
  Results( float tmpMarks, Date tmpDate, Unit tmpUnit );

    /**
    * @brief Returns the results for a given unit
    *
    * This function gets the results for a unit and returns it to the user.
    *
    * @return const float
    */
  float GetResults() const;

    /**
    * @brief Sets the results for a given unit
    *
    * This function sets the unit results from a temporary input value.
    *
    * @param  float res - The temporary value of results which is passed in to set the result value
    * @return void
    */
  void SetResults(float res);

    /**
    * @brief Returns the a Unit object
    *
    * This function returns a Unit object and it's associated data to the user
    *
    * @return const Unit
    */
  const Unit& GetUnit() const;

    /**
    * @brief Sets the Unit Object
    *
    * This function sets the Unit Object to a temporary input value.
    *
    * @param  Unit tmpUnit - A temporary Unit object used to set the value of the main Unit object
    * @return void
    */
  void SetUnit(const Unit &tmpUnit);

    /**
    * @brief Returns the a Date object
    *
    * This function returns a Date object and it's associated data to the user
    *
    * @return const Date
    */
  const Date& GetDate() const;

    /**
    * @brief Sets the Date Object
    *
    * This function sets the Date Object to a temporary input value.
    *
    * @param  Date tmpDate - A temporary Date object used to set the value of the main Date object
    * @return void
    */
  void SetDate(const Date &tmpDate);
private:
  Unit inUnit; //Single Unit object

  Date inDate; //Single Date object

  float marks; //Unit results
};

#endif
