#include "StaxAppData.h"

#include <sstream>

std::string StaxAppData::toString() const
{
    std::stringstream ss;

    ss << "{ ";
    ss << apiUrl << ", ";
    ss << optionsFilename << ", ";
    ss << dbConnectionString << ", ";
    ss << userId;
    ss << " }";

    return ss.str();
}

//std::ostream& operator<<(std::ostream& stream, const StaxAppData& appData)
//{
//    stream << appData.toString();
//    return stream;
//}
//
//std::ostream& operator<<(std::ostream& stream, const std::shared_ptr<StaxAppData>& pAppData)
//{
//    stream << pAppData->toString();
//    return stream;
//}
