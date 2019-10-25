#ifndef IOBjECT_H
#define IOBjECT_H
#include <iostream>
#include <string>

struct IObject {
public:
	virtual ~IObject();
	virtual std::string toString() const = 0;
};
#endif // !IOBjECT_H
