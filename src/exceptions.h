#ifndef _HELLOSDL_EXCEPTION__
#define _HELLOSDL_EXCEPTION__

#include <exception>
using namespace std;

class BaseError: public exception
{
    private:
        static const char* baseReason;

    protected:
        const char* reason;

    public:
        BaseError(const char* reason = "");
        virtual const char* what() const throw();
};

class TileTintError: public BaseError
{
    private:
        static const char* baseReason;

    public:
        TileTintError(const char* reason = "");
};


#endif
