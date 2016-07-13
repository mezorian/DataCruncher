/**
 * signal.h
 * Purpose: defines class Signal and enum ModificationType
 *
 * @author Wall.Of.Death
 * @version 1.0 20160713
 */

#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
#include <iostream>
#include <climits>

using namespace std;

/**
 * @brief The ModificationType enum
 * defines types of basis mathematical operations
 * this is needed for the implementation of Signal::modifySignal
 * and the implementation of mathematical operators
 */
enum ModificationType {ADD, SUBTRACT, MULTIPLY, DIVIDE, ADD_SIGNAL, SUBTRACT_SIGNAL, MULTIPLY_SIGNAL, DIVIDE_SIGNAL};

/**
 * class signal
 * @brief class inherited from std::vector which is for basic calculations on
 *
 */
class Signal : public vector<int>{
    public:
        /* --- constructors / destructors --- */

        // standard - constructor
        Signal(int  size_             =       0,   bool useMultiChannel_  =   false,
               int  channelsCount_    =       1,   int  selectedChannel_  =       0,
               bool useCutOffToRange_ =   false,   int  minValue_         = INT_MIN,
               int  maxValue_         = INT_MAX                                   );
        // copy - constructor
        Signal(const Signal& other_, bool copyVectorData_ = true); // copy-constructor

        /* --- miscellaneous --- */
        int getSize   ()           const;
        int getValueAt(int index_) const;

        template  <typename type>
        Signal modifySignal(ModificationType modificationType_, vector<type> val_ ) ;

        template  <typename type>
        type cutOffToRange(type val_);

        /* --- getter / setter --- */
        bool getUseMultiChannel  () const    { return useMultiChannel; };
        int  getChannelsCount    () const    { return channelsCount;   };
        int  getSelectedChannel  () const    { return selectedChannel; };
        bool getUseCutOffToRange () const    { return useCutOffToRange;};
        int  getMinValue         () const    { return minValue;        };
        int  getMaxValue         () const    { return maxValue;        };
        bool setSelectedChannel  (int  val_) ;
        bool setUseMultiChannel  (bool val_) ;
        bool setChannelsCount    (int  val_) ;
        void setUseCutOffToRange (bool val_) ;
        bool setMinMaxValue      (int  min_, int max_);

        /* --- operators --- */
        Signal& operator=(const Signal& other_);
        bool   operator==(const Signal& other_) const;
        bool   operator!=(const Signal& other_) const;
        Signal operator+(int val_) const;
        Signal operator-(int val_) const;
        Signal operator*(int val_) const;
        Signal operator/(int val_) const;
        Signal operator+(const Signal& val_) const;
        Signal operator-(const Signal& val_) const;
        Signal operator*(const Signal& val_) const;
        Signal operator/(const Signal& val_) const;
        friend ostream& operator<<(ostream& ostream_, const Signal signal_);
    private:
        bool useMultiChannel  = false;
        int  channelsCount    = 1;
        int  selectedChannel  = 0;
        bool useCutOffToRange = false;
        int  minValue         = INT_MIN;
        int  maxValue         = INT_MAX;
};

#endif // SIGNAL_H

'
4'
