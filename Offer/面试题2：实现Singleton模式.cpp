/*
*
* 面试题2：实现Singleton模式
*
*/


//GoF 单例模式的一种实现
class Singleton 
{
private:
	Singleton() {}
	~Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static Singleton *instance;
public:
	static Singleton& get_instance() {
		if (instance == nullptr){
			instance = new Singleton();
		}
		return *instance;
	}
};

Singleton* Singleton::instance = nullptr;

//<<Effective C++>>中的一种实现，线程安全
class Singleton2
{
public:
	static Singleton2& Instance(){
		static Singleton2 instance;
		return instance;
	}
private:
	Singleton2(){}
	~Singleton2(){}
	Singleton2(const Singleton&) = delete;
	Singleton2& operator=(const Singleton&) = delete;
};