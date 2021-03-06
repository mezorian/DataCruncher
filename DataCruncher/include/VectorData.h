/**
 * VectorData.h
 * Purpose: defines class VectorData
 *
 * @author Wall.Of.Death
 * @version 2.2
 */

#ifndef VectorData_H
#define VectorData_H

#include <iostream>
#include <vector>
#include <float.h>
#include <stdlib.h>

using namespace std;

/**
 * class VectorData
 */
class VectorData : public vector<double> {
    public:
        /* --- constructors / destructors --- */

        // standard - constructor
        VectorData(int     size_     =       0, bool   useCutOffToRange_ =   false,
                     double  minValue_ = DBL_MIN, double maxValue_         = DBL_MAX);

        // copy - constructor
        VectorData(const VectorData& other_, bool copyVectorData_ = true);

        // initializer - list - contructor
        VectorData(const initializer_list<double>& val_)
            : vector<double>(val_) {};

        /* --- miscellaneous --- */
        int    getSize       ()            const;
        double getValueAt    (int index_)  const;
        double cutOffToRange (double val_) const;
        bool   nearlyEqual   (double val1_, double val2_, double tolerance_) const;

        /* --- getter / setter --- */
        bool    getUseCutOffToRange () const    {return useCutOffToRange;};
        double  getMinValue         () const    {return minValue;        };
        double  getMaxValue         () const    {return maxValue;        };
        void    setUseCutOffToRange (bool val_) ;
        bool    setMinMaxValue      (double  min_, double max_);

        /* --- operators --- */
        VectorData& operator= (const VectorData& other_);
        bool        operator==(const VectorData& other_) const;
        bool        operator!=(const VectorData& other_) const;
        VectorData  operator+ (double val_) const;
        VectorData  operator- (double val_) const;
        VectorData  operator* (double val_) const;
        VectorData  operator/ (double val_) const;
        VectorData  operator+ (const VectorData& val_) const;
        VectorData  operator- (const VectorData& val_) const;
        VectorData  operator* (const VectorData& val_) const;
        VectorData  operator/ (const VectorData& val_) const;
        VectorData  operator+=(double val_);
        VectorData  operator-=(double val_);
        VectorData  operator*=(double val_);
        VectorData  operator/=(double val_);
        VectorData  operator+=(const VectorData& val_);
        VectorData  operator-=(const VectorData& val_);
        VectorData  operator*=(const VectorData& val_);
        VectorData  operator/=(const VectorData& val_);
        friend ostream& operator<<(ostream& ostream_, const VectorData VectorData_);
        friend ostream& operator<<(ostream& ostream_, vector<double> val_);

    private:
        bool   useCutOffToRange = false;
        double minValue         = DBL_MIN;
        double maxValue         = DBL_MAX;
};

#endif // VectorData_H
