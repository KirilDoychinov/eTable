#include "DataFactory.h" 
#include "Number.h" 
#include "String.h"
#include "DataUtils.h"

Data* DataFactory::createData(std::string str) {
	DataUtils::trim(str);

	Data* d = nullptr;
	if (str.empty())
		d = new String("");

	else if (str.size() > 1 && str.front() == '"' && str.back() == '"')
		d = new String(str);

	else if (DataUtils::isNum(str))
		d = new Number(str);

	else if (DataUtils::isFormula(str)) {


	}

	return d;
}
