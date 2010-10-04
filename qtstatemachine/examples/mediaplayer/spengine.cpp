
#include "spengine.h"
#include <phonon>

using namespace Phonon;

class SPEnginePvt
{
    public:
    MediaObject* mediaObject;
    AudioOutput* audioOutput;
};
void SPEngine::clearQueue()
{
    pvt->mediaObject->clearQueue();
}

int SPEngine::currentTime() const 
{
    return pvt->mediaObject->currentTime ();
}
int SPEngine::totalTime() const 
{
    return pvt->mediaObject->totalTime();
}

void SPEngine::enqueue (const QUrl & u)
{
    pvt->mediaObject->enqueue(MediaSource(u));
}
void SPEngine::setTrack(const QUrl & u)
{
    pvt->mediaObject->setCurrentSource(MediaSource(u));
}
void SPEngine::play()
{
    pvt->mediaObject->play ();
}

void SPEngine::pause()
{
    pvt->mediaObject->pause ();
}

void SPEngine::stop()
{
    pvt->mediaObject->stop();
}

void SPEngine::seek(qint64 pos)
{
    pvt->mediaObject->seek(pos);
}

void SPEngine::setVolume(int v)
{
    pvt->audioOutput->setVolume((qreal)v/100);
}

void SPEngine::onVolumeChanged(qreal r)
{
    emit volumeChanged(r*100);
}
int SPEngine::volume() const
{
    return pvt->audioOutput->volume()*100;
}

SPEngine::SPEngine(QObject* p) : QObject(p)
{
    pvt = new SPEnginePvt;
    pvt->mediaObject = new Phonon::MediaObject(this);
    pvt->audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    createPath (pvt->mediaObject, pvt->audioOutput);
    pvt->mediaObject->setTickInterval(500);
    connect (pvt->mediaObject, SIGNAL(aboutToFinish()), this, SIGNAL(aboutToFinish()));
    connect (pvt->mediaObject, SIGNAL(tick(qint64)), this, SIGNAL(tick(qint64)));
    connect (pvt->mediaObject, SIGNAL(totalTimeChanged(qint64)), this, SIGNAL(totalTimeChanged(qint64)));
    connect (pvt->audioOutput, SIGNAL(volumeChanged(qreal)), this, SLOT(onVolumeChanged(qreal)));
}

SPEngine::~SPEngine ()
{
    delete pvt;
}
