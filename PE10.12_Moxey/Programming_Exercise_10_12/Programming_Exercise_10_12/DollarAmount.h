// DollarAmount.h
// DollarAmount class stores dollar amounts as a whole numbers of pennies
#include <string>
#include <cmath> 

class DollarAmount {
public:
    // ========== constructors ==========
    // initialize with money value expressed in cents
    explicit DollarAmount(int64_t value = 0) : amount{ value } { }

    // initialize amount from whole number of dollars and number of cents
    DollarAmount(int64_t dollars, int64_t cents) { setAmount(dollars, cents); }

  
    // ========== set functions ==========
    // set amount with whole number of dollars and number of cents
    void setAmount(int64_t, int64_t);

    // set amount with money value expressed in cents
    void setAmount(int64_t);


    // ========== calculation functions ==========
    // add right's amount to this object's amount
    void add(DollarAmount right) { amount += right.amount; }

    // subtract right's amount from this object's amount
    void subtract(DollarAmount right) { amount -= right.amount; }

    //multiply a quanity by this amount
    void multiplyQuantity(int64_t quantity) { amount *= quantity; }

    //divide this amount by divisor
    void divideQuantity(int divisor) { amount = (amount + divisor / 2) / divisor; }

    // ---------- calculate interest and add result to amount ----------
    void addInterest(double);

    // ========== output conversion ==========
    // return a string representation of a DollarAmount object
    std::string toString() const;

    //overload aratimtic 
    DollarAmount& operator+(DollarAmount);
    DollarAmount& operator-(DollarAmount);
    DollarAmount& operator*(int64_t);
    DollarAmount& operator/(int);

    //get dollar amount object
    int64_t getAmount() const;


private:
    int64_t amount{ 0 }; // dollar amount in pennies

    // ============ utility function ===========
    // converts double percentage interest rate to integer version for use in addInterest
    // returns divisor for addInterest
    int convertRateToInt(double origRate, int& intRate);
};

