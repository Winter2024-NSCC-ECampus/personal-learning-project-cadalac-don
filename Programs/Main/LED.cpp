/*
 *  This is proof of concept that I can add in c++ and inheritance to Arduino programming.
 *  LED counter is for bad number counter and output count is to count all inputs.
 */
class LED{
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

class Output : LED{
  public:
    int goodCounter = 0;

  void allCounterIncrease(){
    goodCounter++;
    }

  int goodCounterNum(){
    return goodCounter;
    }
};
