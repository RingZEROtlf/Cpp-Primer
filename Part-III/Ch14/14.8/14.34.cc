template <typename T>
struct IfThenElse
{
    T operator()(bool condition, T a, T b)
    {
        return condition ? a : b;
    }
};