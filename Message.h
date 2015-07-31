/*
 *  Message.h
 *
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <cmath>

struct Message { 
    int Sender;
    int Receiver;
    int Msg; //see MessageTypes.h note: this is why msg.Msg work in OnMessage
    double DispatchTime;
    void* ExtraInfo;

    Message():DispatchTime(-1), 
                    Sender(-1), 
                    Receiver(-1), 
                    Msg(-1) {}
    
    Message(double time, int sender, int receiver, int msg, void* info = nullptr):
        DispatchTime(time),
        Sender(sender),
        Receiver(receiver),
        Msg(msg),
        ExtraInfo(info) {}
};


/*-----------------------------------------------------------------------------
    The std::set in CommoNet.h needs the below overloaded operators to sort and 
    remove duplicates.
------------------------------------------------------------------------------*/

//so things don't get crazy with inconsequential differences
const double SmallestDelay = 0.25;


//Test if to messages are the same. Check if the absolute value of the time
//difference is less then the minimum we care about, then check to see if the 
//various data fields are the same.
inline bool operator==(const Message& m1, const Message m2){
    return( fabs(m1.DispatchTime - m2.DispatchTime) < SmallestDelay) &&
        (m1.Sender == m2.Sender) &&
        (m1.Receiver == m2.Receiver) &&
        (m1.Msg == m2.Msg);
}

//First make sure they aren't the same message, then see which is earlier
inline bool operator<(const Message& m1, const Message m2){
    if (m1 == m2)
        return false;
    else
        return (m1.DispatchTime < m2.DispatchTime);
}

//debugging stuff to see the messages being sent
inline std::ostream& operator<<(std::ostream& os, const Message& m) {
    os << "time: " << m.DispatchTime << " Sender: " << m.Sender << " Receiver: " << m.Receiver << " Msg: " << m.Msg;
    return os;
}

//helper function for unsing ExtraInfo as an appropriate type
template <class T>
inline T DereferenceToType(void* p){
    return *(T*)(p); //cast p as a pointer of type T, and return a pointer
}

#endif
