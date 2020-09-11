class Point
{
public:
    Point() {}
    Point(const Point& point) {}

private:

};

Point global;
Point foo_bar(Point arg)
{
    Point local = arg, *heap = new Point(global);
    *heap = local;
    Point pa[4] = { local, *heap };
    return *heap;
}