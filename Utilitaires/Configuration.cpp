#include "Configuration.h"
Configuration * Configuration::instance = nullptr;
//----------------------------------------------------------------------------------------------------------------------
Configuration *Configuration::getInstance()
{
    if(instance== 0)
    {
        instance = new Configuration();
    }
    return instance;
}

//----------------------------------------------------------------------------------------------------------------------