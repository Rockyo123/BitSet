#include "bitset.hpp"
    
    //bitset constructor
    Bitset::Bitset()
    {
        bset = new int8_t[8];
        for(unsigned i = 0; i< 8; i++)
        {
            bset[i] = 0;
        }
        valid = true;
        bsetSize = 8;
    }

    //bitset constructor with size
    Bitset::Bitset(intmax_t size)
    {
        if(size > 0)
        {
            bset = new int8_t[size];
            for(unsigned i = 0; i< size; i++)
            {
                bset[i] = 0;
            }
            valid = true;
        }
        else if(size <= 0)
        {
            valid = false;
        }
        bsetSize = size;
    }

    //bitset constructor with string
    Bitset::Bitset(const std::string & value)
    {
        valid = true;
        bset = new int8_t[value.length()];
        bsetSize = value.length();
        int temp = 0;
        temp = stoi(value);
        int i = 0;
        for(int i = bsetSize - 1; i>= 0; i--)
        {
            bset[i] = temp%10;
            if(temp%10 != 0 || temp%10 != 1)
            {
                valid = false;
            }
            temp = temp/10;
        }
    }   

    //bitset destructor
    Bitset::~Bitset()
    {
        delete [] bset;
    }

    //return bitset size
    intmax_t Bitset::size() const
    {
        return bsetSize;
    }
     
    //returns if bitset is valid or not (includes only 1s and 0s)
    bool Bitset::good() const
    {
        return valid;
    }

    //sets bitset[index] to 1. If invalid index is sent in, set valid to false.
    void Bitset::set(intmax_t index)
    {
        if(index < bsetSize && index >= 0)
        {
            bset[index] = 1;
        }
        else
        {
           valid = false;
        }
    }

    //sets bitset[index] to 0.  If invalid index is sent in, set valid to false.
    void Bitset::reset(intmax_t index)
    {
        if(index < bsetSize && index >= 0)
        {
            bset[index] = 0;
        }
        else
        {
           valid = false;
        }
    }

    //toggles bitset[index] 1 -> 0. 0 -> 1.  If invalid index is sent in, set valid to false.
    void Bitset::toggle(intmax_t index)
    {
        if(index < bsetSize && index >= 0)
        {
            if(bset[index] == 1)
            {
                bset[index] = 0;
            }
            else if(bset[index] == 0)
            {
                bset[index] = 1;
            }
        }
        else
        {
           valid = false;
        } 
    }

    //returns true if bitset[index] == 1, false otherwise.  If invalid index is sent in, set valid to false.
    bool Bitset::test(intmax_t index)
    {
        if(index < bsetSize && index >= 0)
        {
            if(bset[index] == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
           valid = false;
           return false;
        } 
    }

    //returns bitset as a string, starting with leading 1.
    std::string Bitset::asString() const
    {
        bool oneFound = false;
        int leadingOne = 0;
        int i=0;
        while(i < bsetSize && !oneFound)
        {
            if(bset[i] == 1)
            {
                oneFound = true;
                leadingOne = i;
                i--;
            }
            i++;
        }

        int j = 0;
        std::string bsetString;
          while(j + leadingOne < bsetSize)
          {
            bsetString += std::to_string(bset[j + leadingOne]);
            j++;
          } 
        return bsetString;
    }
