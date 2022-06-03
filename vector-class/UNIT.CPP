// UNIT.CPP - Unit class implementation

#include "UNIT.H"

Unit::Unit()
{
  name[0] = '\0'; // it is a char * string, not a C++ string object.

  id[0] = '\0'; // it is a char * string, not a C++ string object.

  credits = 0;
}

Unit::Unit( std::string nam, std::string tempID, unsigned cred,
           std::string tmpCoordName, std::string tmpCoordRoomNum,
           std::string tmpCoordEmail, std::string tmpCoordPhoneNum )
{
  name = nam;
  id = tempID;
  credits = cred;

  coordName = tmpCoordName;
  coordRoomNum = tmpCoordRoomNum;
  coordEmail = tmpCoordEmail;
  coordPhoneNum = tmpCoordPhoneNum;
}

string Unit::GetName() const
{
    return name;
}

void Unit::SetName( string tmpName )
{
    name = tmpName;
}

string Unit::GetUnitID() const
{
    return id;
}

void Unit::SetUnitID( string tmpID )
{
    id = tmpID;
}

unsigned Unit::GetCredits() const
{
  return credits;
}

void Unit::SetCredits( unsigned cred )
{
  credits = cred;
}

string Unit::GetCoordName() const
{
    return coordName;
}

void Unit::SetCoordName( string tmpCoordName )
{
    coordName = tmpCoordName;
}

string Unit::GetCoordRoomNum() const
{
    return coordRoomNum;
}

void Unit::SetCoordRoomNum( string tmpCoordRoomNum )
{
    coordRoomNum = tmpCoordRoomNum;
}

string Unit::GetCoordEmail() const
{
    return coordEmail;
}

void Unit::SetCoordEmail( string tmpCoordEmail )
{
    coordEmail = tmpCoordEmail;
}

string Unit::GetCoordPhoneNum() const
{
    return coordPhoneNum;
}

void Unit::SetCoordPhoneNum( string tmpCoordPhoneNum )
{
    coordPhoneNum = tmpCoordPhoneNum;
}
