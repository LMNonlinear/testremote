/* medDatabaseView.cpp --- 
 * 
 * Author: Julien Wintz
 * Copyright (C) 2008 - Julien Wintz, Inria.
 * Created: Tue Mar 31 13:18:20 2009 (+0200)
 * Version: $Id$
 * Last-Updated: Sat Mar 20 20:03:03 2010 (+0100)
 *           By: Julien Wintz
 *     Update #: 97
 */

/* Commentary: 
 * 
 */

/* Change log:
 * 
 */

#include <medSql/medDatabaseModel.h>
#include <medSql/medDatabaseView.h>
#include <medSql/medDatabaseItem.h>

medDatabaseView::medDatabaseView(QWidget *parent) : QTreeView(parent)
{
    this->setAcceptDrops(true);
    this->setFrameStyle(QFrame::NoFrame);
    this->setAttribute(Qt::WA_MacShowFocusRect, false);
    this->setUniformRowHeights(true);
    this->setAlternatingRowColors(true);
    this->setAnimated(false);
    this->setSortingEnabled(true);

    this->setSelectionMode(QAbstractItemView::ExtendedSelection);

    this->header()->setStretchLastSection(true);

    connect(this, SIGNAL(      clicked(const QModelIndex&)), this, SLOT(onItemClicked(const QModelIndex&)));
    connect(this, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(onItemDoubleClicked(const QModelIndex&)));
}

medDatabaseView::~medDatabaseView(void)
{

}

void medDatabaseView::setModel(medDatabaseModel *model)
{
    QTreeView::setModel(model);
}

void medDatabaseView::onPatientClicked(int id)
{
    if(medDatabaseModel *model = dynamic_cast<medDatabaseModel *>(this->model())) {
        QModelIndex index = model->indexForPatient(id);
        this->collapseAll();
        this->setExpanded(index, true);
        selectionModel()->clearSelection();
        selectionModel()->select(index, QItemSelectionModel::Select);
    }
}

void medDatabaseView::onStudyClicked(int id)
{
    if(medDatabaseModel *model = dynamic_cast<medDatabaseModel *>(this->model())) {
        QModelIndex index = model->indexForStudy(id);
        this->collapseAll();
        this->setExpanded(index.parent(), true);
        this->setExpanded(index, true);
        selectionModel()->clearSelection();
        selectionModel()->select(index, QItemSelectionModel::Select);
    }
}

void medDatabaseView::onSeriesClicked(int id)
{
    if(medDatabaseModel *model = dynamic_cast<medDatabaseModel *>(this->model())) {
        QModelIndex index = model->indexForSeries(id);
        this->collapseAll();
        this->setExpanded(index.parent().parent(), true);
        this->setExpanded(index.parent(), true);
        this->setExpanded(index, true);
        selectionModel()->clearSelection();
        selectionModel()->select(index, QItemSelectionModel::Select);
    }
}

void medDatabaseView::onImageClicked(int id)
{
    if(medDatabaseModel *model = dynamic_cast<medDatabaseModel *>(this->model())) {
        QModelIndex index = model->indexForImage(id);
        this->collapseAll();
        this->setExpanded(index.parent().parent().parent(), true);
        this->setExpanded(index.parent().parent(), true);
        this->setExpanded(index.parent(), true);
        this->setExpanded(index, true);
        selectionModel()->clearSelection();
        selectionModel()->select(index, QItemSelectionModel::Select);
    }
}

void medDatabaseView::onItemClicked(const QModelIndex& index)
{
    medDatabaseItem *item = NULL;

    if(medDatabaseModel *model = dynamic_cast<medDatabaseModel *>(this->model()))
        item = static_cast<medDatabaseItem *>(index.internalPointer());

    if(item)
        if(item->table() == "patient")
            emit patientClicked(item->value(0).toInt());
        else if(item->table() == "study")
            emit studyClicked(item->value(0).toInt());
        else if(item->table() == "series")
            emit seriesClicked(item->value(0).toInt());
        else
            emit imageClicked(item->value(0).toInt());
}

void medDatabaseView::onItemDoubleClicked(const QModelIndex& index)
{
    medDatabaseItem *item = NULL;

    if(medDatabaseModel *model = dynamic_cast<medDatabaseModel *>(this->model()))
        item = static_cast<medDatabaseItem *>(index.internalPointer());

    if(item)
        if(item->table() == "patient") {
            emit patientDoubleClicked(item->value(0).toInt());
            emit patientDoubleClicked(index);
        }
        else if(item->table() == "study") {
            emit studyDoubleClicked(item->value(0).toInt());
            emit studyDoubleClicked(index);
        }
        else if(item->table() == "series") {
            emit seriesDoubleClicked(item->value(0).toInt());
            emit seriesDoubleClicked(index);
        }
        else {
            emit imageDoubleClicked(item->value(0).toInt());
            emit imageDoubleClicked(index);
        }
}
