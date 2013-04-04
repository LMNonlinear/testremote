
#ifndef medAttachedData_h__
#define medAttachedData_h__

#include <medCore/medAbstractData.h>
#include "medCoreExport.h"

class medAttachedDataPrivate;

/**
 * Class to store attachments to datasets
 */
class MEDCORE_EXPORT medAttachedData : public medAbstractData
{
    Q_OBJECT

public:
    //! Constructor
    //\param parent : Set the parent which will own this dataset.
    medAttachedData( medAttachedData *parent = NULL );
    virtual ~medAttachedData();

    //! The data may be reference conted by a parent dataset.
    // This is not the parent in the Qt sense (it does not take ownership). The parentData reference counts this.
    medAbstractData * parentData() const;
    void setParentData( medAbstractData * mdata );

private:
    medAttachedDataPrivate* d;
};

#endif // medAttachedData_h__

