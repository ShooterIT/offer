/*
*
* 面试题1：赋值运算符函数
*
*/

#include <cstring>

//类型定义
class CMyString
{
public:
	CMyString(char *pch = nullptr) :pdata(pch) {}
	CMyString(const CMyString& str) = default;
	CMyString& operator=(const CMyString &str);
	~CMyString(void) = default;
private:
	char *pdata;
};

/*
//一般写法
CMyString & CMyString::operator=(const CMyString & str) //返回类型，参数类型
{
	if (this != &str) {			 //判断是否是同一个
		delete[] pdata;			 //删除当前实例内存
		pdata = nullptr;		 //清空指针
		pdata = new char[strlen(str.pdata) + 1];	//申请新的内存
		strcpy(pdata, str.pdata);//拷贝传入数据		
	}
	return *this; //返回自身引用
}
*/


//异常安全
CMyString & CMyString::operator=(const CMyString & str)//返回类型，参数类型
{
	if (this != &str) {			//判断是否是同一个
		CMyString tmp_str(str);	//创建临时实例，离开作用后就会是否临时实例
		
		//交换数据
		char *ptmp = tmp_str.pdata; 
		tmp_str.pdata = pdata;
		pdata = ptmp;
	}

	return *this; //返回自身引用
}


