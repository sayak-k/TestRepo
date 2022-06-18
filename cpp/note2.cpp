#include <memory>
#include <iostream>

void foo(std::shared_ptr<int> p) {
	std::cout << "\n within foo p is pointing to : " << p;
	std::cout << "\n p's reference count is : " << p.use_count();
}


int main() {
    auto p = std::shared_ptr<int>(new int(2));
    std::cout << "\n p is now : " << p;
	std::cout << "\n p's reference count is : " << p.use_count();
	foo(p);
	std::cout << "\n p is now : " << p;
	std::cout << "\n p's reference count is : " << p.use_count();
	std::cout << "\n";
    return 0;
};
