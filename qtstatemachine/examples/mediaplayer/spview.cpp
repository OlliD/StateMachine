
#include "spview.h"
#include "spmodel.h"
#include <QDebug>
#include <QItemDelegate>

class SPViewPvt
{
    public:
    SPModel* model;
};


class SPItemDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    SPItemDelegate(QObject* o) : QItemDelegate(o) {}

    virtual void paint (QPainter* p, QStyleOptionViewItem & option, const QModelIndex & index) const
    {
        QString disp = index.data(Qt::DisplayRole).toString();
        drawBackground(p,option,index);
        drawDisplay(p,option,option.rect,disp);
    }
};

void SPView::setModel (SPModel* m)
{
    pvt->model = m;    
}

void SPView::showAlbums ()
{
    listView->setModel (pvt->model->albumsItemModel());
}

void SPView::showArtists ()
{
    listView->setModel (pvt->model->artistsItemModel());
}

void SPView::showGenres ()
{
    QAbstractItemModel* model = pvt->model->genresItemModel();
    listView->setModel (model);
}

void SPView::showSongs ()
{
    listView->setModel (pvt->model->songsItemModel());
}

void SPView::showPlaylists()
{
    listView->setModel (pvt->model->playlistsItemModel());
}


SPView::SPView(QWidget* w) : QWidget (w)
{
    pvt = new SPViewPvt;
    setupUi(this);
    listView->setItemDelegate(new SPItemDelegate(this));
}

QString SPView::currentItem() const
{
    QVariant v = listView->model()->data(listView->currentIndex(),Qt::UserRole);
    if (v.isNull())
       v = listView->currentIndex().data(Qt::DisplayRole);
    return v.toString ();
}

int SPView::itemCount () const
{
    return listView->model()->rowCount ();
}
int SPView::currentIndex() const
{
    return listView->currentIndex().row();
}

void SPView::setTotalTime (int t)
{
    posSlider->setMaximum(t);
}
void SPView::setCurrentTime (int t)
{
    posSlider->setValue (t);
}

SPView::~SPView ()
{
    delete pvt;
}
#include "spview.moc"
