#include <map>

using std::map;

template<class ToolType, class Base, class ... Args> class Factory
{
private:
	typedef Base* (*Creator)(Args ...);
	template<class Derived> static Base* creator(Args ... args) {
		return new Derived(args ...);
	}
	map<ToolType, Creator> _factoryMap;

public:
	Factory() = default;
	template<class Derived> void add(ToolType id) {
		_factoryMap[id]=&creator<Derived>;
	}
	Creator get(ToolType id) {
		return _factoryMap[id];
	}
};
