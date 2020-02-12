// FILE: sequence4.h
// TEMPLATE CLASS PROVIDED:
//   sequence<Item> (part of the namespace main_savitch_6B)
//   This is a container class for a sequence of items,
//   where each List may have a designated item called the current item).
//   The template parameter <value_type> is the data type of the items
//   in the List. It may be any of the C++ built-in types (int, char, etc.),
//   or a class with a default constructor, an assignment operator,
//   and a copy constructor.
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   sequence<Item>::value_type
//     This is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   sequence<Item>::size_type
//     This is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
// CONSTRUCTOR for the sequence<Item> class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence<Item> class:


//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence<Item> class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#ifndef MAIN_SAVITCH_SEQUENCE4_H
#define MAIN_SAVITCH_SEQUENCE4_H
#include <cstdlib>  // Provides size_t
#include "node2.h"  // Provides node class

namespace main_savitch_6B
{
    template <class Item>
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef Item value_type;
        typedef std::size_t size_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence( );
        sequence(const sequence& source);
	    ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void operator =(const sequence& source);
	void remove_current( );
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return many_nodes; }
        bool is_item( ) const { return (cursor != NULL); }
        value_type current( ) const;
    private:
	node<Item> *head_ptr;
	node<Item> *tail_ptr;
	node<Item> *cursor;
	node<Item> *precursor;
	size_type many_nodes;
    };

    //implement functions here
    template <class Item>
    void list_piece(
	const node<Item>* start_ptr, const node<Item>* end_ptr,
	node<Item>*& head_ptr, node<Item>*& tail_ptr
    )
    // Precondition: start_ptr and end_ptr are pointers to nodes on the same
    // linked list, with the start_ptr node at or before the end_ptr node.
    // Postcondition: head_ptr and tail_ptr are the head and tail pointers
    // for a new list that contains the items from start_ptr up to but
    // not including end_ptr.  The end_ptr may also be NULL, in which case
    // the new list contains elements from start_ptr to the end of the list.
    // Library facilities used: cstdlib
    {
    head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (start_ptr == end_ptr)
	    return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, start_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	start_ptr = start_ptr->link( );
	while (start_ptr != end_ptr)
	{
	    list_insert(tail_ptr, start_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    start_ptr = start_ptr->link( );
	}

    }

    template <class Item>
    sequence<Item>::sequence( )
    // Library facilities used: cstdlib
    {
    head_ptr = tail_ptr = cursor = precursor = NULL;
	many_nodes = 0;
    }

    template <class Item>
    sequence<Item>::sequence(const sequence& source)
    // Library facilities used: cstdlib, node1.h
    {
    if (source.cursor == NULL)
	{   // There is no current item in the source list:
	    list_copy(source.head_ptr, head_ptr, tail_ptr);
	    cursor = precursor = NULL;
	}
	else if (source.precursor == NULL)
	{   // The current item in the source is at its head:
	    list_copy(source.head_ptr, head_ptr, tail_ptr);
	    cursor = head_ptr;
	    precursor = NULL;
	}
	else
	{   // The current item in the source is not at its head:
	    list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
	    list_piece(source.cursor, (node<double>*)NULL, cursor, tail_ptr);
	    precursor->set_link(cursor);
	}
        many_nodes = source.many_nodes;

    }

    template <class Item>
    sequence<Item>::~sequence( )
    // Library facilities used: node1.h
    {
    list_clear(head_ptr);
    many_nodes = 0;
    }
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
    template <class Item>
    void sequence<Item>::start( )
    // Library facilities used: cstdlib
    {
        //How do you set precursor and cursor?

    }

//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
    template <class Item>
    void sequence<Item>::advance( )
    // Library facilities used: node1.h
    {

    }

//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
    template <class Item>
    void sequence<Item>::insert(const value_type& entry)
    // Library facilities used: cstdlib, node1.h
    {

    }

//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
    template <class Item>
    void sequence<Item>::attach(const value_type& entry)
    // Library facilities used: node1.h
    {

    }

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//
    template <class Item>
    void sequence<Item>::remove_current( )
    // Library facilities used: cassert, cstdlib, node1.h
    {

    }

    template <class Item>
    void sequence<Item>::operator =(const sequence& source)
    // Library facilities used: cstdlib, node1.h
    {
    if (this == &source)
            return;

	list_clear(head_ptr);
	if (source.cursor == NULL)
	{   // There is no current item in the source list:
	    list_copy(source.head_ptr, head_ptr, tail_ptr);
	    cursor = precursor = NULL;
	}
	else if (source.precursor == NULL)
	{   // The current item in the source is at its head:
	    list_copy(source.head_ptr, head_ptr, tail_ptr);
	    cursor = head_ptr;
	    precursor = NULL;
	}
	else
	{   // The current item in the source is not at its head:
	    list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
	    list_piece(source.cursor, (node<double>*)NULL, cursor, tail_ptr);
	    precursor->set_link(cursor);
	}
        many_nodes = source.many_nodes;

    }

//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and
//     the item after this (if there is one) is now the new current item.
//
    template <class Item>
    Item sequence<Item>::current( ) const
    // Library functions used: cassert, node1.h
    {


    }

}

#endif

