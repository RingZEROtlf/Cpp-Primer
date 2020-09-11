#include <string>

class BinStrTree;

class TreeNode
{
    friend class BinStrTree;
public:
    TreeNode(const std::string &_value, int _count, TreeNode *_left, TreeNode *_right)
        : value(_value), count(_count), left(_left), right(_right), use(new std::size_t(1))
    {
        if (_left) ++_left->use;
        if (_right) ++_right->use;
    }

    TreeNode(const TreeNode &node)
        : value(node.value), count(node.count), 
          left(node.left), right(node.right), use(node.use)
    {
        if (node.left) ++node.left->use;
        if (node.right) ++node.right->use;
    }

    TreeNode& operator=(const TreeNode &rhs)
    {
        ++*rhs.use;
        if (--*use == 0) {
            delete use;
            if (left && --left->use == 0) delete left;
            if (right && --right->use == 0) delete right;
        }
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        use = rhs.use;
        if (rhs.left) ++rhs.left->use;
        if (rhs.right) ++rhs.right->use;
        return *this;
    }

    ~TreeNode()
    {
        if (*use == 0 || --*use == 0) {
            delete use;
            if (left && --left->use == 0) delete left;
            if (right && --right->use == 0) delete right;
        }
    }

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
    std::size_t *use;
};

class BinStrTree
{
public:
    BinStrTree(TreeNode *_root)
        : root(_root)
    {
        ++*_root->use;
    }

    BinStrTree(const BinStrTree &tree)
        : root(tree.root)
    {
        ++*tree.root->use;
    }

    BinStrTree& operator=(const BinStrTree &rhs)
    {
        ++*rhs.root->use;
        if (--*root->use == 0) {
            delete root;
        }
        root = rhs.root;
    }

    ~BinStrTree()
    {
        if (--*root->use == 0) {
            delete root;
        }
    }

private:
    TreeNode *root;
};