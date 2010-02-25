/**
 * See usercommands.h for overview.
 */

#include "usercommands.h"
#include "notefactory.h"
#include "noteselection.h"
#include "notedrag.h"
CmdDeleteNote::CmdDeleteNote(BasketView *currentBasket, QUndoCommand *parent) : QUndoCommand(parent) {
  this->currentBasket=currentBasket;
  zone = currentBasket->getNoteZoneToInsert();
  pos = currentBasket->getNotePosToInsert();

  NoteSelection *selection = currentBasket->selectedNotes();
  clicked = currentBasket->getNoteClickedToInsert();
  //if (selection->firstStacked()) {
  d=new QDrag(0);
  d->setMimeData((NoteDrag::dragObject(selection, true, /*source=*/0))->mimeData());
  //mimeData = d->mimeData();
    currentBasket->noteDeleteWithoutConfirmation();
    //}
}
void CmdDeleteNote::undo() {
  printf("in CmdDeleteNote::undo()");
  //The trick is to "paste" the note where it used to be.
  currentBasket->closeEditor();
  currentBasket->unselectAll();
  Note *note = NoteFactory::dropNote(d->mimeData()/*mimeData*/,currentBasket);
  if (note) {currentBasket->insertCreatedNote(note,clicked, zone, pos);}
  else {printf("Note was null\n");}
}
void CmdDeleteNote::redo() {
  currentBasket->noteDelete();
  printf("in CmdDeleteNote::redo()");
}
//CmdAddItem::CmdAddItem() {
//}
void CmdAddItem::undo() {
  printf("in CmdAddItem::undo()");
}
void CmdAddItem::redo() {
  printf("in CmdAddItem::redo()");
}
