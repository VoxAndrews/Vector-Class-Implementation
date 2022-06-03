// TOOLS.H - Helper Tools
// author Darcy Lyndon Cukrov Wilson

#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>  // C++ string library

using std::string;

/**
* @class Tools
* @brief A Tools class used for creating and applying certain formatting functions to data
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 29/03/2022 Darcy Lyndon Cukrov Wilson
*/

class Tools {
public:
    /**
    * @brief Tools Constructor
    *
    * This is a default construct for the Tools Class
    */
  Tools();

    /**
    * @brief Returns a formatted Month String (E.g. Takes an integer, and outputs a day of the month)
    *
    * @return const string
    */
  string GetMonthFormatted() const;

    /**
    * @brief Sets the month value to be formatted
    *
    * @param  unsigned tmpMonth - The temporary value of the month which is passed in to format into a string
    * @return void
    */
  void SetMonthFormatted( unsigned tmpMonth );
private: //Usually Doxygen comments are NOT added for private variables, but for the sake of learning, they are here
    /**
    * @param  unsigned monthValue - The value of the month which will be taken and used to convert to a string
    */
  unsigned monthValue;
};

#endif

