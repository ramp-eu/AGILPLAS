#include "Input.hpp"

Input::Input(int reference, String alias)
{
    this->reference = reference;
    this->alias = alias;
}
int Input::getReference()
{
    return this->reference;
}
String Input::getAlias()
{
    return this->alias;
}
void Input::serialPrint()
{
    Serial.println(String("Input-> reference: ") + this->getReference() +
                          ", alias: " + this->getAlias());
}
