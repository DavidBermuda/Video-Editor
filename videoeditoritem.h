/* VideoEditorItem
 * Copyright (C) 2012 Thiago Sousa Santos <thiago.sousa.santos@collabora.co.uk>
 * Copyright (C) 2012 Robert Swain <robert.swain@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef VIDEOEDITORITEM_H
#define VIDEOEDITORITEM_H

#include <QObject>

extern "C" {
#include <ges/ges.h>
}

class VideoEditorItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uri READ getUri NOTIFY uriChanged)
    Q_PROPERTY(QString fileName READ getFileName NOTIFY fileNameChanged)
    Q_PROPERTY(quint64 inPoint READ getInPoint NOTIFY inPointChanged)
    Q_PROPERTY(quint64 duration READ getDuration NOTIFY durationChanged)
public:
    explicit VideoEditorItem(QObject *parent = 0);
    virtual ~VideoEditorItem();

    QString getUri() const;
    void setUri(QString uri);
    QString getFileName() const;
    void setFileName(QString fileName);
    quint64 getInPoint() const;
    void setInPoint(quint64 inPoint);
    quint64 getDuration() const;
    void setDuration(quint64 duration);
    GESTimelineFileSource *getTlfs() const;
    void setTlfs(GESTimelineFileSource *tlfs);
    unsigned long getDurHdlrID() const;
    void setDurHdlrID(unsigned long handler_id);

signals:

    void uriChanged();
    void fileNameChanged();
    void inPointChanged();
    void durationChanged(VideoEditorItem*);

public slots:

private:
    GESTimelineFileSource *m_tlfs;
    QString m_uri;
    QString m_fileName;
    quint64 m_inPoint;
    quint64 m_duration;
    unsigned long m_dur_hdlr_id;

    Q_DISABLE_COPY(VideoEditorItem)
};

#endif // VIDEOEDITORITEM_H
