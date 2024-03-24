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

	// LinkedList of StaxAppData
	using LinkedList = LinkedList<std::shared_ptr<StaxAppData>>;

	std::string toString() const;	
};

//std::ostream& operator<< (std::ostream& stream, const StaxAppData& appData);
//std::ostream& operator<< (std::ostream& stream, const std::shared_ptr<StaxAppData>& pAppData);
