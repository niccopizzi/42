#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void  swap(T& a, T& b)
{
    T temp = b;

    b = a;
    a = temp;
}

template<typename T>
T   min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T   max(T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif // WHATEVER.HPP