#pragma once
#include <iostream>

using namespace std;

#define SIZE 5
int main()
{
#pragma region ���� ����

    // ���ĵ��� ���� �����͵鿡 ���� ���� ���� �����͸�
    // ã�Ƽ� ���� �տ� �ִ� �����Ϳ� ��ȯ�ϴ� �˰����̴�.

    // �ð� ���⵵ O(n^2)


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

