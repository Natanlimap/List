#include <iostream>  // cout, endl
#include <cassert>   // assert()
#include "../include/list.h"

template < typename T = int >
sc::list<T> createVec( const sc::list<T> & _v )
{
    sc::list<T> temp( _v );
    return _v;
}

// The vector/iterator driver.
int main( void )
{
    auto n_unit{0};
    // Unit #1: default constructor
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": default constructor.\n";
        sc::list<int> seq;
        assert( seq.size() == 0 );
        assert( seq.empty() == true );
        std::cout << ">>> Passed!\n\n";
    }

    // Unit #2: constructor(size)
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": constructor(size).\n";
        sc::list<int> seq(10);
        assert( seq.size() == 10);
        assert( seq.empty() == false );
        std::cout << ">>> Passed!\n\n";
    }

//     // Unit #3: initializer list constructor
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": initializer list constructor.\n";
        sc::list<int> seq{ 1, 2, 3, 4, 5 };
        assert( seq.size() == 5 );
        assert( seq.empty() == false );
        
        // recover elements to test.
        // auto i{0};
        // for ( auto it = seq.begin() ; it != seq.end() ; ++it, ++i )
        //     assert( *it == i+1 );

        std::cout << ">>> Passed!\n\n";
    }

    // Unit #5: range constructor
    // {
    //     std::cout << ">>> Unit teste #" << ++n_unit << ": range constructor.\n";
    //     sc::list<int> seq{ 1, 2, 3, 4, 5 };
    //     sc::list<int> seq2( seq.begin(), seq.end() );
    //     assert( seq2.size() == 5 );
    //     assert( seq2.empty() == false );

    //     // recover elements to test.
    //     auto i{1};
    //     for( auto e : seq2 )
    //         assert ( e == i++ );

    //     // Copy only part of the original range.
    //     sc::list<int> vec3( std::next( seq.begin(), 1 ), std::next( seq.begin(), 3 ) );
    //     auto it2 = std::next( seq.begin(), 1 );
    //     for ( auto it = vec3.begin() ; it != vec3.end() ; ++it, ++it2 )
    //         assert( *it == *it2 );

    //     std::cout << ">>> Passed!\n\n";
    // }

//     // Unit: copy constructor
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": copy constructor.\n";
//         sc::list<int> seq{ 1, 2, 3, 4, 5 };
//         sc::list<int> seq2( seq );
//         assert( seq2.size() == 5 );
//         assert( seq2.empty() == false );

//         // recover elements to test.
//         auto i{1};
//         for( auto e : seq2 )
//             assert ( e == i++ );

//         // Changing seq (the original)...
//         auto it = std::next( seq.begin(), 2 );
//         *it = 10;
//         // ... should not alter the copy.
//         i = 1;
//         for( auto e : seq2 )
//             assert ( e == i++ );

//         std::cout << ">>> Passed!\n\n";
//     }

//     // Unit: move constructor
// #ifdef MOVE_SYNTAX_IMPLEMENTED
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": move constructor.\n";
//         sc::list<int> seq{ 1, 2, 3, 4, 5 };
//         sc::list<int> seq2( std::move( seq ) );
//         assert( seq2.size() == 5 );
//         assert( seq2.empty() == false );

//         // recover elements to test.
//         auto i{1};
//         for( auto e : seq2 )
//             assert ( e == i++ );

//         std::cout << ">>> Passed!\n\n";
//     }
// #endif

//     // Unit: Assign operator.
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": assign operator.\n";
//         sc::list<int> seq{ 1, 2, 3, 4, 5 };
//         sc::list<int> seq2;

//         seq2 = seq;
//         assert( seq2.size() == 5 );
//         assert( seq2.empty() == false );

//         // recover elements to test.
//         auto i{1};
//         for( auto e : seq2 )
//             assert ( e == i++ );

//         std::cout << ">>> Passed!\n\n";
//     }

//     // Unit: Move assign operator.
// #ifdef MOVE_SYNTAX_IMPLEMENTED
//     // 
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": move assign operator.\n";
//         sc::list<int> seq{ 1, 2, 3, 4, 5 };
//         sc::list<int> seq2;

//         seq2 = std::move( seq );
//         assert( seq2.size() == 5 );
//         assert( seq2.empty() == false );
//         assert( seq.size() == 0 );
//         assert( seq.empty() == true );

//         // recover elements to test.
//         auto i{1};
//         for( auto e : seq2 )
//             assert ( e == i++ );

//         std::cout << ">>> Passed!\n\n";
//     }
// #endif

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": initializer list assignment.\n";
//         sc::list<int> seq = { 1, 2, 3, 4, 5 };

//         assert( seq.size() == 5 );
//         assert( seq.empty() == false );

//         // recover elements to test.
//         auto i{1};
//         for( auto e : seq )
//             assert ( e == i++ );

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": clear().\n";
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         assert( seq.size() == 5 );
//         assert( seq.empty() == false );

//         seq.clear();
//         assert( seq.size() == 0 );
//         assert( seq.empty() == true );

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": push_front().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq;

