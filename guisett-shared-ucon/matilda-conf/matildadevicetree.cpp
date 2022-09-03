#include "matildadevicetree.h"

#include "moji_defy.h"

//---------------------------------------------------------------------

MatildaDeviceTree::MatildaDeviceTree(QObject *parent) : UCDevTreeView(parent)
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
//    l.append( QString("Meter logs") );
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

    l.append( ":/katynko/svg2/lc_extendedhelp.svg");

    l.append( ":/katynko/svg2/network-disconnect.svg" );

    l.append( ":/katynko/svg2/view-readermode.svg" );


    l.append( ":/katynko/svg2/view-readermode-gr.svg" );

    l.append( ":/katynko/svg2/call-start.svg");
    l.append( ":/katynko/svg2/network-wired.svg");
    l.append( ":/katynko/svg2/network-wireless.svg" );



    l.append( ":/katynko/svg2/journal-new.svg" );

    l.append( ":/katynko/svg2/refinp2.svg");
    l.append( ":/katynko/svg/view-list-text.svg");

    l.append( ":/katynko/svg/address-book-new.svg" );
    l.append( ":/katynko/svg/view-statistics.svg");//Statistic of exchange
    l.append( ":/katynko/svg2/view-readermode-gr2.svg" );


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
    l.append( ":/katynko/svg/format-justify-fill.svg" );
    l.append( ":/katynko/svg2/dashboard-show.svg");
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

    l.append(lDevPollProtocolV6Path2icon());

    l.append(lDevPollProtocolV7Path2icon());

    l.append(lDevPollProtocolV8Path2icon());
    l.append(lDevPollProtocolV9Path2icon());

    l.append(lDevPollProtocolV11Path2icon());

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
    case DEV_SVAHA           : l = realPageNameDevSvaha(protocolVersion); break;

    case DEV_POLL_4_STAFF   : l = realPageNameDevPoll4staff(); break;

    case DEV_POLL_EMULATOR_L0: l = realPageNameDevEmul0(protocolVersion); break;
    case DEV_POLL_EMULATOR_L1: l = realPageNameDevEmul1(protocolVersion); break;
    case DEV_POLL_EMULATOR_L2: l = realPageNameDevEmul2(protocolVersion); break;

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


