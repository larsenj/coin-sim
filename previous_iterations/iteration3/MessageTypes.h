/*
 * MessageTypes.h
 *
 */

#ifndef MESSAGETYPES_H
#define MESSAGETYPES_H

#include <string>

enum message_type{
    Msg_push_supplies,
    Msg_push_intel,
    Msg_pull_med,
    Msg_leader_dead,
    Msg_leader_alive,
    Msg_supplier_dead,
    Msg_supplier_alive,
    Msg_im_dead,
    Msg_im_alive
};

inline std::string MsgToStr(int msg){
    switch(msg){
        case Msg_push_supplies:
            return "Pushing supplies";
        case Msg_push_intel:
            return "Pushing intel";
        case Msg_pull_med:
            return "Seeking medical attention";
        case Msg_im_dead:
            return "Just FYI: I'm dead"; //"Avenge me!"
        case Msg_im_alive:
            return "Locked, cocked, and ready to rock";
        case Msg_leader_dead:
            return "HQ cell down";
        case Msg_leader_alive:
            return "HQ cell up";
        case Msg_supplier_dead:
            return "Log cell down";
        case Msg_supplier_alive:
            return "Log cell up";
        default:
            return "Say again, over";
    }//end switch
}

#endif