//         assert( seq.empty() == true );
//         for ( auto i{0u} ; i < 5 ; ++i )
//         {
//             seq.push_front( i+1 );
//             assert( seq.size() == i+1 );
//         }
//         assert( seq.empty() == false );

//         auto i{5};
//         for ( const auto & e: seq )
//             assert( e == i-- );

//         seq.clear();
//         assert( seq.empty() == true );
//         for ( auto i{0u} ; i < 5 ; ++i )
//         {
//             seq.push_front( i+1 );
//             assert( seq.size() == i+1 );
//         }
//         assert( seq.empty() == false );
//         i = 5;
//         for ( const auto & e: seq )
//             assert( e == i-- );

//         std::cout << ">>> Passed!\n\n";

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": push_back().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq;

//         assert( seq.empty() == true );
//         for ( auto i{0u} ; i < 5 ; ++i )
//         {
//             seq.push_back( i+1 );
//             assert( seq.size() == i+1 );
//         }
//         assert( seq.empty() == false );

//         auto i{0};
//         for ( const auto & e: seq )
//             assert( e == ++i );

//         seq.clear();
//         assert( seq.empty() == true );
//         for ( auto i{0u} ; i < 5 ; ++i )
//         {
//             seq.push_back( i+1 );
//             assert( seq.size() == i+1 );
//         }
//         assert( seq.empty() == false );
//         i = 0;
//         for ( const auto & e: seq )
//             assert( e == ++i );

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": pop_back().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         while( not seq.empty() )
//         {
//             seq.pop_back();
//             // Checke whether we have the same list except for the last.
//             auto i {0};
//             for ( const auto & e: seq )
//                 assert( e == ++i );
//         }

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": pop_front().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         auto start{1};
//         while( not seq.empty() )
//         {
//             seq.pop_front();
//             // Check whether we have the same list except for the first.
//             auto i {start};
//             for ( const auto & e: seq )
//                 assert( e == ++i );

//             start++;
//         }

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": front().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         auto i{0};
//         while( not seq.empty() )
//         {
//             assert( seq.front() == ++i );
//             seq.pop_front();
//         }

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": back().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         auto i{5};
//         while( not seq.empty() )
//         {
//             assert( seq.back() == i-- );
//             seq.pop_back();
//         }

//         std::cout << ">>> Passed!\n\n";
//     }


//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": operator==().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };
//         sc::list<int> seq2 { 1, 2, 3, 4, 5 };
//         sc::list<int> vec3 { 1, 2, 8, 4, 5 };
//         sc::list<int> vec4 { 8, 4, 5 };

//         assert( seq == seq2 );
//         assert( not ( seq == vec3 ) );
//         assert( not ( seq == vec4 ) );
//         assert( seq == ( sc::list<int>{ 1, 2, 3, 4, 5 } ) );

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": operator!=().\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };
//         sc::list<int> seq2 { 1, 2, 3, 4, 5 };
//         sc::list<int> vec3 { 1, 2, 8, 4, 5 };
//         sc::list<int> vec4 { 8, 4, 5 };

//         assert( not( seq != seq2 ) );
//         assert( seq != vec3 );
//         assert( seq != vec4 );
//         assert( seq != ( sc::list<int>{ 1, 2, 3 } ) );

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": insert(pos, value).\n";

//         // #1 From an empty vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         seq.insert( seq.begin(), 0 );
//         assert( seq == ( sc::list<int>{ 0, 1, 2, 3, 4, 5 } ) );

//         std::cout << ">>> Passed!\n\n";
//     }

//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": insert(pos, first, last).\n";

//         // Aux arrays.
//         sc::list<int> seq1 { 1, 2, 3, 4, 5 };
//         sc::list<int> seq2 { 1, 2, 3, 4, 5 };
//         sc::list<int> source { 6, 7, 8, 9, 10 };

//         std::cout << ">>> seq1 size is: " << seq1.size() << '\n';
//         // Insert at the begining.
//         seq1.insert( seq1.begin(), source.begin(), source.end() );
//         std::cout << ">>> Seq1 == " << seq1 << std::endl;
//         std::cout << ">>> seq1 size is: " << seq1.size() << '\n';
//         assert( seq1 == ( sc::list<int>{ 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 } ) );
//         std::cout << ">>> Ok\n\n";

//         // In the middle
//         seq1 = seq2;
//         seq1.insert( std::next( seq1.begin(), 2 ), source.begin(), source.end() );
//         std::cout << ">>> Seq1 == " << seq1 << std::endl;
//         std::cout << ">>> seq1 size is: " << seq1.size() << '\n';
//         assert( seq1 == ( sc::list<int>{ 1, 2, 6, 7, 8, 9, 10, 3, 4, 5 } ) );
//         std::cout << ">>> Ok2\n\n";

//         // At the end
//         seq1 = seq2;
//         seq1.insert( seq1.end(), source.begin(), source.end() );
//         std::cout << ">>> Seq1 == " << seq1 << std::endl;
//         std::cout << ">>> seq1 size is: " << seq1.size() << '\n';
//         assert( seq1 == ( sc::list<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) );
//         std::cout << ">>> Ok3\n\n";


