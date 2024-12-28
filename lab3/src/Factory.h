#include <map>

using std::map;
//tooltype - тип инструментов для которых создается фабрика
//base - базовый класс который используется для создания обьектов 
//args - переменное колво аргументов переданных в конструктор создаваемого обьекта

//шаблонный класс factory с tooltype, base и Args
template<class ToolType, class Base, class ... Args> class Factory
{
private:
	//тип Creator - указатель на функцию принимающую n-е колво аргов и возвращающую указатель на обьект базового класса Base
	typedef Base* (*Creator)(Args ...);
	//статический метод creator с n-м колвом аргументов возвращающий указатель на обьект производного класса Derived(можно вызвать без создания экземпляра класса)
	template<class Derived> static Base* creator(Args ... args) {
		//создается новый обтект Derived с переданными аргументами и возвращает указатель на этот обьект
		return new Derived(args ...);
	}
	//словарь отображающий тип инструментов на creator 
	map<ToolType, Creator> _factoryMap;

public:
	//стандартный конструктор
	Factory() = default;
	//метод add добавляющий в _factoryMap новый tooltype на creator для derived(добавляет в _factoryMap новый tooltype и соотвествующий creator)
    template<class Derived>void add(ToolType toolType) {
        _factoryMap[toolType] = &creator<Derived>;
	}
	//метод get возвращающий creator по tooltype из _factoryMap
	Creator get(ToolType id) {
		// return _factoryMap[id];
		return _factoryMap.at(id);
	}
};
