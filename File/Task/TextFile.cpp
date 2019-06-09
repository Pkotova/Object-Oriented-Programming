#include "pch.h"
#include "TextFile.h"
#include <iostream>
#include <cstring>
#include "File.h"
using namespace std;

TextFile::TextFile() : TextFile("Default","Default")
{}

TextFile::TextFile(const TextFile& other) : TextFile(other.name, other.content)
{}

TextFile::TextFile(const char* name, const char* content) : File(name), content(nullptr)
{
	addContent(content);
}
TextFile& TextFile::operator=(const TextFile& other)
{
	if (this != &other)
	{
		File::operator=(other);
		addContent(other.content);
	}
	return *this;
}
void TextFile::addContent(const char* _content)
{
	if (_content != nullptr)
	{
		delete[] content;
		this->content = new char[strlen(_content) + 1];
		strcpy_s(this->content, strlen(_content) + 1, _content);
	}
}
char* TextFile::getContent()const
{
	return this->content;
}
int TextFile::size()const
{
	return (strlen(this->content) - 1);
}
void TextFile::print()const
{
	cout << endl;
	cout << "Text file: ";
	File::print();
	cout << "Content: " << this->content << endl;
}
TextFile* TextFile::clone()const
{
	return new TextFile(*this);
}
bool TextFile::operator==(const TextFile& f)
{
	return (strcmp(this->name, f.name) == 0);
}
TextFile::~TextFile()
{
	delete[] this->name;
}
