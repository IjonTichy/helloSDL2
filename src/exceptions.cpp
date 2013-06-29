#include <string.h>

#include "exceptions.h"

const char* BaseError::baseReason = "error occured";
const char* TileTintError::baseReason = "error occured";

BaseError::BaseError(const char* reason)
{
    if (strlen(reason)) { this->reason = reason; }
    else { this->reason = this->baseReason; }
}

const char* BaseError::what() const throw()
{
    return (const char*)this->reason;
}


TileTintError::TileTintError(const char* reason) : BaseError(reason) {}
