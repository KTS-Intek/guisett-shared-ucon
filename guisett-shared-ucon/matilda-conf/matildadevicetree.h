#ifndef MATILDADEVICETREE_H
#define MATILDADEVICETREE_H

///[!] guisett-shared
#include "uc-dev/ucdevtreeview.h"

#include <QStringList>
#include <QHash>
#include <QMap>

class MatildaDeviceTree : public UCDevTreeView
{
    Q_OBJECT
public:
    explicit MatildaDeviceTree(QObject *parent = nullptr);





    static QStringList simplePagesList();

    static QStringList listPath2icon();

    static QStringList getListPath2iconMain();

    static QStringList getListRealMainNames();


    static QStringList realPageNameByDev(const int &devType, const int &protocolVersion);//en_GB

    static MatildaDevTreeView pageName4devTree();//en_GB



    static QStringList infoNames();

    static QStringList commandNames();

    static QStringList pollDataNames();

    static QStringList networkSettNames();

    static QStringList generalSettNames();



    static QStringList electricNames();

    static QStringList waterNames();

    static QStringList gasNames();

    static QStringList pulseNames();

    static QStringList modbusNames();

    static QStringList m2mHttpNames();


    static QStringList prepaidNames();

    static QStringList smartLightNames();


    static QStringList m2mNamesAll();

    static QStringList m2mNames();

    static QStringList appNames();

    static QStringList realPageNameDevPoll(const int &protocolVersion);

    static QStringList realPageNameDevStor();

    static QStringList realPageNameDevPoll4staff();


    static QStringList realPageNameDevGate();

    static QStringList realPageNameDevEmul0(const int &protocolVersion);

    static QStringList realPageNameDevEmul1(const int &protocolVersion);

    static QStringList realPageNameDevEmul2(const int &protocolVersion);
    static QStringList realPageNameDevEmul3();

    static QStringList realPageNameDevM2MSrvc(const int &protocolVersion);
    static QStringList realPageNameDevM2MSrvcStaff(const int &protocolVersion);


    static QStringList lOnlyM2MSrvcSyncRealNames();
    static QStringList lOnlyM2MSrvcSyncLocalNames();
    static QStringList lOnlyM2MSrvcSyncPath2icon();

    static QStringList lDevPollProtocolV3RealNames();
    static QStringList lDevPollProtocolV3LocalNames();
    static QStringList lDevPollProtocolV3Path2icon();

    static QStringList lDevPollProtocolV4RealNames();
    static QStringList lDevPollProtocolV4LocalNames();
    static QStringList lDevPollProtocolV4Path2icon();

    static QStringList lDevPollProtocolV5RealNames();
    static QStringList lDevPollProtocolV5LocalNames();
    static QStringList lDevPollProtocolV5Path2icon();

    static QStringList lDevPollProtocolV6RealNames();
    static QStringList lDevPollProtocolV6LocalNames();
    static QStringList lDevPollProtocolV6Path2icon();


    static QStringList lDevPollProtocolV7RealNames();
    static QStringList lDevPollProtocolV7LocalNames();
    static QStringList lDevPollProtocolV7Path2icon();




    static QStringList lDevPollProtocolV8RealNames();
    static QStringList lDevPollProtocolV8LocalNames();
    static QStringList lDevPollProtocolV8Path2icon();


    static QStringList lDevPollProtocolV9RealNames();
    static QStringList lDevPollProtocolV9LocalNames();
    static QStringList lDevPollProtocolV9Path2icon();


    static QStringList lDevPollProtocolV11RealNames();
    static QStringList lDevPollProtocolV11LocalNames();
    static QStringList lDevPollProtocolV11Path2icon();

    static QStringList lDevPollProtocolV12RealNames();
    static QStringList lDevPollProtocolV12LocalNames();
    static QStringList lDevPollProtocolV12Path2icon();


    static QStringList realPageName();//en_GB

    static QStringList localPageName();//local lang


    static QStringList realChapterName();//en_GB

    static QStringList localChapterName();//local lang


    static QHash<QString,QString> hashRealName2localName();

    static QHash<QString,QString> hashLocalName2realName();

    static QMap<QString, QString> getHashRealName2ico();


    static QList<int> getPageCanWrite();
    static QList<int> getPageCanRead();

    static QList<int> getPageCanWriteM2MSrvcOnly();
    static QList<int> getPageCanReadM2MSrvcOnly();

    static QList<int> getPageCanWriteDevPollProtocolV3();
    static QList<int> getPageCanReadDevPollProtocolV3();

    static QList<int> getPageCanWriteDevPollProtocolV4();
    static QList<int> getPageCanReadDevPollProtocolV4();

    static QList<int> getPageCanWriteDevPollProtocolV5();
    static QList<int> getPageCanReadDevPollProtocolV5();



    static QList<int> getPageCanWriteDevPollProtocolV6();
    static QList<int> getPageCanReadDevPollProtocolV6();

    static QList<int> getPageCanWriteDevPollProtocolV7();
    static QList<int> getPageCanReadDevPollProtocolV7();

    static QList<int> getPageCanWriteDevPollProtocolV8();
    static QList<int> getPageCanReadDevPollProtocolV8();


    static QList<int> getPageCanWriteDevPollProtocolV9();
    static QList<int> getPageCanReadDevPollProtocolV9();


};

#endif // MATILDADEVICETREE_H
