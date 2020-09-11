#ifndef FOLDER_HPP
#define FOLDER_HPP

#include "Message.hpp"

#include <set>

class Folder
{
public:
    Folder() {}
    Folder(const Folder&) = delete;
    Folder& operator=(const Folder&) = delete;

    void addMsg(Message* m)
    {
        messages.insert(m);
    }

    void remMsg(Message* m)
    {
        messages.erase(m);
    }

private:
    std::set<Message*> messages;
};

#endif