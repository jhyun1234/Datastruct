#include <iostream>
#include"CircleQueue.h"
using namespace std;

int main()
{
#pragma region 원형 큐
	// 물리적으로는 선형 구조를 가지고 있으며,
	// 큐의 시작점과 끝점을 연결한 큐이다.


	CircleQueue<int> queue;
	queue.EnQueue(100);
	queue.EnQueue(200);
	queue.EnQueue(300);

	cout << queue.Front() << endl;
	cout << queue.Back() << endl;
	queue.DeQueue();
	queue.DeQueue();
	queue.DeQueue();
	
	
#pragma endregion


}