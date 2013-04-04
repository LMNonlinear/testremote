/*
 * medQtDataImage.h
 *
 *  Created on: 4 juil. 2011 10:29:14
 *      Author: John Stark
 */

#pragma once

#include "medTestExport.h"

#include <medCore/medAbstractDataImage.h>

class medQtDataImagePrivate;

/** A concrete implementation of a dtkAbstractDataImage for use in testing. */
class MEDTEST_EXPORT medQtDataImage : public medAbstractDataImage
{
    Q_OBJECT;
public:
    medQtDataImage();
    virtual ~medQtDataImage();
    virtual QString description() const;
    virtual QString identifier() const;

    static QString s_description();
    static QString s_identifier();
    static bool registered();

    // Implement dtkAbstractData
    virtual void setData(void* data);
    virtual void setData(void* data, int channel);
    virtual void *output();
    virtual void *data();
    virtual void *data(int channel);

    virtual       QImage & thumbnail()  ;
    virtual QList<QImage>& thumbnails() ;

    // Implement dtkAbstractDataImage
    void *image();

    virtual int   Dimension() const;
    virtual const PixId& PixelType() const;

    virtual int xDimension() const;
    virtual int yDimension() const;
    virtual int zDimension() const;
    virtual int tDimension() const;

    virtual qreal xSpacing() const;
    virtual qreal ySpacing() const;
    virtual qreal zSpacing() const;
    virtual qreal tSpacing() const;

    virtual int minRangeValue();
    virtual int maxRangeValue();

    virtual int scalarValueCount(int value);
    virtual int scalarValueMinCount();
    virtual int scalarValueMaxCount();
public:
protected:
    void generateThumbnails();
private:

    medQtDataImagePrivate * d;
};


