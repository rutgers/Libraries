/* 
	A median filter object is created by by passing the desired filter window size on object creation.
	The window size should be an odd number between 3 and 255.  
  
	New data is added to the median filter by passing the data through the in() function.  The new medial value is returned.
	The new data will over-write the oldest data point, then be shifted in the array to place it in the correct location. 
  
	The current median value is returned by the out() function for situations where the result is desired without passing in new data.
 
	!!! All data must be type INT.  !!!
 */

#ifndef IRFilter_h

	#define IRFilter_h

	#include "Arduino.h"

	class IRFilter
	{
		public:
			IRFilter(byte size, int seed);
			int in(int value);
			int out(); 
			int poly(int i);

			//void printData();		// used for debugging
			//void printSizeMap();
			//void printLocationMap();
			//void printSortedData();
			
		private:
			byte medFilterWin;		// number of samples in sliding median filter window - usually odd #
			byte medDataPointer;	// mid point of window
			int  * data;			// array pointer for data sorted by age in ring buffer
			byte * sizeMap;			// array pointer for locations data in sorted by size
			byte * locationMap;		// array pointer for data locations in history map
			byte oldestDataPoint;	// oldest data point location in ring buffer
			long A0;
			long A1;
			long A2;
			long A3;
			long A4;
			long A5;
      
	};

#endif
