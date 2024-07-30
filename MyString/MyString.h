#ifndef MYYSTRING_H_
#define MYYSTRING_H_

#include <iostream>

class MyString
{
	char* data_;
	size_t length_;

public:

	MyString();
	MyString(const char* s);
	MyString(const MyString& rhs);
	MyString(MyString&& rhs) noexcept;
	~MyString();

	MyString& operator=(const MyString& rhs);
	MyString& operator=(MyString&& rhs) noexcept;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	size_t length() const noexcept;
	size_t size() const noexcept;
	bool empty() const noexcept;
	const char* c_str() const noexcept;

	friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};


#endif // end of MYYSTRING_H_
