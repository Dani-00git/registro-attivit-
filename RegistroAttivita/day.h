#ifndef DAY_H
#define DAY_H
#include <QWidget>
#include <list>
#include <vector>
#include <activities.h>
#include <QDate>


class Day
{
public:
    Day(){}
    Day(QDate& data): data(data){}

    Day(QDate& data, Activities a): data(data){
        toDayActivities.push_back(a);
    }

    Day(const int giorno,const  int mese,const  int anno){
        this->data.setDate(giorno,mese,anno);
    }

    void addAttività(const Activities& nuovaAttività){
        toDayActivities.push_back(nuovaAttività);
    }/*
    Activities getActivity(const int i){
        std::list<Activities> a = toDayActivities;
        for(int j=0; j<i;j++)
            a.pop_front();
        return a.front();
    }*/
    Activities getActivity(const int i){
        return toDayActivities[i];
    }
    void setDate(QDate& data){
        this->data = data;
    }

    QDate getDate(){
        return data;
    }

    int numOfActivities(){
        return toDayActivities.size();
    }
    int getDay(){ return data.day();}
    int getMonth(){ return data.month();}
    int getYear(){ return data.year();}

private:
    QDate data;
    //std::list<Activities> toDayActivities;
    std::vector<Activities> toDayActivities;
};

#endif // DAY_H
