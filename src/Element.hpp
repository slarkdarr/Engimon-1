#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <map>
#include <utility>
#include <string>

using namespace std;
enum ElementType {
	None,
    Fire,
    Water,
    Electric,
    Ground,
    Ice
};

class Element
{
	private:
		ElementType element;
	public:
		typedef std::map<std::pair<ElementType,ElementType>, float> ElementAdv;
		typedef std::map<ElementType, std::string> ElementToString;
		Element(ElementType eltype);
		Element();
		void setElement(ElementType eltype);
		ElementType getElementType() const;
		bool operator==(const Element& other);
		float getElementAdvantage(const Element& other);
		string to_string();
		static ElementAdv elementAdv;
		static ElementToString stringify;
};
#endif