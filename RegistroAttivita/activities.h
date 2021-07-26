#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Activities
{
public:
    Activities(){};

    Activities(QString in, QString fin, QString desc, int importanza)
        : importanza(importanza){
        descrizione = desc.toStdString();
        inizio = in.toStdString();
        fine = fin.toStdString();
    };

    std::string getInizio(){          return inizio;                      }
    std::string getFine(){            return fine;                        }
    std::string getDescrizione(){     return descrizione;                 }
    int getImportanza(){              return importanza;                  }

private:
    std::string inizio, fine;
    std::string descrizione;
    int importanza;
};

#endif // ACTIVITIES_H
