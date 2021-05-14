#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

class Input
{
private:
    int reference;
    String alias;

public:
    Input(int reference, String alias);
    int getReference();
    String getAlias();
    void serialPrint();
};

#endif
