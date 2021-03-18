#include "Element.hpp"  
#include <iterator> 
#include <map>
#include <utility> 
#include <iostream>

Element::ElementAdv Element::elementAdv = {
    {std::make_pair(Fire, Fire), 1},
    {std::make_pair(Fire, Water), 0},
    {std::make_pair(Fire, Electric), 1},
    {std::make_pair(Fire, Ground), 0.5},
    {std::make_pair(Fire, Ice), 2},
    {std::make_pair(Water,Fire), 2},
    {std::make_pair(Water, Water), 1},
    {std::make_pair(Water, Electric), 0},
    {std::make_pair(Water, Ground), 1},
    {std::make_pair(Water, Ice), 1},
    {std::make_pair(Electric, Fire), 1},
    {std::make_pair(Electric, Water), 2},
    {std::make_pair(Electric, Electric), 1},
    {std::make_pair(Electric, Ground), 0},
    {std::make_pair(Electric, Ice), 1.5},
    {std::make_pair(Ground, Fire), 1.5},
    {std::make_pair(Ground, Water), 1},
    {std::make_pair(Ground, Electric), 2},
    {std::make_pair(Ground, Ground), 1},
    {std::make_pair(Ground, Ice), 0},
    {std::make_pair(Ice, Fire), 0},
    {std::make_pair(Ice, Water), 1},
    {std::make_pair(Ice, Electric), 0.5},
    {std::make_pair(Ice, Ground), 2},
    {std::make_pair(Ice, Ice), 1}
};

Element::ElementToString Element::stringify = {
	{None, "None"},
    {Fire, "Fire"},
    {Water, "Water"},
    {Electric, "Electric"},
    {Ground, "Ground"},
    {Ice, "Ice"}
};

Element::Element(ElementType eltype) {
    this->element = eltype;
}
Element::Element(){
    this->element = ElementType::None;
}
void Element::setElement(ElementType eltype){
    this->element = eltype;
}
ElementType Element::getElement() const{
    return element;
}

bool Element::operator==(const Element& other){
    if (other.getElement() == this->element) {
        return true;
    }
    return false;
}

string Element::to_string(){
    return stringify[this->element];
}

float Element::getElementAdvantage(const Element& other){
    return elementAdv[std::make_pair(this->element, other.getElement())];
}

