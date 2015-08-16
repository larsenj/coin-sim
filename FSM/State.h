#ifndef STATE_H
#define STATE_H

class State{
    public:
        virtual void Enter(Cell*) = 0;
        virtual void Execute(Cell*) = 0;
        virtual void Exit(Cell*) = 0;
        virtual ~State(){};
}//end class


#endif
