//
// Created by Aurélien Brachet on 06/10/2025.
//

#ifndef COMMAND_H
#define COMMAND_H

template<class T>
class Command {
public:
    virtual ~Command() = default;

    virtual void execute(T&) = 0;
};

#endif //COMMAND_H
