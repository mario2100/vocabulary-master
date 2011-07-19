#ifndef VOCABULARYTABWIDGET_H
#define VOCABULARYTABWIDGET_H

#include <QtGui/QTabWidget>
#ifndef FREE
# include <QtGui/QTabBar>
#endif

class VocabularyTabWidget : public QTabWidget
{
    Q_OBJECT

    public:
        VocabularyTabWidget(QWidget *pParent = NULL);

#ifndef FREE
        int addTab(QWidget *page, const QString &label, const bool &pEnabled);

    private:
        static const QTabBar::ButtonPosition POSITION_BUTTON_ENABLED = QTabBar::LeftSide;

    signals:
        void TabEnableChanged(const int &pIndex, const Qt::CheckState &pState) const;

    private slots:
        const void on_qcbEnabled_stateChanged(int state) const;
#endif
}; // VocabularyTabWidget

#endif // VOCABULARYTABWIDGET_H