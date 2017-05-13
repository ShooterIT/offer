/*
*
* 面试题1：赋值运算符函数
*
*/

#include <cstring>

class CMyString
{
public:
	CMyString(char *pdata = nullptr);
	CMyString(const CMyString& str);
	CMyString& operator=(const CMyString &str);
	~CMyString(void);
private:
	char *pdata;
};

//一般写法
CMyString & CMyString::operator=(const CMyString & str)
{
	if (this != &str) {
		delete[] pdata;
		pdata = nullptr;
		pdata = new char[strlen(str.pdata) + 1];
		strcpy(pdata, str.pdata);
	}
	return *this;
}

//异常安全
CMyString & CMyString::operator=(const CMyString & str)
{
	if (this != &str) {
		CMyString tmp_str(str);
		char *ptmp = tmp_str.pdata;
		tmp_str.pdata = pdata;
		pdata = ptmp;
	}

	return *this;
}


