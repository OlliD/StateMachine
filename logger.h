#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QObject>
#include <QDateTime>
#include <QFile>

class Logger : public QObject {

    Q_OBJECT

    private:
      //Ein Pointer zum Speichern der Instanz
      static Logger* instance;
      //Konstruktor private, damit man sich keine Instanzen holen kann.
      Logger(QString path);
      //Den Kopierkonstruktor schützen um zu vermeiden, dass das Objekt unbeabsichtigt kopiert wird.
      Logger(const Logger& cc);
      //~Logger();
      void logging(QString, int);
      int index;
      QDateTime *logtimer;
      QFile *logfile;
    public:
      int loglevel;

      static Logger& getInstance(QString path = "../../../log.txt");
      void log(QString, int);
      static void Destroy();

  public slots:
      void startTimer();
      void logWithState(QString);

};

#endif // LOGGER_H

