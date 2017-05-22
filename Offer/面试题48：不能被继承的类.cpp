/*
*
* 面试题48：不能被继承的类
*
*/

//私有的构造与析构函数
class Sealed
{
public:
	static Sealed *get_instance() {
		new Sealed();
	}
	static void delete_intance(Sealed *instance) {
		delete instance;
	}
private:
	Sealed() {}
	~Sealed(){}
};