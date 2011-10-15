#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <ui_mainwindow.h>

#ifdef FREE
# include "settings.h"
#else
# include <QtGui/QBoxLayout>
#endif
#include "vocabulary.h"
#ifndef FREE
# include "plugins.h"
# include <QtGui/QSystemTrayIcon>
#endif
#include <QtCore/QTranslator>
#ifndef FREE
# include "license.h"
#endif

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
        ~MainWindow();
		MainWindow(QWidget *pParent = NULL, Qt::WindowFlags pFlags = 0);

	private:
		enum eTemplate {
			TemplateLearning
#ifndef FREE
			, TemplateTray
#endif
		}; // eTemplate

#ifndef FREE
		static const int FLASH_COUNT = 3;
		static const int FLASH_WAIT = 100;
		static const int MAX_NEXTRECORD_TRIES = 9999;
#endif
		static const int MILISECONDS_PER_SECOND = 1000;
        static const int RECORD_NONE = -1;
#ifndef FREE
        static const int SAY_BEEP_WAIT = 500;
#endif

		struct sAnswer {
			int iWord;
			bool bDirectionSwitched;
		}; // sAnswer

        typedef QHash<int, sAnswer> tAnswer;

		int _iCurrentRecordId;
        int _iTimerAnswer;
		int _iTimerQuestion;
#ifndef FREE
# ifndef TRY
        License *_lLicense;
# endif
		Plugins _pPlugins;
		QAction *_qaTrayExit;
        QAction *_qaTrayManage;
        QAction *_qaTraySettings;
#endif
        QHash<int, int> _qhCurrentAnswer;
#ifndef FREE
        QHBoxLayout *_qhblInner;
#endif
        QLabel _qlVocabularyStatus;
#ifndef FREE
		QMenu _qmTray;
        QSystemTrayIcon _qstiTrayIcon;
#endif
		QTranslator _qtTranslator;
		Settings _sSettings;
        tAnswer _taHash;
		Ui::qmwUiMain _umwMainWindow;
        Vocabulary _vVocabulary;

        const void ApplySettings(const bool &pStartup);
#ifndef FREE
		const void CreateTrayMenu();
#endif
        const void EnableControls();
		virtual bool event(QEvent *event);
        const QString GetLanguageText(const bool &pDirectionSwitched, const bool &pAnswer) const;
		const bool GetLearningDirection() const;
        const QString GetLearningText(const eTemplate &pTemplate, const bool &pDirectionSwitched, const bool &pAnswer) const;
#ifndef FREE
        const int GetRecordPriority() const;
#endif
        const void OpenVocabulary(
#ifndef FREE
            const bool &pCurrentRecord
#endif
            );
        const void RefreshStatusBar();
#ifndef FREE
# ifdef Q_WS_WIN
        const void RegisterHotkeys() const;
# endif
		const void Say(const bool &pDirectionSwitched, const bool &pAnswer) const;
#endif
        const void SetLayout();
#ifndef FREE
		const void SetRecordEnabled(const bool &pEnabled);
		const void SetRecordPriority(const int &pPriority);
		const void SetupRecordControls() const;
		const void ShowTrayBalloon(const bool &pDirectionSwitched, const bool &pAnswer);
#endif
		void timerEvent(QTimerEvent *event);

	private slots:
        const void on_qaAbout_triggered(bool checked = false);
#ifndef FREE
        const void on_qaAnswer_triggered(bool checked = false);
        const void on_qaFindInVocabulary_triggered(bool checked = false);
# ifndef TRY
        const void on_qaLicense_triggered(bool checked = false);
# endif
#endif
        const void on_qaManage_triggered(bool checked = false);
#ifndef FREE
        const void on_qaMute_toggled(bool checked);
#endif
        const void on_qaNew_triggered(bool checked = false);
		const void on_qaNext_triggered(bool checked = false);
#ifndef TRY
        const void on_qaOpen_triggered(bool checked = false);
#endif
		const void on_qaSettings_triggered(bool checked = false);
		const void on_qaStart_triggered(bool checked = false);
		const void on_qaStop_triggered(bool checked = false);
#ifndef FREE
		const void on_qcbRecordEnabled_clicked(bool checked = false);
		const void on_qmTray_triggered(QAction *action);
		const void on_qstiTrayIcon_activated(QSystemTrayIcon::ActivationReason reason);
		const void on_qtbPriority1_clicked(bool checked = false);
		const void on_qtbPriority2_clicked(bool checked = false);
		const void on_qtbPriority3_clicked(bool checked = false);
		const void on_qtbPriority4_clicked(bool checked = false);
		const void on_qtbPriority5_clicked(bool checked = false);
		const void on_qtbPriority6_clicked(bool checked = false);
		const void on_qtbPriority7_clicked(bool checked = false);
		const void on_qtbPriority8_clicked(bool checked = false);
		const void on_qtbPriority9_clicked(bool checked = false);
#endif
#if !defined(FREE) && defined(Q_WS_WIN)
		virtual bool winEvent(MSG *message, long *result);
#endif
}; // MainWindow

#endif // MAINWINDOW_H