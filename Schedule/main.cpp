#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <cstdio>
#include <QtCore/QTextCodec>
#include <QtCore/QList>

#include "generatoridgenerator.h"
#include "event.h"

int main(int argc,char**argv)
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    try {
        QCoreApplication app(argc,argv);
        QFile file("/tmp/tmpfile.txt");
        QFile file2("/tmp/tmpfile2.txt");

        IDGenerator gen1=GeneratorIDGenerator::nextIDGenerator();
        IDGenerator gen2=GeneratorIDGenerator::nextIDGenerator();
        IDGenerator gen3=GeneratorIDGenerator::nextIDGenerator();
        
        IDGenerator::ID eventID=gen1.nextID();
        
        CompList<Term> terms;
        
        terms<<Term(eventID,QDate::currentDate());
        terms<<Term(eventID,QDate::currentDate());
        terms<<Term(eventID,QDate::currentDate());

        Event e1(eventID,gen2.nextID(),gen3.nextID(),terms);

        file.open(QIODevice::WriteOnly);
        QDataStream output(&file);

        output<<e1;
        
        file.close();
        file.open(QIODevice::ReadOnly);
        QDataStream input(&file);
        
        Event e2;
        input>>e2;
        
        file.close();
        file2.open(QIODevice::WriteOnly);
        QDataStream output2(&file2);
        
        output2<<e2;
        
        if(!(e1==e2))
            printf("Zapis jest niespójny!\n");
    }
    catch (char const* e)
    {
        printf("%s\n",e);
    }
    catch(QString e)
    {
        qDebug()<<e;
    }

    return 0;
}
