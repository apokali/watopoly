#include <vector>

class Player {
    
    
    public:
    void rollDice(bool tesingMode); // if tesing mode is true, ignore this fuction, since dice are read in
                            // if NOT in tims line rolls dice, then goes to the destination
                            //      if rolls doubles then sets Rollagain true and doubles counter ++1
                            //      if reaches to 3, sets Rollagain false, and goes to tims line directly
                            // if already in tims line, if no doubles occurs, sets number of turns in tims line ++ 1
                            //                          if double occurs, moves to the next destination
                            // if thrid turns in tims line, still no doubles, then ...
    void sentTo(int pos);   // sent to the designated position (NOT by rolling dice), also checks if the destination is DC tims line
                            // then you have to roll doubles to leave, and sets OSAPstatus to false
    bool checkRollAgain();  // check if you can roll dice again, returns false if you cannot
    void endTurn();         // ends a player's turn, but have to check if you can roll dice again, otherwise you cannot end the turn
                            // if you are in tims line, check the number of turns you are in this line
                            // if reaches to 3, then you leave
                            // if 
    void offerTrade();           // offer trade with another player
    void receiveTrade();        // receiver trade offer from another player
    void improve(AcademicBuilding ab);   // improve the ab, but first check if you have a monopoly first, otherwise you cannot improve,
    void mortage(Property p);        // mortage property
    void unmortage(Property p);      // unmortage property
    void checkBankrupcy();  // check if you are gonna pay money more than you have
    void delcareBankrupcy();// delcare, but fisrt check if you can sell properties or improvement to raise enough money, then reject it
    void asset();           // print the asset you have
    int getResidenceNum();  // number of residence a player has
    int getGymNum();        // number of gyms a player has
    int getNumBlockOwns(std::string blockName); // given a monopoly block name, returns total number of academic buildings that belong to a
                                                // monopoly
    void receiveMoney(int mon); //receives money
