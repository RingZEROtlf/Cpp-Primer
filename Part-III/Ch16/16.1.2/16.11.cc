template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
    List();
    List(const List&);
    List& operator=(const List&);
    ~List();
    void insert(ListItem *ptr, elemType value);
private:
    ListItem *front, *end;
};