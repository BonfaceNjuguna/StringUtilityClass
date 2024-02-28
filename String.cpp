#include <iostream>
#include "String.h"
#include <cstring>

//default constructor
String::String() : m_str(nullptr), m_length(0), m_capacity(0){}

//constructor C-style
String::String(const char* _str)
{
	m_length = strlen(_str);
	m_capacity = m_length + 1;
	m_str = new char[m_capacity];
	strcpy_s(m_str, m_capacity, _str);
}

//copy constructor
String::String(const String& _other)
{
	m_length = _other.m_length;
	m_capacity = _other.m_capacity;
	m_str = new char[m_capacity];
	strcpy_s(m_str, m_capacity, _other.CStr());
}

//destructor
String::~String()
{
	delete[] m_str;
}

//length of the string
size_t String::Length() const
{
	return m_length;
}

//character at specified index
char& String::CharacterAt(size_t _index)
{
	return m_str[_index];
}

const char& String::CharacterAt(size_t _index) const
{
	return m_str[_index];
}

bool String::EqualTo(const String& _other) const 
{
	return strcmp(m_str, _other.CStr()) == 0;
}

//append
String& String::Append(const String& _str)
{
	size_t newLength = m_length + _str.m_length;
	size_t newCapacity = newLength + 1;

	char* temp = new char[newCapacity];
	strcpy_s(temp, newCapacity, m_str);
	strcat_s(temp, newCapacity, _str.CStr());

	delete[] m_str;

	m_str = temp;
	m_length = newLength;
	m_capacity = newCapacity;

	return *this;
}

//prepend
String& String::Prepend(const String& _str)
{
	size_t newLength = m_length + _str.m_length;
	size_t newCapacity = newLength + 1;

	char* temp = new char[newCapacity];
	strcpy_s(temp, newCapacity, _str.CStr());
	strcat_s(temp, newCapacity, m_str);

	delete[] m_str;

	m_str = temp;
	m_length = newLength;
	m_capacity = newCapacity;

	return *this;
}

//C-style
const char* String::CStr() const
{
	return m_str;
}

//lowercase
String& String::ToLower()
{
	for (size_t i = 0; i < m_length; i++)
	{
		if (m_str[i] >= 'A' && m_str[i] <= 'Z')
		{
			m_str[i] += 32;
		}
	}
	return *this;
}

//uppercase
String& String::ToUpper()
{
	for (size_t i = 0; i < m_length; i++)
	{
		if (m_str[i] >= 'a' && m_str[i] <= 'z')
		{
			m_str[i] -= 32;
		}
	}
	return *this;
}

size_t String::Find(const String& _str)
{
	return Find(0, _str);
}

size_t String::Find(size_t _startIndex, const String& _replace)
{
	return 0;
}

String& String::Replace(const String& _find, const String& _replace)
{
	return *this;
}

String& String::ReadFromConsole()
{
	char buffer[256];
	std::cin.getline(buffer, 256);
	*this = buffer;
	return *this;
}

String& String::WriteToConsole()
{
	std::cout << m_str;
	return *this;
}

bool String::operator==(const String& _other)
{
	return EqualTo(_other);
}

bool String::operator!=(const String& _other)
{
	return !EqualTo(_other);
}

String& String::operator=(const String& _str)
{
	if (this != &_str)
	{
		delete[] m_str;
		m_str = new char[_str.m_length + 1];
		strcpy_s(m_str, _str.m_length + 1, _str.CStr());
	}
	return *this;
}

char& String::operator[](size_t _index)
{
	return CharacterAt(_index);
}

const char& String::operator[](size_t _index) const
{
	return CharacterAt(_index);
}

bool String::operator<(const String& _other) const
{
	return strcmp(m_str, _other.CStr()) < 0;
}

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