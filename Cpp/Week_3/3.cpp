/*
003:编程填空：统计动物数量
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
代码填空，使得程序能够自动统计当前各种动物的数量

#include <iostream>
using namespace std;
// 在此处补充你的代码
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}
输入
无
输出
0 animals in the zoo, 0 of them are dogs, 0 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
6 animals in the zoo, 3 of them are dogs, 3 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
样例输入
None
样例输出
0 animals in the zoo, 0 of them are dogs, 0 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
6 animals in the zoo, 3 of them are dogs, 3 of them are cats
3 animals in the zoo, 2 of them are dogs, 1 of them are cats
*/

#include <iostream>
using namespace std;
// 在此处补充你的代码
class Animal{
    public:
        static int number;
        Animal(){
            number++;
        }
        // Animal(Animal &a){
        //     number++;
        // }
        virtual ~Animal(){
            number--;
        }
};

class Dog : public Animal{
    public:
        static int number;
        Dog(){
            number++;
        }
        // Dog(Dog &d){
        //     number++;
        // }
        ~Dog(){
            number--;
        }
};

class Cat : public Animal{
    public:
        static int number;
        Cat(){
            number++;
        }
        // Cat(Cat &c){
        //     number++;
        // }
        ~Cat(){
            number--;
        }
};

int Animal::number=0, Dog::number=0, Cat::number=0;


void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}