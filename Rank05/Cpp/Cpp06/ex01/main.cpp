#include "Serializer.hpp"

/* int main(void)
{
    Data    ringBuffer;

    for (int i = 0; i < 8; i++)
        ringBuffer.enqueue(i + 1);
    std::cout << "Ring buffer after enqueue\n" << ringBuffer;

    ringBuffer.dequeue();
    ringBuffer.dequeue();
    std::cout << "Ring buffer after dequeue\n" << ringBuffer;
    ringBuffer.enqueue(30);
    std::cout << "Ring buffer after enqueue\n" << ringBuffer;
} */

int main(void)
{
    Data*       rbPtr = new Data;
    Data*       ptr;

    ptr = Serializer::deserialize(Serializer::serialize(rbPtr));
    std::cout << "rbPtr : " << rbPtr << "\n";
    std::cout << "ptr   : " << ptr << "\n";

    delete rbPtr;
}