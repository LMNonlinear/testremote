/*=========================================================================

 medInria

 Copyright (c) INRIA 2013 - 2018. All rights reserved.
 See LICENSE.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

=========================================================================*/
#pragma once

#include <medSingleFilterDoubleOperationProcessNode.h>
#include <medAbstractSubtractFilterProcess.h>

#include <medComposerExport.h>

class medSubtractFilterProcessNodePrivate;

class MEDCOMPOSER_EXPORT medSubtractFilterProcessNode : public medSingleFilterDoubleOperationProcessNode<medAbstractSubtractFilterProcess>
{
public:
     medSubtractFilterProcessNode();

     virtual QWidget *editor(void);
};


