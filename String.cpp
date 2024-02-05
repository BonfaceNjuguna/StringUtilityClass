#include <iostream>
#include "String.h"

//default constructor
String::String(){}

//constructor C-style
String::String(const char* _str)
{
	if (_str)
	{
		data_ = new char[strlen(_str) + 1];
		strcpy_s(data_, strlen(_str) + 1, _str);
	}
	else
	{
		data_ = new char[1];
		data_[0] = '\0';
	}
}

//copy constructor
String::String(const String& _other)
{
	data_ = new char[_other.Length() + 1];
	strcpy_s(data_, _other.Length() + 1, _other.CStr());
}

//destructor
String::~String()
{
	delete[] data_;
}

//length of the string
size_t String::Length() const
{
	return strlen(data_);
}

//character at specified index
char& String::CharacterAt(size_t _index)
{
	return data_[_index];
}

//const char& String::CharacterAt(size_t _index) const
//{
//
//}
//
//bool String::EqualTo(const String& _other) const 
//{
//
//}

//append
String& String::Append(const String& _str)
{
	char* temp = new char[Length() + _str.Length() + 1];
	strcpy_s(temp, Length() + 1, data_);
	strcat_s(temp, Length() + _str.Length() + 1, _str.CStr());
	delete[] data_;
	data_ = temp;
	return *this;
}

////prepend
//String& String::Prepend(const String& _str)
//{
//
//}

//C-style
const char* String::CStr() const
{
	return data_;
}

//lowercase
String& String::ToLower()
{
	for (size_t i = 0; i < Length(); i++)
	{
		if (data_[i] >= 'A' && data_[i] <= 'Z')
		{
			data_[i] += 32;
		}
	}
	return *this;
}

//uppercase
String& String::ToUpper()
{
	for (size_t i = 0; i < Length(); i++)
	{
		if (data_[i] >= 'a' && data_[i] <= 'z')
		{
			data_[i] -= 32;
		}
	}
	return *this;
}

//size_t String::Find(const String& _str)
//{
//
//}
//
//size_t String::Find(size_t _startIndex, const String& _replace)
//{
//
//}
//
//String& String::Replace(const String& _find, const String& _replace)
//{
//
//}
//
//String& String::ReadFromConsole()
//{
//
//}
//
//String& String::WriteToConsole()
//{
//
//}
//
//bool String::operator==(const String& _other)
//{
//
//}
//
//bool String::operator!=(const String& _other)
//{
//	
//}
//
//String& String::operator=(const String& _str)
//{
//
//}
//
//char& String::operator[](size_t _index)
//{
//
//}
//
//const char& String::operator[](size_t _index) const
//{
//
//}
//
//bool String::operator<(const String& _other) const
//{
//
//}

String String::operator+(const String& _other) const
{
	String result = *this;
	result.Append(_other);
	return result;
}

String& String::operator+=(const String& _other)
{
	Append(_other);
	return *this;
}