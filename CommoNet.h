/*
 *  CommoNet.h
 *  Used for sending messages between entities.
 */

#ifndef COMMONET_H
#define COMMONET_H

#include <set>
#include "EnemyForces/Cell.h"

const double SEND_NOW = 0.0;
const int NO_EXTRA_INFO = 0;

class CommoNet {

    private:
        //container for delayed messages. Set stores the data in a priority 
        //tree and avoids duplicates.
        std::set<Message> PriorityDispatch;
        void Dispatch(Cell* Receiver, const Message& msg);
        CommoNet(){}

    public:
        //singleton
        static CommoNet* Instance();

        //send a message
        void Send(double, int, int, int, void*); //delay,sender,receiver,msg,extra
        //call this each time through main loop
        void SendDelayed();
};

#define Commo CommoNet::Instance()

#endif
