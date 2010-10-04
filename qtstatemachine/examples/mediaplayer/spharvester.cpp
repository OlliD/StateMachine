
#include "spharvester.h"
#include <QDir>
#include <phonon>
#include <QQueue>
#include <QFile>
#include <QUrl>

using namespace Phonon;

struct SPHarvesterPvt
{
    MediaObject* mediaObject;
    QQueue<QString> pathQueue;
};

SPHarvester::SPHarvester(QObject* o) : QObject(o)
{
    pvt = new SPHarvesterPvt;
    pvt->mediaObject = new MediaObject(this);
    connect (pvt->mediaObject, SIGNAL(metaDataChanged()), this, SLOT(readMetaData ()));
}

SPHarvester::~SPHarvester()
{
    delete pvt;
}

void SPHarvester::harvest (const QString & directory, bool recurse)
{
    QDir d (directory);
    QFileInfoList l = d.entryInfoList(QStringList() << "*.mp3",recurse ? QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Files : QDir::Files);
    foreach (QFileInfo fi, l) {
        if (fi.isDir()) {
            harvest (fi.absoluteFilePath(), recurse);
        } else {
            pvt->pathQueue.enqueue(fi.absoluteFilePath());
        }
    }
    harvestNext ();
}

void SPHarvester::harvestNext ()
{
    if (pvt->pathQueue.empty())
        emit done();
    else {
        QString s = pvt->pathQueue.dequeue();
        pvt->mediaObject->setCurrentSource(MediaSource(s));
    }
}

void SPHarvester::readMetaData ()
{
    QStringList albums = pvt->mediaObject->metaData("ALBUM");
    QStringList titles = pvt->mediaObject->metaData("TITLE");
    QStringList artists = pvt->mediaObject->metaData("ARTIST");
    QStringList trackNums = pvt->mediaObject->metaData("TRACKNUMBER");
    SongData sd;
    sd.url = pvt->mediaObject->currentSource().url().toString();
    sd.album = albums.count() ? albums[0] : "Unknown Album";
    sd.artist = artists.count() ? artists[0] : "Unknown Artist";
    sd.trackNumber = trackNums.count() ? trackNums[0].toInt() : 0;
    sd.genres = pvt->mediaObject->metaData("GENRE");
    sd.title = titles.count() ? titles[0] : QFileInfo(sd.url).baseName();

    emit foundTrack(sd);
    harvestNext ();
}
