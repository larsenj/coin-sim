/*  
 *  CommoNet.cpp
 *
 */

#include <ctime>
#include "CommoNet.h"
#include "EntityManager.h"

//send message to another cell
void CommoNet::Send(double delay, int sender, int receiver, int msg, void* ExtraInfo){
    //pointer to receiver
    Cell* Receiver = EntityMgr->GetEntityFromID(receiver);

    //create message
    Message message(delay, sender, receiver, msg, ExtraInfo);

    if (delay <= 0)
        Dispatch(Receiver, message);
    //if the messgage is to be delayed, stash it in the priority queue
    else {
        double CurrentTime = Clock->GetCurrentTime();
        message.DispatchTime = CurrentTime + delay;
        PriorityDispatch.insert(message);
    }
}//end Send

void CommoNet::SendDelayed(){
    double CurrentTime = Clock->GetCurrentTime();
    //check if need to send delayed messages, remove expired ones
    while(PriorityDispatch.begin()->DispatchTime < CurrentTime &&
            PriorityDispatch.begin()->DispatchTime > 0) {
        //get front of queue
        Message message = *PriorityDispatch.begin();
        //get recipient
        Cell* Receiver = EntityMgr->GetEntityFromID(message.Receiver);
        Dispatch(Receiver, message);
        //dequeue
        PriorityDispatch.erase(PriorityDispatch.begin());
    }//end while
}//end SendDelayed
