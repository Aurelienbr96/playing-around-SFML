//
// Created by Aurélien Brachet on 06/10/2025.
//

#ifndef MOVELEFT_H
#define MOVELEFT_H
#include "../command.h"
#include "../player.h"

class MoveLeft: public Command<Player> {
    public:
        void execute(Player& player) override;
};

#endif //MOVELEFT_H
