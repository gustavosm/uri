#include <bits/stdc++.h>
 
 
using namespace std;
int findBestPack( const vector<pair<int , int> > & , 
      set<int> & , const int  ) ;
 
int main( ) {
   vector<pair<int , int> > items ;
   int n;
   int qtde;
   int peso;
   int cases;
   
   cin >> cases;
   
   while (cases--)
   {
   	   cin >> n;
   	   items.push_back(make_pair(0,0));
   	   for (int i = 0; i < n; i++)
   	   {
   	   		cin >> qtde >> peso;
   	   		items.push_back(make_pair(qtde,peso));
   	   		
   	   }
	   const int maximumWeight = 51 ;
	   set<int> bestItems ; 
	   int bestValue = findBestPack( items , bestItems , maximumWeight ) ;
	   cout << bestValue << " brinquedos\n" ;
	   int totalweight = 0 ;
	   for (set<int>::const_iterator si = bestItems.begin( ) ; 
		 si != bestItems.end( ) ; si++ ) { 
		  totalweight += (items.begin( ) + *si)->second ;
	   }
	   cout << "Peso: " << totalweight << " kg\nsobra(m) " << n - bestItems.size() << " pacote(s)\n\n" ;
   	   items.clear();
   }
   return 0 ;
}
 
int findBestPack( const vector<pair<int , int> > & items ,set<int> & bestItems , const int weightlimit ) {
   //dynamic programming approach sacrificing storage space for execution
   //time , creating a table of optimal values for every weight and a 
   //second table of sets with the items collected so far in the knapsack
   //the best value is in the bottom right corner of the values table,
   //the set of items in the bottom right corner of the sets' table.
   const int n = items.size( ) ;
   int bestValues [ n ][ weightlimit ] ;
   set<int> solutionSets[ n ][ weightlimit ] ;
   set<int> emptyset ;
   for ( int i = 0 ; i < n ; i++ ) {
      for ( int j = 0 ; j < weightlimit  ; j++ ) {
	 bestValues[ i ][ j ] = 0 ;
	 solutionSets[ i ][ j ] = emptyset ;
       }
    }
    for ( int i = 0 ; i < n ; i++ ) {
       for ( int weight = 0 ; weight < weightlimit ; weight++ ) {
	  if ( i == 0 )
	     bestValues[ i ][ weight ] = 0 ;
	  else  {
	     int itemweight = (items.begin( ) + i)->second ; 
	     if ( weight < itemweight ) {
		bestValues[ i ][ weight ] = bestValues[ i - 1 ][ weight ] ;
		solutionSets[ i ][ weight ] = solutionSets[ i - 1 ][ weight ] ;
	     } else { 
		if ( bestValues[ i - 1 ][ weight - itemweight ] + 
		   (items.begin( ) + i)->first >
		        bestValues[ i - 1 ][ weight ] ) {
		   bestValues[ i ][ weight ] = 
		       bestValues[ i - 1 ][ weight - itemweight ] + 
	        	(items.begin( ) + i)->first ;
		  solutionSets[ i ][ weight ] = 
		      solutionSets[ i - 1 ][ weight - itemweight ] ;
		  solutionSets[ i ][ weight ].insert( i ) ;
	     }
	     else {
		bestValues[ i ][ weight ] = bestValues[ i - 1 ][ weight ] ;
		solutionSets[ i ][ weight ] = solutionSets[ i - 1 ][ weight ] ;
	     }
	  }
       }
      }
    }
    bestItems.swap( solutionSets[ n - 1][ weightlimit - 1 ] ) ;
    return bestValues[ n - 1 ][ weightlimit - 1 ] ;
}
