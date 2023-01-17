#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>
#include <vector>

class Bitset{
public:

  /** Default constructor for Bitset. 
   @post creates Bitset with 8 bits of 0
  */
  Bitset();

   /** constructor for bitset that allows user to create a custom sized bitset of zeros. 
  @param size number of bits in the bitset being created. 
  @post creates Bitset with (size) bits of 0.
  */
  Bitset(intmax_t size);

   /** constructor for bitset that allows user to create a custom bitset from a string. 
  @param value the string that will become the bitset
  @post creates Bitset equal to value, , if any bits are not 0 or 1, the bitset is invalid.
  */
  Bitset(const std::string & value);

  /** destructor for bitset.
  @pre There is a Bitset in the program.
  @post The Bitset and all the data will be destroyed.
  */
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  /** method that will return the size of the current bitset
  @pre There is a valid Bitset in the program.
  @return number of bits in the current bitset as an int.
  */
  intmax_t size() const;

   /** method that will return if the current bitset is valid
  @pre There is a Bitset in the program.
  @return true if bitset is valid, false if not.
  */
  bool good() const;

   /** method that will set the (index) bit of bitset to 1.
  @pre There is a Bitset in the program.
  @post If index > 0 and Index < Bitset size, (index) bit of Bitset will be set to 1.
  */
  void set(intmax_t index);

   /** method that will set the (index) bit of bitset to 0.
  @pre There is a Bitset in the program.
  @post If index > 0 and Index < Bitset size, (index) bit of Bitset will be set to 0.
  */
  void reset(intmax_t index);

   /** method that will toggle the (index) bit of bitset.
  @pre There is a Bitset in the program.
  @post If index > 0 and Index < Bitset size, (index) bit of Bitset will be set to 1 if 0 and set to 0 if 1.
  */
  void toggle(intmax_t index);

   /** method that will check if (index) bit of bitset is equal to 1.
  @pre There is a Bitset in the program.
  @return True if index > 0 and Index < Bitset size, and (index) bit of Bitset is 1. False if 0.
  */
  bool test(intmax_t index);

   /** method that return the bitset as a string
  @pre There is a Bitset in the program.
  @return string of the bitset, with most significant bit first.
  */
  std::string asString() const;

private:

  int8_t *bset = nullptr; 
  int8_t bsetSize;
  bool valid;
};

#endif
