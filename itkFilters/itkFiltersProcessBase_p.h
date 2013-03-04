#ifndef ITKFILTERSPROCESSBASE_P_H
#define ITKFILTERSPROCESSBASE_P_H

#include <dtkCore/dtkAbstractProcess.h>
#include <dtkCore/dtkAbstractProcess_p.h>
#include <dtkCore/dtkSmartPointer.h>
#include <dtkCore/dtkAbstractData.h>
#include <dtkLog/dtkLog.h>

#include "itkFiltersPluginExport.h"

#include "itkProcessObject.h"
#include "itkCommand.h"

class itkFiltersProcessBase;

class ITKFILTERSPLUGIN_EXPORT itkFiltersProcessBasePrivate : public dtkAbstractProcessPrivate
{
public:
    itkFiltersProcessBasePrivate(itkFiltersProcessBase *q = 0) : dtkAbstractProcessPrivate(q) {}
    itkFiltersProcessBasePrivate(const itkFiltersProcessBasePrivate& other) : dtkAbstractProcessPrivate(other) {}

    virtual ~itkFiltersProcessBasePrivate(void) {}
    
    itk::CStyleCommand::Pointer callback;
    itkFiltersProcessBase *filter;
    
    dtkSmartPointer<dtkAbstractData> input;
    dtkSmartPointer<dtkAbstractData> output;
    
    template <class PixelType> void setupFilter() {}
    virtual void setFilterDescription() {}
    
//    template <class PixelType> void update ( void ) {
//        this->setupFilter<PixelType>();
//        this->setFilterDescription();
//    }
    
    static void eventCallback ( itk::Object *caller, const itk::EventObject& event, void *clientData) {
        itkFiltersProcessBasePrivate * source = reinterpret_cast<itkFiltersProcessBasePrivate *> ( clientData );
        itk::ProcessObject * processObject = ( itk::ProcessObject* ) caller;
    
        if ( !source ) { dtkWarn() << "Source is null"; }
    
        source->filter->emitProgress((int) (processObject->GetProgress() * 100));
        
    }
};

DTK_IMPLEMENT_PRIVATE(itkFiltersProcessBase, dtkAbstractProcess)

#endif // ITKFILTERSPROCESSBASE_P_H
