#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"

template <class T>
class StateMachine {

    private:
        T* smOwner;//pointer to owner of this SM
        State<T>* currentState;
        State<T>* previousState;//to keep a record
        State<T>* globalState;

    public:
        StateMachine(T* owner): 
            smOwner(owner), currentState(nullptr), previousState(nullptr), 
            globalState(nullptr){}

        //call to update the FSM
        inline void Update()const{
            //check if states are valid, then call their Execute functions
            if(globalState)
                globalState->Execute(smOwner);
            if(currentState)
                currentState->Execute(smOwner);
        }

        //change State
        inline void ChangeState(State<T>* newState){
            assert(newState && "<StateMachine::ChangeState>: trying to change to a null state");
            previousState = currentState;//to maintain the record
            currentState->Exit(smOwner);
            currentState = newState;
            currentState->Enter(smOwner);
        }

        inline void RevertToPrevious(){
            ChangeState(previousState);
        }

        //Getters and setters
        inline void SetCurrentState(State<T>* s){currentState = s;}
        inline void SetPreviousState(State<T>* s){previousState = s;}
        inline void SetGlobalState(State<T>* s){globalState = s;}

        inline State<T>* GetCurrentState() const {return currentState;}
        inline State<T>* GetPreviousState() const {return previousState;}
        inline State<T>* GetGlobalState() const {return globalState;}

        //check if current state same as that passed as param
        inline bool IsIn(const State<T>& st)const;

}//end class

#endif
