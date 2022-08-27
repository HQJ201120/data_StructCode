#include "SeqQueue.h"

typedef struct MyStruct
{
	char name[64];
	int age;

}Mystruct;

int main(void)
{
	SeqQueue* queue = Init_SeqQueue();

	//创建数据
	Mystruct M1 = { "hjj",18 };
	Mystruct M2 = { "xyf",99 };
	Mystruct M3 = { "hrj",99 };
	Mystruct M4 = { "lhl",99 };
	Mystruct M5 = { "zjw",99 };

	Push_SeqQueue(queue, &M1);
	Push_SeqQueue(queue, &M2);
	Push_SeqQueue(queue, &M3);
	Push_SeqQueue(queue, &M4);
	Push_SeqQueue(queue, &M5);

	Mystruct* backstr = (Mystruct*)Back_SeqQueue(queue);
	printf("name: %s,age: %d\n", backstr->name, backstr->age);

	while (Size_SeqQueue(queue) > 0)
	{
		Mystruct* Mystr = (Mystruct*)Top_SeqQueue(queue);
		printf("name: %s,age: %d\n", Mystr->name, Mystr->age);

		Pop_SeqQueue(queue);
	}

	FreeSpeace_SeqQueue(queue);

	return 0;
}