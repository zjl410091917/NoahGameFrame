#ifndef NFC_SCHEDULE_MODULE_H
#define NFC_SCHEDULE_MODULE_H

#include "NFComm/NFCore/NFMap.h"
#include "NFComm/NFCore/NFList.h"
#include "NFComm/NFCore/NFIDataList.h"
#include "NFComm/NFPluginModule/NFIScheduleModule.h"

class  NFCScheduleElement
	: public NFList<OBJECT_SCHEDULE_FUNCTOR_PTR>
{
public:
	NFCScheduleElement()
	{
		mstrScheduleName = "";
		mfIntervalTime = 0.0f;
		mnNextTriggerTime = 0;
		mnStartTime = 0;
		mnRemainCount = 0;
		mnAllCount = 0;
	};

	virtual ~NFCScheduleElement()
	{
	}

	void DoHeartBeatEvent();

	std::string mstrScheduleName;
	float mfIntervalTime;
	NFINT64 mnNextTriggerTime;
	NFINT64 mnStartTime;
	int mnRemainCount;
	int mnAllCount;

	NFGUID self;
};

class NFCScheduleModule : public NFIScheduleModule
{
public:
	NFCScheduleModule(NFIPluginManager* p);

	virtual ~NFCScheduleModule();

	virtual bool Init();
	virtual bool Execute();

	virtual bool AddSchedule(const std::string& strScheduleName, const MODULE_SCHEDULE_FUNCTOR_PTR& cb, const float fTime, const int nCount);
	virtual bool RemoveSchedule(const std::string& strScheduleName);
	virtual bool ExistSchedule(const std::string& strScheduleName);

	virtual bool AddSchedule(const NFGUID self, const std::string& strScheduleName, const OBJECT_SCHEDULE_FUNCTOR_PTR& cb, const float fTime, const int nCount);
	virtual bool RemoveSchedule(const NFGUID self);
	virtual bool RemoveSchedule(const NFGUID self, const std::string& strScheduleName);
	virtual bool ExistSchedule(const NFGUID self, const std::string& strScheduleName);

protected:
	NFMapEx<NFGUID, NFMapEx <std::string, NFCScheduleElement >> mObjectScheduleMap;//guid_scheduleName_element
	std::list<NFCScheduleElement> mObjectAddList;
	std::map<NFGUID, std::string> mObjectRemoveList;
	
};

#endif