#include <iostream>
#include <vector>
using namespace std;

class Screen {

	friend class Window_mgr;
	//friend void Window_mgr::clear(ScreenIndex);
public:
	//Screen���û�����ʹ��pos, �����ȶ����ʹ��,ͨ�������ڿ�ʼ�ط�
	typedef std::string::size_type pos; 
	//using pos=std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}
	char get() const { return contents[cursor]; } //�����塱�����ڲ�������ʽ����
	inline char get(pos r, pos c) const; //��ʽ����������Ϊ����
	Screen& move(pos r, pos c); //�����Ժ�����Ϊ����
	Screen& set(char c);
	Screen& set(pos r, pos c, char ch);
	const Screen& display() const; //�������Ƿ���const���������
	Screen& display();

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr; //mutable��ʹ��const������Ҳ�ܱ��޸�
};

//���ⲿ����ʱ����Ϊ����
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
	return *this; //const�е�*this���ص���ָ����������
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
	Screen& s = screens[idx]; //ʹ�����ý�ʡ���ڿ���
	s.contents = string(s.height * s.width, ' ');
}

void mgr_size(Window_mgr mgr) {
	cout << mgr.screens.size();
}

int main_06_01() {

	Screen myScreen;
	//myScreen.display().set('a');����, display()���س�����������
	myScreen.display(); //���ó������汾
	const Screen conScreen;
	conScreen.display();//���ó����汾

	Window_mgr mgr;
	mgr.clear(0);

	return 0;
}