//    addChapter(QString("General for meters"), generalMetersSettNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/electric-water.svg");
    addChapter(QString("Electricity meter"), electricNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/sc_symbolshapes.lightning.svg");
    addChapter(QString("Water meters"), waterNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/lc_fillcolor.svg");



    addChapter(QString("Smart lighting"), smartLightNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/lc_extrusionlightingfloater.svg");

    addChapter(QString("Commands"), commandNames(), lKeys, h, hashRealName2ico, ":/katynko/svg2/im30821.svg");


    addChapter(QString("Network settings"), networkSettNames(), lKeys, h, hashRealName2ico, ":/katynko/svg2/lc_browseview.svg");

    addChapter(QString("General settings"), generalSettNames(), lKeys, h, hashRealName2ico, ":/katynko/svg/applications-system.svg");

    addChapter(QString("M2M Service"), m2mNamesAll(), lKeys, h, hashRealName2ico, ":/katynko/svg/network-disconnect.svg");

    addChapter(QString("Application"), appNames(), lKeys, h, hashRealName2ico, ":/katynko/svg3/run-build.svg");

    addChapter(QString("Pulse meters"), pulseNames(), lKeys, h, hashRealName2ico, ":/katynko/svg5/dstv_low.svg");
    //    addChapter(QString("Gas meters"), gasNames(), lKeys, h, hashRealName2ico, ":/katynko/svg4/gas-meter.svg");

    addChapter(QString("Modbus"), modbusNames(), lKeys, h, hashRealName2ico, ":/katynko/svg5/modbus-l.svg");


//    h.insert("\r\nlKeys\r\n", lKeys);
    return MatildaDevTreeView(h, hashRealName2ico, lKeys);
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

    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );



/// generalMetersSettNames
    l.append( QString("Statistic of exchange")   );
    l.append( QString("Meter plugin") );
    l.append( QString("Poll events") );
    l.append( QString("Poll error events") );
    l.append( QString("Poll warning events") );

    //protocol v4
    l.append(QString("OpenVPN state"));

    //protocol v5
    l.append( QString("Poll tasks"));


    //protocol v7
    l.append(QString("MeterIfacesLog"));

    //protocol v8
    l.append(QString("GSMCommandsLog"));
    l.append(QString("TCPServerMediumLogs"));
    l.append(QString("TCPZigBeeServiceLog"));
    l.append(QString("TCPZigBeeServiceState"));
    l.append(QString("UCServiceState"));
    l.append(QString("DaAdditionalChannelsLog"));


    //protocol v9
    l.append(QString("DatabaseLogs"));

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
//    l.append( QString("Meter logs") );
//    l.append( QString("Hash summ" ) );//do not show it
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

    //protocol v6
    l.append(QString("UcProxySett"));

    //protocol v7
    l.append(QString("SavedM2MprofilesSett"));

    l.append(QString("IfaceSett4groups"));
    l.append(QString("IfaceSett4channels"));

    //protocol v8
    l.append(QString("TCPMediumServer"));
    l.append(QString("GSMNotifications"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::generalSettNames()
{
    QStringList l;

    l.append( QString("Authorization") );
    l.append(QString("Staff accounts"));//protocol v5


    //older   generalMetersSettNames
    l.append( QString("Poll") );
    l.append( QString("Forwarding table"));
    l.append( QString("ZbyratorTaskTable") );

    //protocol v6
    l.append(QString("DatabaseSumm4ips"));

    //protocol v9
    l.append(QString("DatabaseLimits"));
    return l;


}


//---------------------------------------------------------------------

QStringList MatildaDeviceTree::electricNames()
{
    QStringList l;
    l.append( QString("Meters") );
    l.append( QString("Schedule") );
    //protocol v7
    l.append(QString("ElMeterpollchannels"));
//protocol v8
    l.append(QString("RealViewAdvanced"));
    //protocol v9
    l.append(QString("EnrgMonitors"));
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

QStringList MatildaDeviceTree::gasNames()
{
    QStringList l;

    l.append(QString("GasMeters"));//Gas meters
    l.append(QString("Gas Last active profile"));
    l.append(QString("GasSchedule"));//Gas schedule
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::pulseNames()
{
    QStringList l;

    l.append(QString("PulseMeters"));//Pulse meters
//    l.append(QString("Pulse Last active profile"));
    l.append(QString("PulseSchedule"));//Pulse schedule
    l.append(QString("RealViewAdvancedPMeter"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::modbusNames()
{
    QStringList l;

    l.append(QString("ModbusSerialPortSettings"));
    l.append(QString("ModbusTcpSettings"));
    l.append(QString("ModbusSettings"));
    l.append(QString("ModbusDevicesSettings"));
    l.append(QString("ModbusLogs"));
    l.append(QString("ModbusEvents"));
    l.append(QString("ModbusTcpServiceHistory"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::m2mHttpNames()
{
    QStringList l;
    //m2m service
    l.append(QString("M2MHttpApiks"));
    l.append(QString("M2MHttpGeneral"));
    l.append(QString("M2MHttpEvents"));
    l.append(QString("M2MHttpServiceHistory"));
    l.append(QString("M2MSrvEvents"));

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

    l.append( QString("Tasks") );
    l.append( QString("Relay") );
    l.append( QString("Mode") );

    l.append( QString("General events") );
    l.append( QString("Error events") );
    l.append( QString("Warning events") );
///v4
    l.append( QString("Temporary schedule") );

///protocol v6
    l.append(QString("FireflyTaskTable"));
    l.append(QString("FireflyRescueSchedule"));
    l.append(QString("FireflyNDT"));
    l.append(QString("FireflyScheduleState"));



    return l;
}

QStringList MatildaDeviceTree::m2mNamesAll()
{
    auto l = m2mNames();
    l.append(m2mHttpNames());
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
    ls.append(m2mHttpNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V3)
        ls.append(lDevPollProtocolV3RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V4)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV4RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V5)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV5RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V6)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV6RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V7)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV7RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V8)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV8RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V9)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV9RealNames());

    if(protocolVersion < MATILDA_PROTOCOL_VERSION_V11)//щоб видалити не підтримувані сторінки
        ls.append(lDevPollProtocolV11RealNames());

    QStringList l = realPageName();//беру усі, а потім звідти видаляю ті які не підтримуються
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
//    l.append( QString("Meter logs") );
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
//    l.append( QString("Meter logs") );


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

QStringList MatildaDeviceTree::realPageNameDevEmul0(const int &protocolVersion)
{
    return realPageNameDevEmul2(protocolVersion);
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevEmul1(const int &protocolVersion)
{
    return realPageNameDevEmul2(protocolVersion);
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::realPageNameDevEmul2(const int &protocolVersion)
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
//    l.append( QString("ZigBee") );

    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );
    l.append( QString("Poll error events") );
    l.append( QString("Poll warning events") );


//    l.append( QString("Direct access service") );
    l.append( QString("Direct access client") );
    l.append( QString("M2M client") );

    l.append( QString("Commands") );

    l.append( QString("Accessibility") );
    l.append( QString("Backup") );
    l.append( QString("Poll") );
    l.append( QString("Forwarding table"));

    l.append( QString("Meters") );
    l.append( QString("Database") );
//    l.append( QString("Meter logs") );
//    l.append( QString("Hash summ" ) );

    if(protocolVersion >= MATILDA_PROTOCOL_VERSION_V5){
        l.append(lDevPollProtocolV5RealNames());
        l.removeOne("WaterSchedule");//not supported


        if(protocolVersion >= MATILDA_PROTOCOL_VERSION_V6)
            l.append("DatabaseSumm4ips");

        if(protocolVersion >= MATILDA_PROTOCOL_VERSION_V7)
            l.append(lDevPollProtocolV7RealNames());

        if(protocolVersion >= MATILDA_PROTOCOL_VERSION_V8){



            l.append(QString("TCPZigBeeServiceLog"));
            l.append(QString("UCServiceState"));

            l.append(QString("DaAdditionalChannelsLog"));


        }
    }


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

QStringList MatildaDeviceTree::realPageNameDevSvaha(const int &protocolVersion)
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
    if(protocolVersion >= MATILDA_PROTOCOL_VERSION_V11){
        l.append(m2mHttpNames());
        l.append(QString("SavedM2MprofilesSett")); //v7

        l.append(QString("GSMNotifications")); //v8
        l.append(QString("GSMCommandsLog"));
        l.append(QString("UCServiceState"));

    }
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
    l.append(tr("View tasks of the meters"));//Poll tasks
    l.append(tr("Meters"));//Water
    l.append(tr("Last active profiles"));
    l.append(tr("Staff accounts"));
    l.append(tr("Schedule"));//Water
    l.append(tr("Meter task table settings"));//"ZbyratorTaskTable"

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

QStringList MatildaDeviceTree::lDevPollProtocolV6RealNames()
{
    QStringList l;
    l.append(QString("DatabaseSumm4ips"));

    l.append(QString("FireflyTaskTable"));
    l.append(QString("FireflyRescueSchedule"));
    l.append(QString("FireflyNDT"));
    l.append(QString("FireflyScheduleState"));


    l.append(QString("UcProxySett"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV6LocalNames()
{
    QStringList l;
    l.append(tr("Database IP Rules"));

    l.append(tr("Lamps task table settings"));
    l.append(tr("Rescue schedules"));
    l.append(tr("Search for LCU"));
    l.append(tr("Schedule state"));

    l.append(tr("Proxy settings"));
    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV6Path2icon()
{
    QStringList l;

    l.append( ":/katynko/svg/im-user-offline.svg");
    l.append( ":/katynko/svg2/kt-bandwidth-scheduler.svg");
    l.append( ":/katynko/svg2/exwarning.svg");
    l.append( ":/katynko/svg/irc-voice.svg");

    l.append( ":/katynko/svg4/kt-queue-manager-red.svg");
    l.append( ":/katynko/svg2/view-web-browser-dom-tree.svg");

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV7RealNames()
{
    QStringList l;
    l.append(QString("MeterIfacesLog"));

    l.append(QString("ElMeterpollchannels"));

    l.append(QString("SavedM2MprofilesSett"));
    l.append(QString("IfaceSett4groups"));
    l.append(QString("IfaceSett4channels"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV7LocalNames()
{
    QStringList l;

    //info
    l.append(tr("Meter exchange"));//main and additionals ifaces

    //electricity meter
    l.append(tr("Poll channels"));

    //network
    l.append(tr("Saved M2M profiles"));
    l.append(tr("Group interface settings"));
    l.append(tr("Channel interface settings"));


    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV7Path2icon()
{
    QStringList l;
    l.append( ":/katynko/svg2/sx12452.svg");

    l.append( ":/katynko/svg4/sc_inserthyperlink.svg");

    l.append( ":/katynko/svg4/sc_insertobject.svg");
    l.append( ":/katynko/svg4/sc_ungroup.svg");
    l.append( ":/katynko/svg4/sc_expandpage.svg");

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV8RealNames()
{
    QStringList l;
    l.append(QString("TCPMediumServer"));
    l.append(QString("GSMNotifications"));
    l.append(QString("GSMCommandsLog"));
    l.append(QString("TCPServerMediumLogs"));

    l.append(QString("TCPZigBeeServiceLog"));
    l.append(QString("TCPZigBeeServiceState"));
    l.append(QString("UCServiceState"));

    l.append(QString("DaAdditionalChannelsLog"));
    l.append(QString("RealViewAdvanced"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV8LocalNames()
{
    QStringList l;

    l.append(tr("TCP Medium Server"));//main and additionals ifaces
    l.append(tr("GSM Notifications"));
    l.append(tr("GSM Commands Log"));
    l.append(tr("TCP Server Medium Logs"));


    l.append(tr("TCP/ZigBee Service Log"));
    l.append(tr("TCP/ZigBee Service State"));
    l.append(tr("UC Service State"));

    l.append(tr("Quick Direct access logs"));
    l.append(tr("Real View Advanced"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV8Path2icon()
{
    QStringList l;


    l.append( ":/katynko/svg4/actionview026.svg");
    l.append( ":/katynko/svg/irc-voice.svg");
    l.append( ":/katynko/svg/view-list-text.svg");
    l.append( ":/katynko/svg/format-list-ordered.svg");

    l.append( ":/katynko/svg/view-list-text.svg");
    l.append( ":/katynko/svg/edit-table-insert-row-below.svg");
    l.append( ":/katynko/svg/table.svg");
    l.append( ":/katynko/svg/view-list-text.svg");
    l.append( ":/katynko/svg/format-list-ordered.svg");

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV9RealNames()
{
    QStringList l;
    l.append(QString("EnrgMonitors"));
    l.append(QString("DatabaseLimits"));
    l.append(QString("DatabaseLogs"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV9LocalNames()
{
    QStringList l;
    l.append(tr("Energy monitors"));
    l.append(tr("Database limits"));
    l.append(tr("Database logs"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV9Path2icon()
{
    QStringList l;


    l.append( ":/katynko/svg4/actionview026.svg");
    l.append( ":/katynko/svg4/actionview026.svg");
    l.append( ":/katynko/svg4/actionview026.svg");

    return l;

}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV11RealNames()
{
    QStringList l;


//    l.append(QString("GasMeters"));//Gas meters
//    l.append(QString("Gas Last active profile"));
//    l.append(QString("GasSchedule"));//Gas schedule


    l.append(QString("PulseMeters"));//Pulse meters
//    l.append(QString("Pulse Last active profile"));
    l.append(QString("PulseSchedule"));//Gas schedule

    l.append(QString("RealViewAdvancedPMeter"));


    l.append(QString("ModbusSerialPortSettings"));
    l.append(QString("ModbusTcpSettings"));
    l.append(QString("ModbusSettings"));
    l.append(QString("ModbusDevicesSettings"));
    l.append(QString("ModbusLogs"));
    l.append(QString("ModbusEvents"));
    l.append(QString("ModbusTcpServiceHistory"));


    //m2m service
    l.append(QString("M2MHttpApiks"));
    l.append(QString("M2MHttpGeneral"));
    l.append(QString("M2MHttpEvents"));
    l.append(QString("M2MHttpServiceHistory"));
    l.append(QString("M2MSrvEvents"));

    return l;
}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV11LocalNames()
{
    QStringList l;

//    l.append(tr("Gas Meters"));//Gas meters
//    l.append(tr("Gas Last active profile"));
//    l.append(tr("GasSchedule"));//Gas schedule


    l.append(tr("Pulse meters"));//Pulse meters
//    l.append(tr("Pulse Last active profile"));
    l.append(tr("Pulse Schedule"));//Gas schedule
    l.append(tr("Pulse Real View Advanced"));//Gas schedule



    l.append(tr("Serial Port"));
    l.append(tr("Tcp Service"));
    l.append(tr("General Settings"));
    l.append(tr("Devices table"));
    l.append(tr("Interface Logs"));
    l.append(tr("Events"));
    l.append(tr("502 Service State"));

    //m2m service
    l.append(tr("Http API keys"));
    l.append(tr("Http General"));
    l.append(tr("Http Events"));
    l.append(tr("Http Service History"));

    l.append(tr("M2M Events"));

    return l;

}

//---------------------------------------------------------------------

QStringList MatildaDeviceTree::lDevPollProtocolV11Path2icon()
{
    QStringList l;
//    l.append( ":/katynko/svg4/actionview026.svg"); Gas meters
//    l.append( ":/katynko/svg4/actionview026.svg");
//    l.append( ":/katynko/svg4/actionview026.svg");

    l.append( ":/katynko/svg5/gtk-index.svg");
    l.append( ":/katynko/svg2/dashboard-show.svg");
    l.append( ":/katynko/svg/format-list-ordered.svg");



    l.append( ":/katynko/svg5/lc_tabdialog.svg");
    l.append( ":/katynko/svg/network-disconnect.svg");
    l.append( ":/katynko/svg2/configure.svg");
    l.append( ":/katynko/svg5/sc_inserttable.svg");
    l.append( ":/katynko/svg/view-list-text.svg");
    l.append( ":/katynko/svg2/view-readermode-gr2.svg" );

    l.append( ":/katynko/svg/edit-table-insert-row-below.svg");


    //m2m service
    l.append( ":/katynko/svg5/jo01-http.svg" );
    l.append( ":/katynko/svg5/run-build-http.svg" );
    l.append( ":/katynko/svg5/view-readermode-http.svg" );
    l.append( ":/katynko/svg5/lc_dbtableedit-http.svg" );

    l.append( ":/katynko/svg5/view-readermode-http.svg" );

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

    l.append( QString("System") );
    l.append( QString("Network interfaces") );
    l.append( QString("Running process") );
    l.append( QString("Application events") );
    l.append( QString("GSM/PPP") );
    l.append( QString("TCP settings") );
    l.append( QString("ZigBee") );
    l.append( QString("Packet manager") );
    l.append( QString("Serial log stream") );
    l.append( QString("Serial log") );

    l.append( QString("Meter plugin") );
    l.append( QString("Statistic of exchange")   );
    l.append( QString("Poll events") );
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
    l.append( QString("Meters") );
    l.append( QString("Schedule") );
    l.append( QString("Database") );
    l.append( QString("Meter logs") );//do not delete here!
    l.append( QString("Hash summ" ) );//do not delete here!
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
    l.append(lDevPollProtocolV6RealNames());//starts at 64

    l.append(lDevPollProtocolV7RealNames());//starts at 70

    l.append(lDevPollProtocolV8RealNames());//starts at 75

    l.append(lDevPollProtocolV9RealNames());//starts at 84
    l.append(lDevPollProtocolV11RealNames());//starts at 84

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

    l.append( tr("System") );
    l.append( tr("Network interfaces") );
    l.append( tr("Running processes") );
    l.append( tr("Main events") );
    l.append( tr("GSM/PPP") );
    l.append( tr("TCP settings") );
    l.append( tr("ZigBee") );
    l.append( tr("Packet manager") );
    l.append( tr("Stream of the coordinator")); //tr("Serial log stream") );
    l.append( tr("Log of the coordinator") );

    l.append( tr("Supported meters") );
    l.append( tr("Exchange of the meters") );//Statistic of exchange
    l.append( tr("Poll events of the meters") );
    l.append( tr("Poll errors of the meters") );
    l.append( tr("Poll warnings of the meters") );

    l.append( tr("Simple BASH"));

    l.append( tr("Direct access service") );
    l.append( tr("Direct access client") );
    l.append( tr("M2M client") );

    l.append( tr("Commands") );
    l.append( tr("Authorization") );

    l.append( tr("Accessibility") );

    l.append( tr("Backup") );
    l.append( tr("Poll of the meters") );//"Poll"
    l.append( tr("Forwarding table of the meters"));//"Forwarding table"
    l.append( tr("Meters") );
    l.append( tr("Schedule") );//"Schedule"
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
    l.append(lDevPollProtocolV6LocalNames());
    l.append(lDevPollProtocolV7LocalNames());
    l.append(lDevPollProtocolV8LocalNames());
    l.append(lDevPollProtocolV9LocalNames());
    l.append(lDevPollProtocolV11LocalNames());


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
//v11
    l.append( QString("Pulse meters"));

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
    //v11
    l.append( tr("Pulse meters"));
    return l;
}

//---------------------------------------------------------------------

QHash<QString, QString> MatildaDeviceTree::hashRealName2localName()
{
    return UCDevTreeView::hashRealName2localName(localPageName() + localChapterName(), realPageName() + realChapterName());
}

//---------------------------------------------------------------------

QHash<QString, QString> MatildaDeviceTree::hashLocalName2realName()
{
    return UCDevTreeView::hashLocalName2realName(localPageName() + localChapterName(), realPageName() + realChapterName());

}
//---------------------------------------------------------------------
QMap<QString, QString> MatildaDeviceTree::getHashRealName2ico()
{
    return UCDevTreeView::getHashRealName2ico(listPath2icon(), realPageName());


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
    listInt.append( COMMAND_WRITE_GPRS_SETT );
    listInt.append( COMMAND_WRITE_TCP_SETT   );
    listInt.append( COMMAND_WRITE_ZIGBEE_SETT );
    listInt.append( COMMAND_WRITE_UPGRADE );
    listInt.append( 0 );
    listInt.append( 0 );    
    listInt.append( 0 );//exchange
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
    listInt.append( COMMAND_WRITE_METER_LIST_FRAMED );
    listInt.append( COMMAND_WRITE_POLL_SCHEDULE );
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
    listInt.append(getPageCanWriteDevPollProtocolV6());
    listInt.append(getPageCanWriteDevPollProtocolV7());
    listInt.append(getPageCanWriteDevPollProtocolV8());
    listInt.append(getPageCanWriteDevPollProtocolV9());

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
    listInt.append( COMMAND_READ_SYSTEM_SETTINGS );
    listInt.append( COMMAND_READ_IFCONFIG );
    listInt.append( COMMAND_READ_TASK_INFO );
    listInt.append( COMMAND_READ_APP_LOG );
    listInt.append( COMMAND_READ_GPRS_SETT );
    listInt.append( COMMAND_READ_TCP_SETT );
    listInt.append( COMMAND_READ_ZIGBEE_SETT   );
    listInt.append( 0 );
    listInt.append( 0 );
    listInt.append( COMMAND_READ_SERIAL_LOG );
    listInt.append( COMMAND_READ_ABOUT_PLG );
    listInt.append( COMMAND_READ_POLL_STATISTIC );
    listInt.append( COMMAND_READ_ZBR_LOG );
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

    listInt.append( COMMAND_READ_METER_LIST_FRAMED );
    listInt.append( COMMAND_READ_POLL_SCHEDULE );

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
    listInt.append(getPageCanReadDevPollProtocolV6());
    listInt.append(getPageCanReadDevPollProtocolV7());
    listInt.append(getPageCanReadDevPollProtocolV8());
    listInt.append(getPageCanReadDevPollProtocolV9());

    return listInt;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWriteSvahaOnly()
{
    QList<int> l;
    //svaha-sync
    l << COMMAND_WRITE_M2MSRVS_CONN_SETT << COMMAND_WRITE_M2MSRVS_BACKUP_SETT << 0 << 0;

    //ntp-service
    l << COMMAND_WRITE_SNTP_SETT << 0 << 0 << 0 << 0;
    return l;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadSvahaOnly()
{
    QList<int> l;
    //svaha-service
    l << COMMAND_READ_M2MSRVS_CONN_SETT << COMMAND_READ_M2MSRVS_BACKUP_SETT << COMMAND_READ_M2MSRVS_CONNECTLIST << COMMAND_READ_M2MSRVS_BACKUPLIST_FRMD;
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

QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV6()
{
//    l.append(tr("Database IP Rules"));

//    l.append(tr("Lamp's tasks"));
//    l.append(tr("Rescue schedules"));//Water meters
//    l.append(tr("Lamps's searcher"));
    return QList<int>() << COMMAND_WRITE_CALC_SUMM_4THISIPS << COMMAND_WRITE_FIREFLY_TABLE_SETT << COMMAND_WRITE_GROUP_RESCUE_SCHEDULE << 0 << 0 << COMMAND_WRITE_PROXYSETTINGS;


}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV6()
{
    return QList<int>() << COMMAND_READ_CALC_SUMM_4THISIPS << COMMAND_READ_FIREFLY_TABLE_SETT << COMMAND_READ_GROUP_RESCUE_SCHEDULE << COMMAND_READ_FIREFLY_STATUS_NDT << COMMAND_READ_FIREFLY_SCHEDULESTATE << COMMAND_READ_PROXYSETTINGS;

}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV7()
{
    //protocol v7
    return QList<int>() << 0 << COMMAND_WRITE_ELMETER_POLL_CHANNELS  << COMMAND_SET_SAVED_M2M_PROFILES << COMMAND_WRITE_IFACESETT_4_GROUPS << COMMAND_WRITE_IFACESETT_4_CHANNELS   ;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV7()
{
    return QList<int>() << COMMAND_READ_METER_EXCHANGE_LOG << COMMAND_READ_ELMETER_POLL_CHANNELS << COMMAND_GET_SAVED_M2M_PROFILES << COMMAND_READ_IFACESETT_4_GROUPS << COMMAND_READ_IFACESETT_4_CHANNELS;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV8()
{
    //protocol v8
    return QList<int>() << COMMAND_WRITE_TCP_MEDIUM_SERVICE << COMMAND_WRITE_GSM_NOTIFICATIONS << 0 << 0 << 0
                        << 0 << 0 << 0 << COMMAND_WRITE_RV_ELMETERS_RULES;
}

//---------------------------------------------------------------------

QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV8()
{
    return QList<int>() << COMMAND_READ_TCP_MEDIUM_SERVICE << COMMAND_READ_GSM_NOTIFICATIONS << COMMAND_READ_MATILDA_UART_LOG << COMMAND_READ_TCP_MEDIUM_SERVICE_LOGS << COMMAND_READ_PEREDAVATOR_APP_LOG
                        << COMMAND_READ_PEREDAVATOR_CLNT_STATE  << COMMAND_READ_UC_CLNT_STATE << COMMAND_READ_DA_ADDITIONAL_CHANNEL_LOGS << COMMAND_READ_RV_ELMETERS_RULES;
}

QList<int> MatildaDeviceTree::getPageCanWriteDevPollProtocolV9()
{
    return QList<int>() << COMMAND_WRITE_ENERGY_MONITORS_LIST << COMMAND_SET_DBLIMITS << 0;
}

QList<int> MatildaDeviceTree::getPageCanReadDevPollProtocolV9()
{
    return QList<int>() << COMMAND_READ_ENERGY_MONITORS_LIST << COMMAND_GET_DBLIMITS << COMMAND_READ_SQLT_MEDIUM_LOG;

}

//---------------------------------------------------------------------
