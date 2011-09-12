#ifndef SPINBOXDELEGATE_H
#define SPINBOXDELEGATE_H

#include <QtGui/QStyledItemDelegate>

class SpinBoxDelegate : public QStyledItemDelegate
{
	public:
		SpinBoxDelegate(QObject *pParent = NULL);

	private:
		static const int RECORD_PRIORITY_MAX = 9;
		static const int RECORD_PRIORITY_MIN = 1;

		virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
		virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
		virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
}; // SpinBoxDelegate

#endif // SPINBOXDELEGATE_H