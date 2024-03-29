#pragma once


#include "String.h"
#include "List.h"
#include "CSS.h"
#include "Command.h"


class CommandsInterpreter
{
private:
	List<Command> commands;
	CSS* css;

	String commandName;
	String* arguments;

public:
	CommandsInterpreter();
	CommandsInterpreter(CSS* css);

	void appendCommand(String commandName);
	Command parseCommand(String commandName);
	void printCommands();

	void executeCommands();
	void executeCommand(Command command);

	void printCommandResultIfNotEmpty(String commandResult) const;
	void printCommandResult(int commandResult) const;

	// Commands
	// ? (command)
	int getSectionsCount(); 
	void handleSectionsCountCommand();
	
	// i,S,? (command)
	int getSelectorsCount(int sectionIndex) const;
	void handleSelectorsCountBySectionIndexCommand();

	// z,S,? (command)
	int getSelectorsCount(String selectorName) const;
	void handleSelectorsCountBySelectorNameCommand();

	// i,S,j (command)
	String getSelectorName(int sectionIndex, int selectorIndex) const; // !!! SHOULD BE BLOCK INDEX
	void handleSelectorNameByBlockIndexAndSelectorIndexCommand();
	
	// i,A,? (command)
	int getDeclarationsCount(int sectionIndex) const;
	void handleDeclarationsCountBySectionIndexCommand();

	// n,A,? (command)
	int getPropertyCount(String propertyName) const;
	void handlePropertyCountByPropertyNameCommand();

	// i,A,n (command)
	String getPropertyValue(int sectionIndex, String propertyName) const;
	void handlePropertyValueBySectionIndexAndPropertyNameCommand();

	// z,E,n (command)
	String getPropertyValue(String selectorName, String propertyName) const;
	void handlePropertyValueBySelectorAndPropertyNameCommand();

	// i,D,* (command)
	void handleSectionDeletionCommand();

	// i,D,n (command)
	void handlePropertyDeletionCommand();
};

/* COMMANDS TO COVER

? � wypisz liczb� sekcji CSS;
[implemented; tested]

i,S,? � wypisz liczb� selektor�w dla sekcji nr i (numery zaczynaj� si� od 1), je�li nie ma takiego bloku pomi�;
[implemented, tests needed]

i,A,? - wypisz liczb� atrybut�w dla sekcji nr i, je�li nie ma takiego bloku lub sekcji pomi�;
[implemented, tests needed]

i,S,j � wypisz j-ty selector dla i-tego bloku (numery sekcji oraz atrybut�w zaczynaj� si� od 1) je�li nie ma sekcji lub selektora pomi�;
[temporarily implemented, tests needed]
(!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)
implement blocks
(!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)

i,A,n � wypisz dla i-tej sekcji warto�� atrybutu o nazwie n, je�li nie ma takiego pomi�;
[implemented, tests needed]

n,A,? � wypisz ��czn� (dla wszystkich blok�w) liczb� wyst�pie� atrybutu o nazwie n. (W ramach pojedynczego bloku duplikaty powinny zosta� usuni�te na etapie wczytywania). Mo�liwe jest 0;
(!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!)

z,S,? � wypisz ��czn� (dla wszystkich blok�w) liczb� wyst�pie� selektora z. Mo�liwe jest 0;
[implemented, tests needed]

z,E,n � wypisz warto�� atrybutu o nazwie n dla selektora z, w przypadku wielu wyst�pie� selektora z bierzemy ostatnie. W przypadku braku pomi�;
[implemented, tests needed]

i,D,* - usu� ca�� sekcj� nr i (tj. separatory+atrybuty), po poprawnym wykonaniu wypisz deleted;
[implemented, tests needed]

i,D,n � usu� z i-tej sekcji atrybut o nazwie n, je�li w wyniku operacji pozostaje pusta sekcja powinna zosta� r�wnie� usuni�ta (wraz z ew. selektorami), po poprawnym wykonaniu wypisz deleted.
[implemented, tests needed]

*/
