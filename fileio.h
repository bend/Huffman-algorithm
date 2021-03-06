/*
*   Copyright © Benoit Daccache
*   ben.daccache@gmail.com
*
*   This file is part of Huffman.
*
*   Huffman is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   Huffman is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with Huffman.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef FILEIO_H
#define FILEIO_H
#include <QFile>
#include <QDataStream>
#include <QHash>
#include <QString>

class FileIO
{
public:
    FileIO(QString str);
    void buildCharTable();
    void browseHashTable();
    inline QMap<char,int>* getMap(){return map;}

private:
    QString filename;
    QMap<char, int> *map;
};

#endif // FILEIO_H
