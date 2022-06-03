// Unit.H - Unit class definition
// author Darcy Lyndon Cukrov Wilson

#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>  // C++ string library

using std::string;

/**
* @class Unit
* @brief Manages information for a specific Unit
*
* Unit Data is taken in through this file and transfered through to RESULTS.CPP/RESULTS.H.
* From there, they move through to RESULTS.CPP/RESULTS.H where they are appended to the start
* of the results, and finally, are taken through REGIST.CPP/REGIST.H, and printed in MAIN.CPP.
*
* A Unit Object contains a Unit ID, Unit Name, and total Credits for the Unit.
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 21/03/2022 Darcy Lyndon Cukrov Wilson
*/

class Unit {
public:
    /**
    * @brief Unit Constructor
    *
    * This is a default construct for the Unit Class
    */
  Unit();

    /**
    * @brief Unit Constructor, allowing for user input
    *
    * This is a default construct for the Unit Class which allows for user inputs
    */
  Unit( std::string nam, std::string tempID, unsigned cred,
        std::string tmpCoordName, std::string tmpCoordRoomNum,
        std::string tmpCoordEmail, std::string tmpCoordPhoneNum );

    /**
    * @brief Returns the unit name
    *
    * @return string
    */
  string GetName() const;

    /**
    * @brief Sets the unit name
    *
    * @param  string tmpName - The temporary value of the unit name which is passed in to set the current unit name value
    * @return void
    */
  void SetName( string tmpName );

    /**
    * @brief Returns the unit name
    *
    * @return string
    */
  string GetUnitID() const;

    /**
    * @brief Sets the unit name
    *
    * @param  string tmpID - The temporary value of the unit name which is passed in to set the current unit name value
    * @return void
    */
  void SetUnitID( string tmpID );

    /**
    * @brief Returns the current credit amount
    *
    * This function gets the current amount of credits and returns it to the user.
    *
    * @return unsigned int
    */
  unsigned GetCredits() const;

    /**
    * @brief Sets the current credit amount
    *
    * This function sets the current amount of credits from a temporary input value.
    *
    * @param  unsigned cred - The temporary value of credits which is passed in to set the current credit value
    * @return void
    */
  void SetCredits( unsigned cred );

    /**
    * @brief Returns the unit coordinator's name
    *
    * @return string
    */
  string GetCoordName() const;

    /**
    * @brief Sets the unit coordinator's name
    *
    * @param  string tmpCoordName - The temporary value of the unit coordinators name
    * @return void
    */
  void SetCoordName( string tmpCoordName );

    /**
    * @brief Returns the unit coordinator's room number
    *
    * @return string
    */
  string GetCoordRoomNum() const;

    /**
    * @brief Sets the unit coordinators room number
    *
    * @param  string tmpCoordRoomNum - The temporary value of the unit coordinators room number
    * @return void
    */
  void SetCoordRoomNum( string tmpCoordRoomNum );

    /**
    * @brief Returns the unit coordinator's email address
    *
    * @return string
    */
  string GetCoordEmail() const;

    /**
    * @brief Sets the unit coordinators email address
    *
    * @param  string tmpCoordEmail - The temporary value of the unit coordinators email address
    * @return void
    */
  void SetCoordEmail( string tmpCoordEmail );

    /**
    * @brief Returns the unit coordinator's phone number
    *
    * @return string
    */
  string GetCoordPhoneNum() const;

    /**
    * @brief Sets the unit coordinators phone number
    *
    * @param  string tmpCoordPhoneNum - The temporary value of the unit coordinators phone number
    * @return void
    */
  void SetCoordPhoneNum( string tmpCoordPhoneNum );
private: //Usually Doxygen comments are NOT added for private variables, but for the sake of learning, they are here
    /**
    * @param  string name - The name of a given unit
    */
  std::string name;  // Unit name
    /**
    * @param  string id - The ID Number of a given unit
    */
  std::string id;   // Unit ID Number
    /**
    * @param  int credits - The number of credits in a unit
    */
  int  credits;   // Number of Credits
    /**
    * @param  string coordName - The Unit Coordinator's name
    */
  std::string coordName;   // Unit Coordinator's Name
    /**
    * @param  string coordRoomNum - The Unit Coordinator's room number
    */
  std::string coordRoomNum;   // Unit Coordinator's Room Number
    /**
    * @param  string coordEmail - The Unit Coordinator's email address
    */
  std::string coordEmail;   // Unit Coordinator's Email Address
    /**
    * @param  string coordPhoneNum - The Unit Coordinator's phone number
    */
  std::string coordPhoneNum;   // Unit Coordinator's Phone Number
};

#endif
