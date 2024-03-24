#pragma once

#include <string>
#include "LinkedList.h"
#include <memory>

/**
    @struct StaxAppData
    @brief  Example application data structure for use with the LinkedList<TValue> class
**/
struct StaxAppData
{
	std::string apiUrl;
	std::string optionsFilename;
	std::string dbConnectionString;
	long userId;

	// linked list of StaxAppData
	using LinkedList = LinkedList<std::shared_ptr<StaxAppData>>;
};
