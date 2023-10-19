#include <iostream>

using namespace std;

#define SIZE 5
int main()
{
#pragma region 선택 정렬

    // 정렬되지 않은 데이터들에 대해 가장 작은 데이터를
    // 찾아서 가장 앞에 있는 데이터와 교환하는 알고리즘이다.
    
    // 시간 복잡도 O(n^2)


    int SelectBuffer[] = { 1,3,4,7,2 };

    int size = sizeof(SelectBuffer) / sizeof(int);

    int temp;
    for (int i = 0; i < size; i++)
    {
        int min = SelectBuffer[i]; // 1
        
        int select = i;

        for (int j = i + 1; j < size; j++)
        {

            if (min > SelectBuffer[j])
            {

                min = SelectBuffer[j];
                select = j;

            }


        }
        std::swap(SelectBuffer[i], SelectBuffer[select]);
    }

    for (int& elemt : SelectBuffer)
    {
        cout << elemt << " ";
    }

#pragma endregion


    
}

