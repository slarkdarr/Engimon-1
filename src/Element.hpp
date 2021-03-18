#ifndef ELEMENTS_H
#define ELEMENTS_H
#include <map>
#include <utility>

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
		Element(ElementType eltype);
		Element();
		void setElement(ElementType eltype);
		ElementType getElement() const;
		bool operator==(const Element& other);
		float getElementAdvantage(const Element& other);
		typedef std::map<std::pair<ElementType,ElementType>, float> ElementAdv;
		static ElementAdv elementAdv;
};
#endif