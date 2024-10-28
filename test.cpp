#include <iostream>

// 변수는 선언될 때, 컴퓨터의 메모리에서 특정 크기만큼 공간이 할당됩니다. 이 공간을 고유하게 식별하는 값이 바로 "메모리 주소"이다.
// 예를 들어, int a = 5;를 선언하면, a는 4바이트(32비트) 공간을 차지하며, 이 공간의 시작 위치가 &a로 표현되는 메모리 주소이다
// 메모리 주소는 해당 변수의 데이터를 읽거나 수정할 때 사용됩니다. 따라서 변수는 값 자체보다는 메모리 주소를 통해 데이터에 접근하는 방식으로 동작한다.

// 아래의 코드의 결과값
// d1 address: 0x7ffedffcb6e0
// d2 address: 0x7ffedffcb6d8
// d1 value: 0x7ffedffcb708
// d2 value: 0x7ffedffcb708
// 쉽게 설명해서
// 0x7ffedffcb6e0 이 주소는 d1이라는 포인터 변수의 메모리 이다. 즉, d1 포인터 자체가 저장된 위치이다.
// 0x7ffedffcb708 이 주소는 d1이 가리키고 있는 Data1 구조체의 시작 주소이다. 실제로 Data1 구조체의 멤버(value1, value2)가 이 주소부터 할당되어 있다.

struct Data1
{
	int value1;
	int value2;
};

struct Data2
{
	long long value;
};

int main() {
	Data1 *d1 = new Data1;
	d1->value1 = 1234;
	d1->value2 = 1234;
	Data2 *d2 = reinterpret_cast<Data2 *>(d1);

	std::cout << "d1 address: " << &d1 << std::endl;
	std::cout << "d2 address: " << &d2 << std::endl;
	std::cout << "d1 value: " << d1 << std::endl;
	std::cout << "d2 value: " << d2 << std::endl;
	delete d1;
	return 0;
}