//         std::cout << ">>> Passed!\n\n";
//     }
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": insert(pos, initializer_list).\n";

//         // Aux arrays.
//         sc::list<int> seq1 { 1, 2, 3, 4, 5 };
//         sc::list<int> seq2 { 1, 2, 3, 4, 5 };
//         sc::list<int> source { 6, 7, 8, 9, 10 };

//         // Inset at the begining.
//         seq1.insert( seq1.begin(), { 6, 7, 8, 9, 10 } );
//         assert( seq1 == ( sc::list<int>{ 6, 7, 8, 9, 10, 1, 2, 3, 4, 5 } ) );

//         // In the middle
//         seq1 = seq2;
//         seq1.insert( std::next( seq1.begin(), 2 ), { 6, 7, 8, 9, 10 } );
//         assert( seq1 == ( sc::list<int>{ 1, 2, 6, 7, 8, 9, 10, 3, 4, 5 } ) );

//         // At the end
//         seq1 = seq2;
//         seq1.insert( seq1.end(), { 6, 7, 8, 9, 10 } );
//         assert( seq1 == ( sc::list<int>{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) );


//         std::cout << ">>> Passed!\n\n";
//     }
// #ifdef IGNORE_THIS
// // This method has the same signature as the assign( InItr, InItr ) of InItr is an integral type.
// // So, we must block this for a while (until C++11).
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": assign(count, value).\n";

//         // Initial vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         // assigning count values to sc::list, with count < size().
//         seq.assign( 3, -1 );
//         assert( seq == ( sc::list<int>{ -1, -1, -1 } ) );
//         assert( seq.size() == 3 );

//         // assigning count values to sc::list, with count == size().
//         seq = { 1, 2, 3, 4, 5 };
//         seq.assign( 5, -1 );
//         assert( seq == ( sc::list<int>{ -1, -1, -1, -1, -1 } ) );
//         assert( seq.size() == 5 );

//         // assigning count values to sc::list, with count > size().
//         seq = { 1, 2, 3, 4, 5 };
//         seq.assign( 8, -1 );
//         assert( seq == ( sc::list<int>{ -1, -1, -1, -1, -1, -1, -1, -1 } ) );
//         assert( seq.size() == 8 );

//         std::cout << ">>> Passed!\n\n";
//     }
// #endif
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": erase(first, last) and erase(pos).\n";

//         // Initial vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         // removing a segment from the beginning.
//         auto past_last = seq.erase( seq.begin(), std::next(seq.begin(),3) );
//         assert( seq.begin() == past_last );
//         assert( seq == ( sc::list<int>{ 4, 5 } ) );
//         assert( seq.size() == 2 );

//         // removing at the middle.
//         seq = { 1, 2, 3, 4, 5 };
//         past_last = seq.erase( std::next(seq.begin(),1), std::next(seq.begin(),4) );
//         assert( std::next(seq.begin(),1) == past_last );
//         assert( seq == ( sc::list<int>{ 1, 5 } ) );
//         assert( seq.size() == 2 );

//         // removing a segment that reached the end.
//         seq = { 1, 2, 3, 4, 5 };
//         past_last = seq.erase( std::next(seq.begin(),2), seq.end() );
//         assert( seq.end() == past_last );
//         assert( seq == ( sc::list<int>{ 1, 2 } ) );
//         assert( seq.size() == 2 );

//         // removing the entire vector.
//         seq = { 1, 2, 3, 4, 5 };
//         past_last = seq.erase( seq.begin(), seq.end() );
//         assert( seq.end() == past_last );
//         assert( seq.empty() );

//         std::cout << ">>> Passed!\n\n";
//     }
//     {
//         std::cout << ">>> Unit teste #" << ++n_unit << ": erase(pos).\n";

//         // Initial vector.
//         sc::list<int> seq { 1, 2, 3, 4, 5 };

//         // removing a single element.
//         seq = { 1, 2, 3, 4, 5 };
//         auto past_last = seq.erase( seq.begin() );
//         assert( seq == ( sc::list<int>{ 2, 3, 4, 5 } ) );
//         assert( seq.begin() == past_last );
//         assert( seq.size() == 4 );

//         // removing a single element in the middle.
//         seq = { 1, 2, 3, 4, 5 };
//         past_last = seq.erase( std::next(seq.begin(),2) );
//         assert( seq == ( sc::list<int>{ 1, 2, 4, 5 } ) );
//         assert( std::next(seq.begin(),2) == past_last );
//         assert( seq.size() == 4 );

//         // removing a single element at the end.
//         seq = { 1, 2, 3, 4, 5 };
//         past_last = seq.erase( std::next(seq.begin(),seq.size()-1 ) );
//         assert( seq == ( sc::list<int>{ 1, 2, 3, 4 } ) );
//         assert( seq.end() == past_last );
//         assert( seq.size() == 4 );

//         std::cout << ">>> Passed!\n\n";
//     }

    return 0;
}
