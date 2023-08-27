#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"

using namespace std;
namespace sdds {
	void TextFile::setFilename(const char* fname, bool isCopy)
	{
		if (isCopy)
		{
			if (fname)
			{
				delete[] m_filename;
				m_filename = new char[strlen(fname) + 1];
				strcpy(m_filename, "C_");
				strcat(m_filename, fname);
			}
		}
		else
		{	
			if (fname)
			{
				delete[] m_filename;
				m_filename = new char[strlen(fname) + 1];
				strcpy(m_filename, fname);
			}
		}
	}

	void TextFile::setNoOfLines()
	{
		m_noOfLines = 0;
		ifstream is(m_filename);
		char ch = '\0';
		while ((ch= is.get()) != EOF)
		{
			if (ch == '\n')
			{
				m_noOfLines++;
			}
		}

		if (m_noOfLines = 0)
		{
			delete[] m_filename;
			m_filename = nullptr;
		}
		else
		{
			m_noOfLines++;
		}
	}

	void TextFile::loadText()
	{
		if (m_filename)
		{
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];

			ifstream is(m_filename);
			string str;
			int i;
			for (i = 0; getline(is, str); i++)
			{
				m_textLines[i] = str.c_str();
			}
			m_noOfLines = i;
		}
	}

	void TextFile::saveAs(const char* fileName) const
	{
		if (fileName)
		{
			ofstream os(fileName);
			for (int i = 0; i < (int)m_noOfLines; i++)
			{
				os << m_textLines[i] << endl;
			}
		}
	}

	void sdds::TextFile::setEmpty()
	{
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	TextFile::TextFile(unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(0)
	{
		setEmpty();
		m_pageSize = pageSize;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(0)
	{
		setEmpty();
		m_pageSize = pageSize;
		setFilename(filename);
		setNoOfLines();
		loadText();
	}

	TextFile::TextFile(const TextFile& I) : m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(0)
	{
		setEmpty();
		m_pageSize = I.m_pageSize;
		
		if (I)
		{
			setFilename(I.m_filename, true);
			I.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile& TextFile::operator=(const TextFile& other)
	{
		if ((this != &other) && *this && other)
		{
			delete[] m_textLines;
			m_textLines = nullptr;
			other.saveAs(m_filename);
			setNoOfLines();
			loadText();
		}

		return *this;
	}

	TextFile::~TextFile()
	{
		delete[] m_filename;
		delete[] m_textLines;
	}

	std::ostream& TextFile::view(std::ostream& ostr) const
	{
		if (*this)
		{
			cout << m_filename << endl;
			ostr.width(strlen(m_filename));
			ostr.fill('=');
			ostr << '=';
			ostr << endl;
			for (int i = 0; i < (int)m_noOfLines; i++)
			{
				if (i != 0 && i % m_pageSize == 0)
				{
					ostr << "Hit ENTER to continue...";
					while (cin.get() != '\n');
				}
				ostr << m_textLines[i] << endl;
			}
		}

		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr)
	{
		string filename;
		getline(istr, filename, '\n');
		delete[] m_filename;
		setFilename(filename.c_str());
		setNoOfLines();
		loadText();

		return istr;
	}

	TextFile::operator bool() const
	{
		return !(m_textLines == nullptr && m_filename == nullptr && m_noOfLines == 0);
	}

	unsigned TextFile::lines() const
	{
		return m_noOfLines;
	}

	const char* TextFile::name() const
	{
		return m_filename;
	}

	const char* TextFile::operator[](unsigned index) const
	{
		return *this ? m_textLines[index % m_noOfLines] : (const char*)nullptr;
	}



	std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
	{
		text.view(ostr);

		return ostr;
	}

	std::istream& operator>>(std::istream& istr, TextFile& text)
	{
		text.getFile(istr);

		return istr;
	}
};
