/*
*
* 面试题2：实现Singleton模式
*
*/


//GoF 单例模式的一种实现
class Singleton
{
private:
	//构造与析构都是私有的
	Singleton() {}
	~Singleton() {}
	//没有拷贝构造和拷贝运算符
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	//静态的实例指针
	static Singleton *instance;
public:
	//静态获得实例对象的方法
	static Singleton& get_instance() {
		if (instance == nullptr) { //为空，才创建
			instance = new Singleton();
		}
		return *instance; //返回对象的引用
	}
};

Singleton* Singleton::instance = nullptr;

//<<Effective C++>>中的一种实现，线程安全
class Singleton2
{
public:
	static Singleton2& Instance(){
		//第一个函数内部的static实例
		static Singleton2 instance;
		return instance;
	}
private:
	Singleton2(){}
	~Singleton2(){}
	Singleton2(const Singleton&) = delete;
	Singleton2& operator=(const Singleton&) = delete;
};