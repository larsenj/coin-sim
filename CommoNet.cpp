/*  
 *  CommoNet.cpp
 *
 */

#include <ctime>
#include <iostream>
#include <chrono>
#include "CommoNet.h"
#include "EntityManager.h"

//singleton pattern
CommoNet* CommoNet::Instance(){
    static CommoNet instance;
    return &instance;
}//end Instance()

//actual dispatching of the message
void CommoNet::Dispatch(Cell* cReceiver, const Message& message){
    if(!cReceiver->HandleMessage(message))
        std::cout << "You called the wrong number" << std::endl;
}//end Dispatch()

//send message to another cell
void CommoNet::Send(double delay, int sender, int receiver, int msg, void* ExtraInfo = nullptr){
    //pointer to receiver
    Cell* Receiver = EntityMgr->GetEntityFromID(receiver);

    //error checking
    if (Receiver == NULL){
        std::cout << "Receiver does not exist" << std::endl;
        return;
    }

    //create message
    Message message(delay, sender, receiver, msg, ExtraInfo);

    if (delay <= 0.0)
        Dispatch(Receiver, message);
    //if the messgage is to be delayed, stash it in the priority queue
    else {
        //std::chrono is used to get times in seconds with 2-3 places after 
        //the decimal. Needed for comparing against the SmallestDelay variable
        //found in "Message.h"
        std::chrono::milliseconds ms = 
            std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now().time_since_epoch());        
        double CurrentTime = (ms.count()%1000000000) / 1000.00;
        //clock_t t = clock()
        //double CurrentTime = Clock->GetCurrentTime();
        message.DispatchTime = CurrentTime + delay;
        PriorityDispatch.insert(message);
    }
}//end Send

void CommoNet::SendDelayed(){
    std::chrono::milliseconds ms = 
        std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch());        
    double CurrentTime = (ms.count()%1000000000) / 1000.00;
    //double CurrentTime = Clock->GetCurrentTime();
    //check if need to send delayed messages, remove expired ones
    while(!PriorityDispatch.empty() &&
            PriorityDispatch.begin()->DispatchTime < CurrentTime &&
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
