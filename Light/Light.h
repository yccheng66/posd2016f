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
        static OffState* GetInstance();
        LightState * flip();
        std::string getLightState() const {return "off";}
        virtual ~OffState() {}
    private:
        OffState(){}
};

OffState* OffState::GetInstance(){
    static OffState instance;
    return &instance;
}

class MedState : public LightState{
    public:
        static MedState* GetInstance();
        LightState * flip();
        std::string getLightState() const {return "med";}
        virtual ~MedState() {}
    private:
        MedState(){}
};

MedState* MedState::GetInstance(){
    static MedState instance;
    return &instance;
}

class HighState : public LightState{
    public:
        static HighState* GetInstance();
        LightState * flip();
        std::string getLightState() const {return "high";}
        virtual ~HighState() {}
    private:
        HighState(){}

};

HighState* HighState::GetInstance(){
    static HighState instance;
    return &instance;
}

class Light{
public:
    Light(LightState* s=OffState::GetInstance()):state(s){}
    std::string getState()const
    {
        return state->getLightState();
    }
    void flip()
    {
        //LightState* ls = state;
        state = state->flip();
        //delete ls;
    }

private:
    LightState* state;
};

LightState * OffState :: flip(){
    return MedState::GetInstance();
}

LightState * MedState :: flip(){
    return HighState::GetInstance();
}

LightState * HighState :: flip(){
    return OffState::GetInstance();
}

#endif // LIGHT_H_INCLUDED
