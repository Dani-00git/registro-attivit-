#ifndef REGISTRO_H
#define REGISTRO_H
#include <vector>
#include <stdlib.h>
#include <day.h>
#include <QDate>

class registro
{
public:
    registro();

    bool addDay(Day nuovoGiorno){
        int find = searchDay(nuovoGiorno.getDate());
        if(find == -1){
            giorni.push_back(nuovoGiorno);
            return true;
            }
        return false;
    }

    int searchDay(const QDate data){
        int i=0;
        for(auto& itr : giorni){
            if (data.year() == itr.getDate().year() && data.month() == itr.getDate().month() && data.day() == itr.getDate().day())
                return i;
            i++;
        }
        return -1;
    }
    Day getDay(const int i){
        return giorni[i];
    }

private:
    std::vector<Day> giorni;
};

#endif // REGISTRO_H
