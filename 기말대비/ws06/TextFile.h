#define _CRT_SECURE_NO_WARNINGS


#ifndef SDDS_TEXTFILE_H_
#define SDDS_TEXTFILE_H_
#include <iostream>

namespace sdds {

    class TextFile; // forward declaration
    class Line {
        char* m_value = nullptr;
        operator const char* ()const { return (const char*)m_value; };
        Line& operator=(const char* lineContent) {
            delete[] m_value;
            m_value = new char[strlen(lineContent) + 1];
            strcpy(m_value, lineContent);
            return *this;
        };
        friend class TextFile;
        Line() {};
        ~Line() {
            delete[] m_value;
        };
        // incomplete...
        Line(const Line& I) = delete;
        Line& operator=(const Line& other) = delete;
    };
    class TextFile {
        Line* m_textLines;
        char* m_filename;
        unsigned m_noOfLines; //양수만 받겟다. 음수는 받지 않겠다.
        unsigned m_pageSize;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile&);
        TextFile& operator=(const TextFile&);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
}
#endif // !SDDS_TEXTFILE_H_


