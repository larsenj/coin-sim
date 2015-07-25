/*
 *  CommoNet.h
 *
 */

#ifndef COMMONET_H
#define COMMONET_H

#include <set>
#include "EnemyForces/Cell.h"


class CommoNet {

    private:
        //container for delayed messages
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
