#include <iostream>
#include "String.h"

//default constructor
String::String(){}

//constructor C-style
String::String(const char* _str){}

//copy constructor
String::String(const String& _other){}

//destructor
String::~String(){}

//length of the string
size_t String::Length() const
{
	
}

//character at specified index
char& String::CharacterAt(size_t _index)
{

}

const char& String::CharacterAt(size_t _index) const
{

}

bool String::EqualTo(const String& _other) const 
{

}

//append
String& String::Append(const String& _str)
{

}

//prepend
String& String::Prepend(const String& _str)
{

}

//C-style
const char* String::CStr() const
{

}

//lowercase
String& String::ToLower()
{

}

//uppercase
String& String::ToUpper()
{

}

size_t String::Find(const String& _str)
{

}

size_t String::Find(size_t _startIndex, const String& _replace)
{

}

String& String::Replace(const String& _find, const String& _replace)
{

}

String& String::ReadFromConsole()
{

}

String& String::WriteToConsole()
{

}

bool String::operator==(const String& _other)
{

}

bool String::operator!=(const String& _other)
{
	
}

String& String::operator=(const String& _str)
{

}

char& String::operator[](size_t _index)
{

}

const char& String::operator[](size_t _index) const
{

}

String String::operator+(const String& _other) const
{
	
}

String& String::operator+=(const String& _other)
{

}