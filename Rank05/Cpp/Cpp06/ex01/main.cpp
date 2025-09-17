#include "Serializer.hpp"

int main(void)
{
    Data*       rbPtr = new Data;
    Data*       ptr;

    rbPtr->enqueue(1);
    rbPtr->enqueue(2);
    rbPtr->enqueue(3);
    rbPtr->enqueue(4);
    rbPtr->enqueue(5);
    rbPtr->enqueue(6);
    rbPtr->enqueue(7);
    rbPtr->enqueue(8);
    rbPtr->enqueue(9);

    std::cout << "Begin of ring buffer before dequeue : " << rbPtr->getFirst() << "\n";
    rbPtr->dequeue();
    std::cout << "Begin of ring buffer after dequeue : " << rbPtr->getFirst() << "\n";
    rbPtr->enqueue(9);

    std::cout << "Ring buffer status before serializer\n" << *rbPtr;

    ptr = Serializer::deserialize(Serializer::serialize(rbPtr));
    std::cout << "rbPtr : " << rbPtr << "\n";
    std::cout << "ptr   : " << ptr << "\n";


    std::cout << "Ring buffer status after serializer\n" << *ptr;

    delete rbPtr;
    return (0);
}