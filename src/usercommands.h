/**
 * usercommands.h
 * This collection of classes abstracts user interaction through
 * a collection of various classes.  Each class can maintain the
 * users state and provide undo and redo functionality.
 */

#include <QUndoCommand>
#include "basketview.h"
#ifndef CMDDELETENOTE_H
#define CMDDELETENOTE_H

/**
 * CmdDeleteNote deletes any type of note with various content
 */
class CmdDeleteNote : public QUndoCommand {
 public:
  CmdDeleteNote(BasketView * currentBasket, QUndoCommand *parent = 0);
  void undo();
  void redo();
 private:
  BasketView *currentBasket;
  QDrag *d;
  QMimeData * mimeData;
  Note *clicked;
  int zone;
  QPoint pos;
};
#endif

#ifndef CMDADDITEM_H
#define CMDADDITEM_H
/**
 * TODO
 */
class CmdAddItem : public QUndoCommand {
 public:
  void undo();
  void redo();
};

#endif

#ifndef CMDCUT_H
#define CMDCUT_H
/**
 * Replaces m_actCutNote, should generically replace cut action
 * for any object.
 */
class CmdCut : public QUndoCommand {
	public:
	CmdCut();
	void undo();
	void redo();
};
#endif
#ifndef CMDPASTE_H
#define CMDPASTE_H
class CmdPaste : public QUndoCommand {
	public:
	CmdPaste();
	void undo();
	void redo();
};
#endif

#ifndef CMDNEWBASKET_H
#define CMDNEWBASKET_H
/**
 * Replaces actNewBasket, actNewSubBasket, actNewSiblingBasket
 */
class CmdNewBasket : public QUndoCommand {
	public:
	int ACT_NEW=0;
	int ACT_NEWSUB=1;
	int ACT_NEWSIBLING=2;
	CmdNewBasket(int actiontype);
	void undo();
	void redo();
};
#endif

#ifndef CMDSELECTALL_H
#define CMDSELECTALL_H
/**
 * Replaces m_actSelectAll and m_actUnselectAll
 */
class CmdSelectAll : public QUndoCommand {
	public:
	CmdSelectAll();
	void undo();
	void redo();
};
#endif
