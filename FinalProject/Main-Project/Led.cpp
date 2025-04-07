/*
 *  This is proof of concept that I can add in c++ and inheritance to Arduino programming.
 *  OOP cannot be directly in the main file because it is C.
 *  LED counter is for bad number counter and output count is to count all inputs.
 */
class Led{
  public:
    int badCounter = 0;
    int dataCounter = 0;
    
  void badCounterIncrease(){
    badCounter++;
    }
    
  int badCounterNum(){
    return badCounter;
    }

  void dataCounterIncrease(){
    dataCounter++;
    }
  
  int dataCounterNum(){
    return dataCounter;
    }  
};

// Child Class
class Output : Led{
  public:
    int goodCounter = 0;

  void allCounterIncrease(){
    goodCounter++;
    }

  int goodCounterNum(){
    return goodCounter;
    }
};
