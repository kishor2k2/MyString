#include "MyString.h"
#include <cstring>

MyString::MyString() : data_(nullptr), length_(0) {}

MyString::MyString(const char* s) {
	length_ = strlen(s);
	data_ = new char[length_ + 1];
	strcpy_s(data_, length_+1, s);
}

MyString::MyString(const MyString& rhs) {
	length_ = rhs.length_;
	strcpy_s(data_, length_+1, rhs.data_);
}

MyString::MyString(MyString&& rhs) noexcept : data_(rhs.data_), length_(rhs.length_) {
	rhs.data_ = nullptr;
	rhs.length_ = 0;
}

MyString::~MyString() {
	delete[] data_;
}

size_t MyString::length() const noexcept {
	return length_;
}

size_t MyString::size() const noexcept {
	return length();
}

bool MyString::empty() const noexcept {
	return length_ == 0;
}

const char* MyString::c_str() const noexcept {
	return data_;
}

MyString& MyString::operator=(const MyString& rhs) {
	if (this != &rhs) {
		delete[] data_;
		length_ = rhs.length_;
		data_ = new char[length_ + 1];
		strcpy_s(data_, rhs.length_+1, rhs.data_);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& rhs) noexcept {
	if (this != &rhs) {
		delete[] data_;
		data_ = rhs.data_;
		length_ = rhs.length_;
		rhs.data_ = nullptr;
		rhs.length_ = 0;
	}
	return *this;
}

char& MyString::operator[](size_t index) {
	return data_[index];
}

const char& MyString::operator[](size_t index) const {
	return data_[index];
}

std::ostream& operator<<(std::ostream& out, const MyString& str) {
	if (str.data_) {
		out << str.data_;
	}
	return out;
}