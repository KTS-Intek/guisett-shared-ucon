#include "matildadevicetree.h"

#include "moji_defy.h"

//---------------------------------------------------------------------

MatildaDeviceTree::MatildaDeviceTree(QObject *parent) : QObject(parent)
{

}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::simplePagesList()
{
    QStringList l;
    l.append( QString("About object") );
    l.append( QString("Date and time") );
    l.append( QString("State") );
    l.append( QString("Quick Direct Access") );

    l.append( QString("Statistic of exchange") );
    l.append( QString("System") );

    l.append( QString("Serial log") );

    l.append( QString("Direct access service") );
    l.append( QString("Direct access client") );
    l.append( QString("M2M client") );

    l.append( QString("Poll") );
    l.append( QString("Forwarding table"));
    l.append( QString("Schedule") );
    l.append( QString("Meters") );
    l.append( QString("Database") );
    l.append( QString("Meter logs") );
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::listPath2icon()
{
    QStringList l ;
    l.append( ":/katynko/svg2/exinfo.svg");
    l.append( ":/katynko/svg2/kt-bandwidth-scheduler.svg");
    l.append( ":/katynko/svg2/view-readermode-active.svg" );
    l.append( ":/katynko/svg2/zoom-in-2.svg");

    l.append( ":/katynko/svg/view-statistics.svg");
    l.append( ":/katynko/svg2/lc_extendedhelp.svg");

    l.append( ":/katynko/svg2/network-disconnect.svg" );

    l.append( ":/katynko/svg2/view-readermode.svg" );

    l.append( ":/katynko/svg/address-book-new.svg" );

    l.append( ":/katynko/svg2/view-readermode-gr.svg" );

    l.append( ":/katynko/svg2/view-readermode-gr2.svg" );
    l.append( ":/katynko/svg2/call-start.svg");
    l.append( ":/katynko/svg2/network-wired.svg");
    l.append( ":/katynko/svg2/network-wireless.svg" );
    l.append( ":/katynko/svg2/journal-new.svg" );

    l.append( ":/katynko/svg2/refinp2.svg");

    l.append( ":/katynko/svg/view-list-text.svg");

    l.append( ":/katynko/svg2/view-readermode-red2.svg" );
    l.append( ":/katynko/svg2/view-readermode-yel2.svg" );

    l.append( ":/katynko/svg2/utilities-terminal.svg");

    l.append( ":/katynko/svg2/zoom-in-2.svg");
    l.append( ":/katynko/svg2/zoom-in.svg" );

    l.append( ":/katynko/svg2/view-web-browser-dom-tree.svg" );

    l.append( ":/katynko/svg2/im30821.svg" );

    l.append( ":/katynko/svg2/configure.svg" );

    l.append( ":/katynko/svg2/homerun.svg" );

    l.append( ":/katynko/svg/document-save.svg");

    l.append( ":/katynko/svg2/kt-queue-manager.svg");
    l.append( ":/katynko/svg/table.svg");
    l.append( ":/katynko/svg2/dashboard-show.svg");
    l.append( ":/katynko/svg/format-justify-fill.svg" );
    l.append( ":/katynko/svg2/db.svg" );
    l.append( ":/katynko/svg2/lc_dbqueryedit.svg");

    l.append( ":/katynko/svg2/lc_dbtableedit.svg" );


    //protocol v2
    l.append( ":/katynko/svg/xy-curve.svg" );//ip route
    l.append( ":/katynko/svg3/dog.svg" );//ppp supervisor

    ///led lamp
    l.append( ":/katynko/svg/format-justify-fill.svg" );
    l.append( ":/katynko/svg2/dashboard-show.svg" );
    l.append( ":/katynko/svg2/kt-queue-manager.svg");
    l.append( ":/katynko/svg/format-disconnect-node.svg" );
    l.append( ":/katynko/svg3/run-build.svg" );

    l.append( ":/katynko/svg2/view-readermode-gr.svg" );
    l.append( ":/katynko/svg2/view-readermode-red2.svg" );
    l.append( ":/katynko/svg2/view-readermode-yel2.svg" );

    l.append(lOnlySvahaSyncPath2icon());

    l.append(lDevPollProtocolV3Path2icon());
    l.append(lDevPollProtocolV4Path2icon());
    l.append(lDevPollProtocolV5Path2icon());

    for(int i = 0, iMax = l.size(); i < iMax; i++){
        if(l.at(i).left(2) != ":/")
            l.replace(i, ":/katynko/svg2/empty.svg");
    }

    return l;
}

QStringList MatildaDeviceTree::getListPath2iconMain()
{
    QStringList lKeys;
    lKeys.append(":/katynko/svg2/lc_extendedhelp.svg");
    lKeys.append(":/katynko/svg2/im30821.svg");
    lKeys.append(":/katynko/svg2/db.svg");
    lKeys.append(":/katynko/svg2/lc_browseview.svg");
    lKeys.append(":/katynko/svg/applications-system.svg");
    lKeys.append(":/katynko/svg4/sc_formattedfield.svg");
    lKeys.append(":/katynko/svg4/lc_extrusionlightingfloater.svg");
    lKeys.append(":/katynko/svg/network-disconnect.svg");
    lKeys.append(":/katynko/svg3/run-build.svg");
    return lKeys;
}

QStringList MatildaDeviceTree::getListRealMainNames()
{
    QStringList lKeys;
    lKeys.append(tr("Info"));
    lKeys.append(tr("Commands"));
    lKeys.append(tr("Poll data"));
    lKeys.append(tr("Network settings"));
    lKeys.append(tr("General settings"));
    lKeys.append(tr("Prepaid"));
    lKeys.append(tr("Smart lighting"));
    lKeys.append(tr("M2M Service"));
    lKeys.append(tr("Application"));
    return lKeys;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameByDev(const int &devType, const int &protocolVersion)
{
    QStringList l;
    switch(devType){
    case DEV_POLL            : l = realPageNameDevPoll(protocolVersion) ; break;
    case DEV_STOR            : l = realPageNameDevStor() ; break;
    case DEV_GATE            : l = realPageNameDevGate() ; break;
    case DEV_SVAHA           : l = realPageNameDevSvaha(); break;

    case DEV_POLL_4_STAFF   : l = realPageNameDevPoll4staff(); break;

    case DEV_POLL_EMULATOR_L0: l = realPageNameDevEmul0(); break;
    case DEV_POLL_EMULATOR_L1: l = realPageNameDevEmul1(); break;
    case DEV_POLL_EMULATOR_L2: l = realPageNameDevEmul2(); break;

    case DEV_POLL_EMULATOR_L3: l = realPageNameDevEmul3(); break;

    default: l = realPageName(); break;
    }
    return l;
}

//---------------------------------------------------------------------

MatildaDeviceTree::MatildaDevTreeView MatildaDeviceTree::pageName4devTree()
{
    //items must be with real name? root item: tr
    QHash<QString, QStringList> h;
    QStringList lKeys;

    QMap<QString, QString> hashRealName2ico = getHashRealName2ico();


    addChapter(QString("About object"), QStringList(), lKeys, h);
    addChapter(QString("Date and time"), QStringList(), lKeys, h);
    addChapter(QString("State"), QStringList(), lKeys, h);
    addChapter(QString("Quick Direct Access"), QStringList(), lKeys, h);


    /*
     *
     *  lKeys.append();
    lKeys.append(":/katynko/svg2/im30821.svg");
    lKeys.append();
    lKeys.append(":/katynko/svg2/lc_browseview.svg");
    lKeys.append(":/katynko/svg/applications-system.svg");
    lKeys.append(":/katynko/svg4/sc_formattedfield.svg");
    lKeys.append(":/katynko/svg4/lc_extrusionlightingfloater.svg");
    lKeys.append(":/katynko/svg/network-disconnect.svg");
    lKeys.append();
    return lKeys;

*/

    addChapter(QString("Info"), infoNames(), lKeys, h, hashRealName2ico, ":/katynko/svg2/lc_extendedhelp.svg");

    addChapter(QString("Poll data"), pollDataNames(), lKeys, h, hashRealName2ico, ":/katynko/svg2/db.svg");
    addChapter(QString("Prepaid"), prepaidNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/sc_formattedfield.svg");

    addChapter(QString("Electricity meter"), electricNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/sc_symbolshapes.lightning.svg");
    addChapter(QString("Water meters"), waterNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/lc_fillcolor.svg");

    addChapter(QString("Smart lighting"), smartLightNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/lc_extrusionlightingfloater.svg");

    addChapter(QString("Commands"), commandNames(), lKeys, h, hashRealName2ico, ":/katynko/svg2/im30821.svg");


    addChapter(QString("Network settings"), networkSettNames(), lKeys, h, hashRealName2ico, ":/katynko/svg2/lc_browseview.svg");

    addChapter(QString("General settings"), generalSettNames(), lKeys, h, hashRealName2ico, ":/katynko/svg/applications-system.svg");

    addChapter(QString("M2M Service"), m2mNames(), lKeys, h, hashRealName2ico, ":/katynko/svg/network-disconnect.svg");

    addChapter(QString("Application"), appNames(), lKeys, h, hashRealName2ico, ":/katynko/svg3/run-build.svg");


//    h.insert("\r\nlKeys\r\n", lKeys);
    return MatildaDevTreeView(h, hashRealName2ico, lKeys);
}

//---------------------------------------------------------------------

void MatildaDeviceTree::addChapter(const QString &key, const QStringList &names, QStringList &lKeys, QHash<QString, QStringList> &h)
{
    QMap<QString, QString> hs;
    addChapter(key, names, lKeys, h, hs, "hs");
}

void MatildaDeviceTree::addChapter(const QString &key, const QStringList &names, QStringList &lKeys, QHash<QString, QStringList> &h, QMap<QString, QString> &hashRealName2ico, const QString &icon)
{
    lKeys.append(key);
    h.insert(key, names);
    hashRealName2ico.insert(key, icon);
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::infoNames()
{
    QStringList l;
    //    l.append( QString("State")                   );
    l.append( QString("System") );
    l.append( QString("Network interfaces") );
    l.append( QString("Running process") );

    l.append( QString("Application events") );
    l.append( QString("Statistic of exchange")   );
    l.append( QString("Meter plugin") );
    l.append( QString("Poll events") );
    l.append( QString("Poll error events") );
    l.append( QString("Poll warning events") );
    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );

    //protocol v4
    l.append(QString("OpenVPN state"));

    //protocol v5
    l.append( QString("Poll tasks"));

    return l;

}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::commandNames()
{
    QStringList l;

    l.append( QString("Simple BASH"));
    l.append( QString("Commands") );

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::pollDataNames()
{
    QStringList l;
    l.append( QString("Database") );
    l.append( QString("Meter logs") );
    l.append( QString("Hash summ" ) );
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::networkSettNames()
{
    QStringList l;
    l.append( QString("GSM/PPP") );
    l.append( QString("TCP settings") );
    l.append( QString("ZigBee") );
    l.append( QString("Direct access service") );
    l.append( QString("Direct access client") );
    l.append( QString("M2M client") );
    l.append( QString("Accessibility") );

    //protocol v2
    l.append( QString("IP Route"));//v2
    l.append( QString("PPP supervisor"));//v2

    //protocol v4
    l.append(QString("Ethernet"));
    l.append(QString("OpenVPN profiles"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::generalSettNames()
{
    QStringList l;

    l.append( QString("Authorization") );
    l.append(QString("Staff accounts"));//protocol v5

    l.append( QString("Poll") );
    l.append( QString("Forwarding table"));
    l.append( QString("ZbyratorTaskTable") );

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::electricNames()
{
    QStringList l;
    l.append( QString("Meters") );
    l.append( QString("Schedule") );
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::waterNames()
{
    QStringList l;

    l.append(QString("WaterMeters"));//Water meters
    l.append(QString("Last active profile"));
    l.append(QString("WaterSchedule"));//Water schedule
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::prepaidNames()
{
    QStringList l;

 l.append( QString("Report") );
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::smartLightNames()
{
    QStringList l;

    l.append( QString("Lamps") );
    l.append( QString("Schedule for groups") );
    l.append( QString("Temporary schedule") );

    l.append( QString("Tasks") );
    l.append( QString("Relay") );
    l.append( QString("Mode") );

    l.append( QString("General events") );
    l.append( QString("Error events") );
    l.append( QString("Warning events") );
    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::m2mNames()
{
    QStringList l;

    ///svaha-service
    l.append(QString("Connection Settings"));
    l.append(QString("Backup Settings"));
    l.append(QString("Show Connections"));
    l.append(QString("Show Backups"));
    l.append(QString("SNTP Settings"));
    l.append(QString("SNTP IP history"));
    l.append(QString("SNTP Events"));
    l.append(QString("SNTP Error Log"));
    l.append(QString("SNTP Warning Log"));
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::appNames()
{
    QStringList l;
    l.append( QString("Packet manager") );
       l.append( QString("Backup") );

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevPoll(const int &protocolVersion)
{
    QStringList ls = lOnlySvahaSyncRealNames();
    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V3)
        ls.append(lDevPollProtocolV3RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V4)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV4RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V5)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV5RealNames());

    QStringList l = realPageName();
    while(!ls.isEmpty())
        l.removeOne(ls.takeFirst());
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevStor()
{
    QStringList l ;
    l.append( QString("About object")            );
    l.append( QString("Date and time")           );
    l.append( QString("State")                   );

    l.append( QString("System") );
    l.append( QString("Network interfaces") );
    l.append( QString("Running process") );

    l.append( QString("Application events") );
    l.append( QString("GSM/PPP") );
    l.append( QString("TCP settings") );

    l.append( QString("Simple BASH"));
    l.append( QString("M2M client") );

    l.append( QString("Commands") );
    l.append( QString("Authorization") );

    l.append( QString("Accessibility") );
    l.append( QString("Backup") );

    l.append( QString("Database") );
    l.append( QString("Meter logs") );
    l.append( QString("Hash summ" ) );

    //protocol v2
    l.append( QString("IP Route"));//v2
    l.append( QString("PPP supervisor"));//v2

    //protocol v4
    l.append(QString("Ethernet"));
    l.append(QString("OpenVPN profiles"));
    l.append(QString("OpenVPN state"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevPoll4staff()
{
    QStringList l ;
    l.append( QString("About object")            );
//    l.append( QString("Date and time")           );
//    l.append( QString("State")                   );

    l.append( QString("Statistic of exchange")   );
    l.append( QString("Poll tasks"));


//    l.append( QString("Application events") );
    l.append( QString("Database") );

    l.append( QString("Meters") );
    l.append( QString("Schedule") );

    l.append(QString("WaterMeters"));//Water meters
    l.append(QString("Last active profile"));
    l.append(QString("WaterSchedule"));//Water schedule

    l.append( QString("Database") );
    l.append( QString("Meter logs") );


    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevGate()
{
    QStringList l ;
    l.append( QString("About object")            );
    l.append( QString("Date and time")           );
    l.append( QString("State")                   );
    l.append( QString("Quick Direct Access") );

    l.append( QString("System") );
    l.append( QString("Network interfaces") );
    l.append( QString("Running process") );
    l.append( QString("Meter plugin") );
    l.append( QString("Application events") );

    l.append( QString("GSM/PPP") );
    l.append( QString("TCP settings") );
    l.append( QString("ZigBee") );
    l.append( QString("Packet manager") );
    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );

    l.append( QString("Simple BASH"));

    l.append( QString("Direct access service") );
    l.append( QString("Direct access client") );
    l.append( QString("M2M client") );

    l.append( QString("Commands") );
    l.append( QString("Authorization") );

    l.append( QString("Accessibility") );
    l.append( QString("Backup") );

    l.append( QString("Forwarding table"));
//    l.append( QString("Hash summ" ) );

    //protocol v2
    l.append( QString("IP Route"));//v2
    l.append( QString("PPP supervisor"));//v2

    //protocol v4
    l.append(QString("Ethernet"));
    l.append(QString("OpenVPN profiles"));
    l.append(QString("OpenVPN state"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevEmul0()
{
    return realPageNameDevEmul2();
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevEmul1()
{
    return realPageNameDevEmul2();
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevEmul2()
{
    QStringList l ;
    l.append( QString("About object")            );
    l.append( QString("Date and time")           );
    l.append( QString("State")                   );
    l.append( QString("Quick Direct Access") );

    l.append( QString("Statistic of exchange")   );
    l.append( QString("System") );
    l.append( QString("Network interfaces") );

    l.append( QString("Meter plugin") );
    l.append( QString("Application events") );
    l.append( QString("Poll events") );

    l.append( QString("TCP settings") );
    l.append( QString("ZigBee") );

    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );
    l.append( QString("Poll error events") );
    l.append( QString("Poll warning events") );


    l.append( QString("Direct access service") );
    l.append( QString("Direct access client") );
    l.append( QString("M2M client") );

    l.append( QString("Commands") );

    l.append( QString("Accessibility") );
    l.append( QString("Backup") );
    l.append( QString("Poll") );
    l.append( QString("Forwarding table"));

    l.append( QString("Meters") );
    l.append( QString("Database") );
    l.append( QString("Meter logs") );
    l.append( QString("Hash summ" ) );
    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::realPageNameDevEmul3()
{
    QStringList l ;

    l.append( QString("Serial log") );

    l.append( QString("Direct access service") );

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevSvaha()
{
    QStringList l ;
    l.append( QString("About object")            );
    l.append( QString("Date and time")           );
    l.append( QString("State")                   );
    l.append( QString("System") );
    l.append( QString("Network interfaces") );
    l.append( QString("Running process") );
    l.append( QString("Application events") );
    l.append( QString("GSM/PPP") );
    l.append( QString("TCP settings") );
    l.append( QString("Packet manager") );

    l.append( QString("Simple BASH"));

    l.append( QString("M2M client") );

    l.append( QString("Commands") );
    l.append( QString("Authorization") );

    l.append( QString("Accessibility") );

    l.append( QString("Backup") );

//size 33

    //protocol v2
    l.append( QString("IP Route"));//v2
    l.append( QString("PPP supervisor"));//v2


    //svaha-sync
    l.append(lOnlySvahaSyncRealNames());
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lOnlySvahaSyncRealNames()
{
    QStringList l;
    //svaha-service
    l.append(QString("Connection Settings"));
    l.append(QString("Backup Settings"));
    l.append(QString("Show Connections"));
    l.append(QString("Show Backups"));

    //sntp-service
    l.append(QString("SNTP Settings"));
    l.append(QString("SNTP IP history"));
    l.append(QString("SNTP Events"));
    l.append(QString("SNTP Error Log"));
    l.append(QString("SNTP Warning Log"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lOnlySvahaSyncLocalNames()
{
    QStringList l;
    //svaha-service
    l.append(tr("Connection Settings"));
    l.append(tr("Backup Settings"));
    l.append(tr("Show Connections"));
    l.append(tr("Show Backups"));

    //sntp-service
    l.append(tr("SNTP Settings"));
    l.append(tr("SNTP IP history"));
    l.append(tr("SNTP Events"));
    l.append(tr("SNTP Error Log"));
    l.append(tr("SNTP Warning Log"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lOnlySvahaSyncPath2icon()
{
    QStringList l;
    //svaha-service
    l.append( ":/katynko/svg/network-disconnect.svg" );
    l.append( ":/katynko/svg2/folder-tar.svg" );
    l.append( ":/katynko/svg/format-justify-fill.svg" );
    l.append( ":/katynko/svg/document-open.svg" );

    //sntp
    l.append( ":/katynko/svg2/kt-bandwidth-scheduler.svg" );
    l.append( ":/katynko/svg2/lc_dbtableedit.svg" );
    l.append( ":/katynko/svg2/view-readermode-gr.svg" );
    l.append( ":/katynko/svg2/view-readermode-redsvg.svg" );
    l.append( ":/katynko/svg2/view-readermode-yel.svg" );
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV3RealNames()
{
    QStringList l;
    l.append(QString("Report"));
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV3LocalNames()
{
    QStringList l;
    l.append(tr("Report"));
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV3Path2icon()
{
    QStringList l;
    l.append( ":/katynko/svg2/lc_dbtableedit.svg" );
    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::lDevPollProtocolV4RealNames()
{
    QStringList l;
    l.append(QString("Ethernet"));
    l.append(QString("OpenVPN profiles"));
    l.append(QString("OpenVPN state"));
    l.append(QString("Temporary schedule"));
    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::lDevPollProtocolV4LocalNames()
{
    QStringList l;
    l.append(tr("Ethernet"));
    l.append(tr("OpenVPN profiles"));
    l.append(tr("OpenVPN state"));
    l.append(tr("Temporary schedule"));
    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::lDevPollProtocolV4Path2icon()
{
    QStringList l;
    l.append( ":/katynko/svg/network-connect.svg" );
    l.append( ":/katynko/svg/document-edit-sign-encrypt.svg" );
    l.append( ":/katynko/svg/document-edit-sign-encrypt.svg" );
    l.append( ":/katynko/svg4/dashboard-red.svg" );

    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::lDevPollProtocolV5RealNames()
{
    QStringList l;
    l.append(QString("Poll tasks"));
    l.append(QString("WaterMeters"));//Water meters
    l.append(QString("Last active profile"));
    l.append(QString("Staff accounts"));
    l.append(QString("WaterSchedule"));//Water schedule
    l.append(QString("ZbyratorTaskTable"));


    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::lDevPollProtocolV5LocalNames()
{
    QStringList l;
    l.append(tr("Poll tasks"));//Poll tasks
    l.append(tr("Meters"));//Water
    l.append(tr("Last active profile"));
    l.append(tr("Staff accounts"));
    l.append(tr("Schedule"));//Water
    l.append(tr("Poll task table"));

    return l;
}
//---------------------------------------------------------------------
QStringList MatildaDeviceTree::lDevPollProtocolV5Path2icon()
{
    QStringList l;

    l.append( ":/katynko/svg2/kt-queue-manager.svg");
    l.append( ":/katynko/svg/format-justify-fill.svg");
    l.append( ":/katynko/svg2/kt-bandwidth-scheduler.svg");
    l.append( ":/katynko/svg/im-user-offline.svg");
    l.append( ":/katynko/svg2/dashboard-show.svg");
    l.append( ":/katynko/svg2/kt-bandwidth-scheduler.svg");

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageName()
{
    QStringList l ;


    l.append( QString("About object")            );
    l.append( QString("Date and time")           );
    l.append( QString("State")                   );
    l.append( QString("Quick Direct Access") );

    l.append( QString("Statistic of exchange")   );
    l.append( QString("System") );
    l.append( QString("Network interfaces") );
    l.append( QString("Running process") );
    l.append( QString("Meter plugin") );
    l.append( QString("Application events") );
    l.append( QString("Poll events") );
    l.append( QString("GSM/PPP") );
    l.append( QString("TCP settings") );
    l.append( QString("ZigBee") );
    l.append( QString("Packet manager") );
    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );
    l.append( QString("Poll error events") );
    l.append( QString("Poll warning events") );

    l.append( QString("Simple BASH"));

    l.append( QString("Direct access service") );
    l.append( QString("Direct access client") );
    l.append( QString("M2M client") );

    l.append( QString("Commands") );
    l.append( QString("Authorization") );

    l.append( QString("Accessibility") );

    l.append( QString("Backup") );
    l.append( QString("Poll") );
    l.append( QString("Forwarding table"));
    l.append( QString("Schedule") );
    l.append( QString("Meters") );
    l.append( QString("Database") );
    l.append( QString("Meter logs") );
    l.append( QString("Hash summ" ) );
//size 34

    //protocol v2
    l.append( QString("IP Route"));//v2
    l.append( QString("PPP supervisor"));//v2

    ///led lamp
    l.append( QString("Lamps") );
    l.append( QString("Schedule for groups") );

    l.append( QString("Tasks") );
    l.append( QString("Relay") );
    l.append( QString("Mode") );

    l.append( QString("General events") );
    l.append( QString("Error events") );
    l.append( QString("Warning events") );

    //svaha-sync
    l.append(lOnlySvahaSyncRealNames());

    l.append(lDevPollProtocolV3RealNames());
    l.append(lDevPollProtocolV4RealNames());
    l.append(lDevPollProtocolV5RealNames());

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::localPageName()
{
    QStringList l ;



    l.append( tr("About object") );
    l.append( tr("Date and time") );
    l.append( tr("State") );
    l.append( tr("Quick Direct Access") );

    l.append( tr("Statistic of exchange") );
    l.append( tr("System") );
    l.append( tr("Network interfaces") );
    l.append( tr("Running processes") );
    l.append( tr("Plugins for meters") );
    l.append( tr("Application events") );
    l.append( tr("Poll events") );
    l.append( tr("GSM/PPP") );
    l.append( tr("TCP settings") );
    l.append( tr("ZigBee") );
    l.append( tr("Packet manager") );
    l.append( tr("Stream from the serial port")); //tr("Serial log stream") );
    l.append( tr("UART log") );
    l.append( tr("Poll errors") );
    l.append( tr("Poll warnings") );

    l.append( tr("Simple BASH"));

    l.append( tr("Direct access service") );
    l.append( tr("Direct access client") );
    l.append( tr("M2M client") );

    l.append( tr("Commands") );
    l.append( tr("Authorization") );

    l.append( tr("Accessibility") );

    l.append( tr("Backup") );
    l.append( tr("Poll") );
    l.append( tr("Forwarding table"));
    l.append( tr("Schedule") );
    l.append( tr("Meters") );
    l.append( tr("Database") );
    l.append( tr("Logs of meters") );
    l.append( tr("Hash summ" ) );

    //protocol v2
    l.append( tr("IP Route"));//v2
    l.append( tr("PPP supervisor"));//v2

    ///led lamp
    l.append( tr("Lights") );
    l.append( tr("Schedule for groups") );

    l.append( tr("Tasks") );
    l.append( tr("Relay") );
    l.append( tr("Mode") );

    l.append( tr("Events") );
    l.append( tr("Errors") );
    l.append( tr("Warnings") );

    l.append(lOnlySvahaSyncLocalNames());

    l.append(lDevPollProtocolV3LocalNames());
    l.append(lDevPollProtocolV4LocalNames());
    l.append(lDevPollProtocolV5LocalNames());

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realChapterName()
{
    QStringList l ;

    //chapters

    l.append( QString("Info"));
    l.append( QString("Poll data"));
    l.append( QString("Prepaid"));
    l.append( QString("Electricity meter"));
    l.append( QString("Water meters"));
    l.append( QString("Smart lighting"));

    l.append( QString("Network settings"));
    l.append( QString("General settings"));
    l.append( QString("M2M Service"));
    l.append( QString("Application"));
    //chapters
    return l;

}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::localChapterName()
{
    QStringList l ;

    //chapters

    l.append( tr("Info"));
    l.append( tr("Poll data"));
    l.append( tr("Prepaid"));
    l.append( tr("Electricity meter"));
    l.append( tr("Water meters"));
    l.append( tr("Smart lighting"));

    l.append( tr("Network settings"));
    l.append( tr("General settings"));
    l.append( tr("M2M Service"));
    l.append( tr("Application"));
    //chapters
    return l;
}

//---------------------------------------------------------------------

QHash<QString, QString> MatildaDeviceTree::hashRealName2localName()
{
    const QStringList lr = realPageName() + realChapterName();
    const QStringList ll = localPageName() + localChapterName();
    QHash<QString,QString> h;
    for(int i = 0, iMax = lr.size(), iMax2 = ll.size(); i < iMax && i < iMax2; i++)
        h.insert(lr.at(i), ll.at(i));
    return h;
}

//---------------------------------------------------------------------

QHash<QString, QString> MatildaDeviceTree::hashLocalName2realName()
{
    const QStringList lr = realPageName() + realChapterName();
    const QStringList ll = localPageName() + localChapterName();
    QHash<QString,QString> h;
    for(int i = 0, iMax = lr.size(), iMax2 = ll.size(); i < iMax && i < iMax2; i++)
        h.insert(ll.at(i), lr.at(i));




    return h;
}
//---------------------------------------------------------------------
QMap<QString, QString> MatildaDeviceTree::getHashRealName2ico()
{
    QMap<QString, QString> hashRealName2ico;

    const QStringList lPath2icon = listPath2icon();
    const QStringList listRealName = realPageName();
    for(int i = 0, iMax = lPath2icon.size(), iMax2 = listRealName.size(); i < iMax && i < iMax2; i++ )
        hashRealName2ico.insert(listRealName.at(i), lPath2icon.at(i));


//    if(allIcons){
//        const QStringList lPath2icon = getListPath2iconMain();
//        const QStringList listRealName = getListRealMainNames();
//        for(int i = 0, iMax = lPath2icon.size(), iMax2 = listRealName.size(); i < iMax && i < iMax2; i++ )
//            hashRealName2ico.insert(listRealName.at(i), lPath2icon.at(i));
//    }
    return hashRealName2ico;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWrite()
{
    QList<int> listInt;
    listInt.append( COMMAND_WRITE_ABOUT_OBJECT );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( COMMAND_WRITE_GPRS_SETT );
    listInt.append( COMMAND_WRITE_TCP_SETT   );
    listInt.append( COMMAND_WRITE_ZIGBEE_SETT );
    listInt.append( COMMAND_WRITE_UPGRADE );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( COMMAND_WRITE_DA_SERVICE_SETT );
    listInt.append( COMMAND_WRITE_PEREDAVATOR_AC_SETT );
    listInt.append( COMMAND_WRITE_MATILDA_AC_SETT );

    listInt.append( 0 );
    listInt.append( 0 );

    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( COMMAND_WRITE_POLL_SETT );
    listInt.append( COMMAND_WRITE_FRWRD_SETT);
    listInt.append( COMMAND_WRITE_POLL_SCHEDULE );
    listInt.append( COMMAND_WRITE_METER_LIST_FRAMED );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );

    //protocol v2
    listInt.append( COMMAND_WRITE_IPTABLE );
    listInt.append( COMMAND_WRITE_PPP_SUPERVISOR);

    ///led lamp
    listInt.append( COMMAND_WRITE_LEDLAMPLIST_FRAMED);
    listInt.append( COMMAND_WRITE_GROUP_SCHEDULE);
    listInt.append( 0 );
    listInt.append( COMMAND_WRITE_POWER_RELAY_SETT);
    listInt.append( COMMAND_WRITE_FIREFLY_MODE_SETT);
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( 0 );

    listInt.append(getPageCanWriteSvahaOnly());
    listInt.append(getPageCanWriteDevPollProtocolV3());
    listInt.append(getPageCanWriteDevPollProtocolV4());
    listInt.append(getPageCanWriteDevPollProtocolV5());

    return listInt;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanRead()
{
    QList<int> listInt;
    listInt.append( COMMAND_READ_ABOUT_OBJECT );
    listInt.append( COMMAND_READ_DATE_SETT );
    listInt.append( COMMAND_READ_STATE );
    listInt.append( 0 );

    listInt.append( COMMAND_READ_POLL_STATISTIC );
    listInt.append( COMMAND_READ_SYSTEM_SETTINGS );
    listInt.append( COMMAND_READ_IFCONFIG );
    listInt.append( COMMAND_READ_TASK_INFO );
    listInt.append( COMMAND_READ_ABOUT_PLG );
    listInt.append( COMMAND_READ_APP_LOG );
    listInt.append( COMMAND_READ_ZBR_LOG );
    listInt.append( COMMAND_READ_GPRS_SETT );
    listInt.append( COMMAND_READ_TCP_SETT );
    listInt.append( COMMAND_READ_ZIGBEE_SETT   );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( COMMAND_READ_SERIAL_LOG );
    listInt.append( COMMAND_READ_PLUGIN_LOG_ERROR );
    listInt.append( COMMAND_READ_PLUGIN_LOG_WARN );
    listInt.append( 0 );

    listInt.append( COMMAND_READ_DA_SERVICE_SETT );
    listInt.append( COMMAND_READ_PEREDAVATOR_AC_SETT );
    listInt.append( COMMAND_READ_MATILDA_AC_SETT );

    listInt.append( 0  );
    listInt.append( 0  );

    listInt.append( 0  );
    listInt.append( COMMAND_READ_BACKUP_LIST );
    listInt.append( COMMAND_READ_POLL_SETT );
    listInt.append( COMMAND_READ_FRWRD_SETT);
    listInt.append( COMMAND_READ_POLL_SCHEDULE );
    listInt.append( COMMAND_READ_METER_LIST_FRAMED );
    listInt.append( COMMAND_READ_DATABASE );
    listInt.append( COMMAND_READ_METER_LOGS );
    listInt.append( COMMAND_READ_TABLE_HASH_SUMM );

    //protocol v2
    listInt.append( COMMAND_READ_IPTABLE);
    listInt.append( COMMAND_READ_PPP_SUPERVISOR);
    ///led lamp
    listInt.append( COMMAND_READ_LEDLAMPLIST_FRAMED);
    listInt.append( COMMAND_READ_GROUP_SCHEDULE);
    listInt.append( COMMAND_READ_FF_TASK_TABLE_FRAMED );
    listInt.append( COMMAND_READ_POWER_RELAY_SETT);
    listInt.append( COMMAND_READ_FIREFLY_MODE_SETT);
    listInt.append( COMMAND_READ_FIREFLY_LOG_EVENT);
    listInt.append( COMMAND_READ_FIREFLY_LOG_ERROR);
    listInt.append( COMMAND_READ_FIREFLY_LOG_WARN);

    listInt.append(getPageCanReadSvahaOnly());
    listInt.append(getPageCanReadDevPollProtocolV3());
    listInt.append(getPageCanReadDevPollProtocolV4());
    listInt.append(getPageCanReadDevPollProtocolV5());

    return listInt;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWriteSvahaOnly()
{
    QList<int> l;
    //svaha-sync
    l << COMMAND_WRITE_SVAHA_CONN_SETT << COMMAND_WRITE_SVAHA_BACKUP_SETT << 0 << 0;

    //ntp-service
    l << COMMAND_WRITE_SNTP_SETT << 0 << 0 << 0 << 0;
    return l;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadSvahaOnly()
{
    QList<int> l;
    //svaha-service
    l << COMMAND_READ_SVAHA_CONN_SETT << COMMAND_READ_SVAHA_BACKUP_SETT << COMMAND_READ_CONNECT_LIST << COMMAND_READ_BACKUPLIST_FRAMED;
    //ntp-service
    l << COMMAND_READ_SNTP_SETT << COMMAND_READ_SNTP_IP_HISTORY << COMMAND_READ_SNTP_LOG_EV << COMMAND_READ_SNTP_LOG_ERR << COMMAND_READ_SNTP_LOG_WARN ;
    return l;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV3()
{    
    return QList<int>() << 0;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV3()
{    
    return QList<int>() << COMMAND_READ_DATABASE_PREPAID;
}
//---------------------------------------------------------------------
QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV4()
{    
    return QList<int>() << COMMAND_WRITE_STATIC_IP_ETH0 << 0 << 0 << COMMAND_WRITE_TEMP_LED_SHCEDULE;
}
//---------------------------------------------------------------------
QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV4()
{
    return QList<int>() << COMMAND_READ_STATIC_IP_ETH0 << COMMAND_READ_OVPN_CERTS << COMMAND_READ_VPN_STATE << COMMAND_READ_TEMP_LED_SHCEDULE ;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV5()
{
     return QList<int>() << 0 << COMMAND_WRITE_WMETER_LIST_FRAMED << COMMAND_WRITE_WMETER_LAST_PROFILES << COMMAND_SET_STAFFUSERS << COMMAND_WRITE_WMETER_POLL_SCHEDULE
                         << COMMAND_WRITE_ZBYRTASK_TABLE_SETT;

//     l.append(tr("Poll tasks"));//Poll tasks
//     l.append(tr("Water meters"));
//     l.append(tr("Last active profile"));
//     l.append(tr("Staff accounts"));
//     l.append(tr("Water schedule"));
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV5()
{
    return QList<int>() << COMMAND_READ_ZBYRATOR_TASKS << COMMAND_READ_WMETER_LIST_FRAMED << COMMAND_READ_WMETER_LAST_PROFILES << COMMAND_GET_STAFFUSERS << COMMAND_READ_WMETER_POLL_SCHEDULE
                        << COMMAND_READ_ZBYRTASK_TABLE_SETT;


}

//---------------------------------------------------------------------