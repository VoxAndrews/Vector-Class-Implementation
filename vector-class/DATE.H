// Date.H - Date class definition
// author Darcy Lyndon Cukrov Wilson

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>  // C++ string library

using std::string;

/**
* @class Date
* @brief Manages information for a specific results allocation date
*
* A Date Object contains a day, month and year for a specific result.
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 27/03/2022 Darcy Lyndon Cukrov Wilson
*/

class Date {
public:
    /**
    * @brief Date Constructor
    *
    * This is a default construct for the Date Class
    */
  Date();

    /**
    * @brief Date Constructor, allowing for user input
    *
    * This is a default construct for the Date Class which allows for user inputs
    */
  Date( unsigned tmpDay, unsigned tmpMonth, unsigned tmpYear );

    /**
    * @brief Returns the day that a mark was created
    *
    * @return unsigned int
    */
  unsigned GetDay() const;

    /**
    * @brief Sets the day that a mark was created
    *
    * @param  unsigned tmpDay - The temporary value of the day which is passed in to set the current day value
    * @return void
    */
  void SetDay( unsigned tmpDay );

    /**
    * @brief Returns the month that a mark was created
    *
    * @return unsigned
    */
  unsigned GetMonth() const;

    /**
    * @brief Sets the month that a mark was created
    *
    * @param  unsigned tmpMonth - The temporary value of the month which is passed in to set the current month value
    * @return void
    */
  void SetMonth( unsigned tmpMonth );

    /**
    * @brief Returns the year that a mark was created
    *
    * @return unsigned int
    */
  unsigned GetYear() const;

    /**
    * @brief Sets the year that a mark was created
    *
    * @param  unsigned tmpYear - The temporary value of the year which is passed in to set the current year value
    * @return void
    */
  void SetYear( unsigned tmpYear );
private: //Usually Doxygen comments are NOT added for private variables, but for the sake of learning, they are here
    /**
    * @param  unsigned day - The value of the day the mark was given
    */
  unsigned day; //Stores a day value (Day that the result was set)
    /**
    * @param  unsigned month - The value of the month the mark was given
    */
  unsigned month; //Stores a Month value (Month that the result was set)
    /**
    * @param  unsigned year - The value of the year the mark was given
    */
  unsigned year; //Stores a Year value (Year that the result was set)
};

#endif
