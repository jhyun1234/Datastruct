#include <iostream>

using namespace std;

#define SIZE 
int main()
{
#pragma region 선형 큐
	// 배열의 공간에 들어간 데이터가 고정되어 데이터를
	// 빼내더라도 초기화하지 않으며 원래 데이터가 있던
	// 배열의 자리에 더 이상 다른 값이 들어갈 수 없는 Queue 이다.
	// 


	/*Linear<int> queue;
	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);

	
	int size = queue.Size();
	for (int i = 0; i < size; i++)
	{
		cout << queue.Front() << " ";
		queue.Dequeue();
	}
	queue.Dequeue();*/


#pragma endregion

#pragma region 계수 정렬
	// 데이터의 값을 직접 비교하지 않고, 단순하게 각 숫자가
	// 몇 개 있는지 갯수를 세어 저장한 다음 정렬하는 알고리즘이다.

	// 시간 복잡도 : O(n + k)

	int CountingSort[] = {1,1,3,3,4,2,2,4,2,5,5,2,3,5,2,3,1};



#pragma endregion

}