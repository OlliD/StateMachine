#ifndef DOMPARSER_H
#define DOMPARSER_H

#include <QWidget>
#include <QDomDocument>
#include <QHash>
#include <QIcon>
#include <QTreeWidget>
#include <QList>
//#include <QtXml>
#include <QMainWindow>
#include <QMap>
#include <QSet>
#include <QTreeWidget>
#include <QDomNodeList>


class DOMParser : public QTreeWidget
{
    Q_OBJECT

public:
    DOMParser( QWidget *parent = 0);
    bool read(QIODevice *device, QDomDocument &document);
    bool write(QIODevice *device);

private slots:
    //void updateDomElement(QTreeWidgetItem *item, int column);

private:

    const static int loglevel = 1;

    void parseFolderElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem = 0 );
    QTreeWidgetItem *createItem(const QDomElement &element,
                                QTreeWidgetItem *parentItem = 0);
    QDomDocument domDocument;
    QHash<QTreeWidgetItem *, QDomElement> domElementForItem;
    void parse(QDomElement &element, QString tagName, QList< QMap<QString, QString> >* parsedData);
    void parseUtteranceRecursion(QDomElement &element, QString tagName, QMap<QString, QString>* utteranceList);
    void parseToWrite(QDomElement &child, QString tagName, QString data);
    void addItems(QDomElement &child, QList< QMap<QString, QString> >* parsedData);
    //QDomNodeList domList;

public slots:
    void parseElements( QDomDocument &document, QString tagName, QList< QMap<QString, QString> >* parsedData);
    void parseUtteranceFile( QDomDocument &document, QString tagName, QMap<QString, QString>* utteranceMap);
    //void updateElement( QDomDocument &document, QString tagName, QString data );
    void saveDocument( QDomDocument &document );
    void modifyElement( QDomDocument &document, QString tagName, QString data );
    void addElement(QString, QString);
    QString getElementByTag(QString&, QDomDocument &document);
    void createFile(QDomDocument &document);
};

#endif // DOMPARSER_H
