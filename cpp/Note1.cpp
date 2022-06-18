#include <memory>
#include <iostream>

void foo(std::unique_ptr<int> q) {
    std::cout << "\n within foo q is pointing to : " << q;
}

int main() {
	auto q = std::unique_ptr<int>(new int(4));
	std::cout << "\n q is now : " << q;
	foo(std::move(q));
	std::cout << "\n q is now : " << q;
	std::cout << "\n";
	return 0;
}
