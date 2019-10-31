#include <iostream>
#include <vector>
using namespace std;

class Screen {

	friend class Window_mgr;
	//friend void Window_mgr::clear(ScreenIndex);
public:
	//Screen的用户可以使用pos, 必须先定义后使用,通常定义在开始地方
	typedef std::string::size_type pos; 
	//using pos=std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}
	char get() const { return contents[cursor]; } //“定义”在类内部的是隐式内联
	inline char get(pos r, pos c) const; //显式内联，声明为内联
	Screen& move(pos r, pos c); //可在稍后设置为内联
	Screen& set(char c);
	Screen& set(pos r, pos c, char ch);
	const Screen& display() const; //根据类是否是const完成了重载
	Screen& display();

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr; //mutable即使在const函数里也能被修改
};

//在外部定义时声明为内联
inline Screen& Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const {

	++access_ctr;
	pos row = r * width;
	return contents[row + c];
}

Screen& Screen::set(char c) { contents[cursor] = c; return *this; }
Screen& Screen::set(pos r, pos c, char ch) {
	pos row = r * width;
	contents[row + c] = ch;
	return *this;
}
const Screen& Screen::display() const{
	std::cout << contents;
	return *this; //const中的*this返回的是指向常量的引用
}
Screen& Screen::display() {
	std::cout << contents;
	return *this;
}

class Window_mgr {
	
	friend void mgr_size(Window_mgr mgr);
public:
	using ScreenIndex=std::vector<Screen>::size_type;
	void clear(ScreenIndex idx);

private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };

};
void Window_mgr::clear(ScreenIndex idx) {
	
	mgr_size(*this);
	Screen& s = screens[idx]; //使用引用节省多于拷贝
	s.contents = string(s.height * s.width, ' ');
}

void mgr_size(Window_mgr mgr) {
	cout << mgr.screens.size();
}

int main_06_01() {

	Screen myScreen;
	//myScreen.display().set('a');错误, display()返回常量对象引用
	myScreen.display(); //调用常非量版本
	const Screen conScreen;
	conScreen.display();//调用常量版本

	Window_mgr mgr;
	mgr.clear(0);

	return 0;
}
