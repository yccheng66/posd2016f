#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED


class LightState{
    public:
        virtual LightState * flip() = 0;
        virtual std::string getLightState() const = 0;
        virtual ~LightState() {}
};
class OffState : public LightState{
    public:
        OffState(){}
        LightState * flip();
        std::string getLightState() const {return "off";}
        virtual ~OffState() {}
};

class MedState : public LightState{
    public:
        MedState(){}
        LightState * flip();
        std::string getLightState() const {return "med";}
        virtual ~MedState() {}
};

class HighState : public LightState{
    public:
        HighState(){}
        LightState * flip();
        std::string getLightState() const {return "high";}
        virtual ~HighState() {}

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
        LightState* ls = state;
        state = state->flip();
        delete ls;
    }

private:
    LightState* state;
};

LightState * OffState :: flip(){
    return new MedState;
}

LightState * MedState :: flip(){
    return new HighState;
}

LightState * HighState :: flip(){
    return new OffState;
}

#endif // LIGHT_H_INCLUDED
