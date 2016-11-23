#include "GarbageCollector.h"

GarbageCollector::GarbageCollector(){ head= tail =NULL; } // Constructor sets head and tail to NULL

void GarbageCollector::addConnection(Connection * connection) 
{ // Add a new connection
	 if ( head == NULL ) // If head is null (List empty) point head and tail to the connection
		head=tail=connection;
	 else 
	 {// else add to the end and advance tail
		tail->setNextConnection(connection);
		tail = connection;
	 }
}
void GarbageCollector::cleanup() 
{// Clean up all finished threads
	Connection * cur = head; // set cur to head
	for ( ; cur!= NULL && !cur->isRunning(); ) 
	{ // Loop and delete all finished connection from the front of the list
		cur->waitForRunToFinish(); // Wait for the thread
		Connection * cur1 = cur; // get a pointer to it
		cur = cur->getNextConnection(); // Advance cur
		delete (cur1); // Delete finished thread
	}
	head = cur; // Set head to cur
	if ( head == NULL) tail=NULL; // If list is empty set tail to NULL
}

// Invoked upon program termination to Gracefully wait for all running threads to finish
void GarbageCollector::terminate() 
{
	Connection * cur = head; //set cur to jead
	for ( ; cur!= NULL; ) 
	{ // Loop on all connections
		cur->waitForRunToFinish(); // wait for the current connection to finish
		Connection * cur1 = cur; // get a pointer to it
		cur = cur->getNextConnection(); // advance cur
		delete (cur1); // delete the current connection
	}
	head = tail=NULL; // set head and tail to NULL as the list should be empty
}

GarbageCollector::~GarbageCollector() { terminate(); // Invoke terminate to dispose all connections}