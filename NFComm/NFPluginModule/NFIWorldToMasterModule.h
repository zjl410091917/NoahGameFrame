// -------------------------------------------------------------------------
//    @FileName         ��    NFIWorldNet_ClientModule.h
//    @Author           ��    LvSheng.Huang
//    @Date             ��    2012-12-15
//    @Module           ��    NFIWorldNet_ClientModule
//
// -------------------------------------------------------------------------

#ifndef NFI_WORLDNET_CLIENTMODULE_H
#define NFI_WORLDNET_CLIENTMODULE_H

#include <iostream>
#include "NFIModule.h"
#include "NFINetModule.h"
#include "NFINetClientModule.hpp"

class NFIWorldToMasterModule
	: public  NFIModule
{
public:
	virtual NFINetClientModule* GetNetClientModule() = 0;
};

#endif