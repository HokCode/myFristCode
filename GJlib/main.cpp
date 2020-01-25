#include <iostream>
#include "exception.h"
#include "object.h"
#include "Smartpoint.h"
#include "List.h"

using namespace std;
using namespace GJlib;

void Demo()
{
    THROW_EXCEPTION(Exception, "Text")
     //#define THROW_EXCEPTION(e, s)  throw e(s, __FILE__, __LINE__);

}

int main()
{
    try
    {
        Demo();
    }
    catch(const Exception& e)
    {
        cout<< "catch(const Exception& e)" <<endl;
        cout<< e.message() <<endl;
        cout<< e.location() <<endl;
    }

    return 0;
}

