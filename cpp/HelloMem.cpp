//
//  HelloMem.cpp
//  
//
//  Created by Sayak Kundu on 29/05/22.
//

#include <memory>
#include <iostream>

typedef struct {
	int a;
	char b;
	double c;
	double d;
} MyType;

void foo(std::shared_ptr<int> p, std::unique_ptr<int> q) {
	std::cout << "\n--------";

	std::cout << "\n within foo p is pointing to : " << p;
	std::cout << "\n p's reference count is : " << p.use_count();
	std::cout << "\n sizeof p: " << sizeof(p);
	std::cout << "\n within foo q is pointing to : " << q;
	std::cout << "\n sizeof q: " << sizeof(q);

/*
	auto leakyPtr = new int(3);
	std::cout << "\n leakyPtr points to: " << leakyPtr;
	std::cout << "\n sizeof leakyPtr: " << sizeof(leakyPtr);

	auto leakyPtr2 = new double(9.1);
	std::cout << "\n leakyPtr2 points to: " << leakyPtr2;
	std::cout << "\n sizeof leakyPtr2: " << sizeof(leakyPtr2);

	auto leakyPtr3 = new MyType;
	std::cout << "\n leakyPtr3 points to: " << leakyPtr3;
	std::cout << "\n sizeof leakyPtr3: " << sizeof(leakyPtr3);
*/

	auto p1 = std::shared_ptr<int>(new int(32));
	std::cout << "\n p1 points to : " << p1;
	p1 = std::shared_ptr<int>(new int(53));
	std::cout << "\n p1 now points to : " << p1;	
	

	std::cout << "\n--------";
}


int main() {

	int i = 32;
	std::cout << "\n size of int: " << sizeof(i);
	double j = 31.1;
	std::cout << "\n size of double: " << sizeof(j);
	MyType s;
	std::cout << "\n size of MyType: " << sizeof(s);

    auto p = std::shared_ptr<int>(new int(2));
    auto q = std::unique_ptr<int>(new int(4));

    std::cout << "\n p is now : " << p;
	std::cout << "\n p's reference count is : " << p.use_count();
	std::cout << "\n sizeof p: " << sizeof(p);

    std::cout << "\n q is now : " << q;
	std::cout << "\n sizeof q: " << sizeof(q);
	
	foo(p, std::move(q));
    
	std::cout << "\n p is now : " << p;
	std::cout << "\n p's reference count is : " << p.use_count();
	std::cout << "\n sizeof p: " << sizeof(p);
	
	std::cout << "\n q is now : " << q;
	std::cout << "\n sizeof q: " << sizeof(q);
	
	std::cout << "\n";
    return 0;
};
