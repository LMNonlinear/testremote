/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2018. All rights reserved.
 See LICENSE.txt for details.
 
  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/

#pragma once

#include <itkDataTensorImageWriterBase.h>

#include <itkDataTensorImagePluginExport.h>

class ITKDATATENSORIMAGEPLUGIN_EXPORT itkNiftiDataTensorImageWriter : public itkDataTensorImageWriterBase
{
    Q_OBJECT

public:
    itkNiftiDataTensorImageWriter();
    virtual ~itkNiftiDataTensorImageWriter();

    virtual QString identifier()  const;
    virtual QString description() const;

    static bool registered();

    static dtkAbstractDataWriter* create();
};
