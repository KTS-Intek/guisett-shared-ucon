#ifndef MATILDADEVICETREE_H
#define MATILDADEVICETREE_H

#include <QObject>
#include <QStringList>
#include <QHash>
#include <QMap>

class MatildaDeviceTree : public QObject
{
    Q_OBJECT
public:
    explicit MatildaDeviceTree(QObject *parent = nullptr);

    struct MatildaDevTreeView
    {
        QHash<QString,QStringList> h4devTree;
        QMap<QString, QString> hashRealName2ico;
        QStringList lKeyDevTree;
        MatildaDevTreeView() {}
        MatildaDevTreeView(const QHash<QString,QStringList> &h4devTree, const QMap<QString, QString> &hashRealName2ico, const QStringList &lKeyDevTree) :
            h4devTree(h4devTree), hashRealName2ico(hashRealName2ico), lKeyDevTree(lKeyDevTree) {}
    };



    static QStringList simplePagesList();

    static QStringList listPath2icon();

    static QStringList getListPath2iconMain();

    static QStringList getListRealMainNames();


    static QStringList realPageNameByDev(const int &devType, const int &protocolVersion);//en_GB

    static MatildaDevTreeView pageName4devTree();//en_GB


    static void addChapter(const QString &key, const QStringList &names, QStringList &lKeys, QHash<QString, QStringList> &h);

    static void addChapter(const QString &key, const QStringList &names, QStringList &lKeys, QHash<QString, QStringList> &h, QMap<QString, QString> &hashRealName2ico, const QString &icon);

    static QStringList infoNames();

    static QStringList commandNames();

    static QStringList pollDataNames();

    static QStringList networkSettNames();

    static QStringList generalSettNames();



    static QStringList electricNames();

    static QStringList waterNames();

    static QStringList prepaidNames();

    static QStringList smartLightNames();

    static QStringList m2mNames();

    static QStringList appNames();

    static QStringList realPageNameDevPoll(const int &protocolVersion);

    static QStringList realPageNameDevStor();

    static QStringList realPageNameDevPoll4staff();


    static QStringList realPageNameDevGate();

    static QStringList realPageNameDevEmul0();

    static QStringList realPageNameDevEmul1();

    static QStringList realPageNameDevEmul2();
    static QStringList realPageNameDevEmul3();

    static QStringList realPageNameDevSvaha();


    static QStringList lOnlySvahaSyncRealNames();
    static QStringList lOnlySvahaSyncLocalNames();
    static QStringList lOnlySvahaSyncPath2icon();

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


    static QStringList realPageName();//en_GB

    static QStringList localPageName();//local lang


    static QStringList realChapterName();//en_GB

    static QStringList localChapterName();//local lang


    static QHash<QString,QString> hashRealName2localName();

    static QHash<QString,QString> hashLocalName2realName();

    static QMap<QString, QString> getHashRealName2ico();


    static QList<int> getPageCanWrite();
    static QList<int> getPageCanRead();

    static QList<int> getPageCanWriteSvahaOnly();
    static QList<int> getPageCanReadSvahaOnly();

    static QList<int> getPageCanWriteDevPollProtocolV3();
    static QList<int> getPageCanReadDevPollProtocolV3();

    static QList<int> getPageCanWriteDevPollProtocolV4();
    static QList<int> getPageCanReadDevPollProtocolV4();

    static QList<int> getPageCanWriteDevPollProtocolV5();
    static QList<int> getPageCanReadDevPollProtocolV5();



    static QList<int> getPageCanWriteDevPollProtocolV6();
    static QList<int> getPageCanReadDevPollProtocolV6();

};

#endif // MATILDADEVICETREE_H
