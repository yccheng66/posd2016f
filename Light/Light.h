#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

class LightState{
    public:
        virtual void flip() {}
        std::string getLightState()const {return state;}
    protected:
        LightState(std::string s="off"):state(s){}
        std::string state;
};
class OffState : public LightState{
    public:
        OffState(){}
        void flip(){
            state = "med";
        }
};

class Light{
public:
    Light(LightState* s=new OffState):state(s){}
    std::string getState()const
    {
        return state->getLightState();
    }
    void flip()
    {
        state->flip();
    }

private:
    LightState* state;
};



#endif // LIGHT_H_INCLUDED
