	#include <iostream>
	#include "String.h"
	#include <cstring>
	#include <cstddef>

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

	//character at specified index (const)
	const char& String::CharacterAt(size_t _index) const
	{
		return m_str[_index];
	}

	//check if the string is equal to another
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

	//C-style string
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

	//find
	size_t String::Find(const String& _str)
	{
		return Find(0, _str);
	}

	//find from index
	size_t String::Find(size_t _startIndex, const String& _str)
	{
		size_t findLength = _str.m_length;
		size_t index = _startIndex;
		while (index < m_length - findLength + 1)
		{
			size_t i = 0;
			while (i < findLength && m_str[index + i] == _str.m_str[i])
			{
				++i;
			}
			if (i == findLength)
			{
				return index;
			}
			++index;
		}
		return SIZE_MAX;
	}

	//replace
	String& String::Replace(const String& _find, const String& _replace)
	{
		size_t findLength = _find.m_length;
		size_t replaceLength = _replace.m_length;
		size_t index = Find(_find);
		while (index != SIZE_MAX)
		{
			if (findLength != replaceLength)
			{
				if (findLength > replaceLength)
				{
					size_t newLength = m_length - findLength + replaceLength;
					size_t newCapacity = newLength + 1;
					char* temp = new char[newCapacity];
					strncpy_s(temp, newCapacity, m_str, index);
					strcat_s(temp, newCapacity, _replace.CStr());
					strcat_s(temp, newCapacity, m_str + index + findLength);
					delete[] m_str;
					m_str = temp;
					m_length = newLength;
					m_capacity = newCapacity;
				}
				else
				{
					size_t newLength = m_length - findLength + replaceLength;
					size_t newCapacity = newLength + 1;
					char* temp = new char[newCapacity];
					strncpy_s(temp, newCapacity, m_str, index);
					strcat_s(temp, newCapacity, _replace.CStr());
					strcat_s(temp, newCapacity, m_str + index + findLength);
					delete[] m_str;
					m_str = temp;
					m_length = newLength;
					m_capacity = newCapacity;
				}
			}
			else
			{
				strncpy_s(m_str + index, m_length - index, _replace.CStr(), replaceLength);
			}
			index = Find(index + replaceLength, _find);
		}
		return *this;
	}

	//read from console
	String& String::ReadFromConsole()
	{
		char buffer[256];
		std::cin.getline(buffer, 256);
		*this = buffer;
		return *this;
	}

	//write to console
	String& String::WriteToConsole()
	{
		std::cout << m_str;
		return *this;
	}

	//operator overload equality
	bool String::operator==(const String& _other)
	{
		return EqualTo(_other);
	}

	//operator overload inequality
	bool String::operator!=(const String& _other)
	{
		return !EqualTo(_other);
	}

	//operator overload assignment
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

	//operator overload subscript
	char& String::operator[](size_t _index)
	{
		return CharacterAt(_index);
	}

	//operator overload subscript(const)
	const char& String::operator[](size_t _index) const
	{
		return CharacterAt(_index);
	}

	//operator overload less than
	bool String::operator<(const String& _other) const
	{
		return strcmp(m_str, _other.CStr()) < 0;
	}

	//operator overload addition
	String String::operator+(const String& _other) const
	{
		String result = *this;
		result.Append(_other);
		return result;
	}

	//operator overload addition assignment
	String& String::operator+=(const String& _other)
	{
		Append(_other);
		return *this;
	}