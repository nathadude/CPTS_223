#include <map>
#include "TwitterData.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower","Smit","Rick","smitRick@gmail.com","1117","power lifting"},
                             {"kittyKat72","Smith","Kathryn","kat@gmail.com","56","health"},
                             {"lexi5","Anderson","Alexis","lexi5@gmail.com","900","education"},
                             {"savage1","Savage","Ken","ksavage@gmail.com","17","president"},
                             {"smithMan","Smith","Rick","rick@hotmail.com","77","olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i) {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    //Scenario 1 Begin

    map<string, TwitterData> nameMap;
    for (int i = 0; i < 5; ++i) {
        nameMap[twitter_data[i].getUserName()] = twitter_data[i];
    }

    cout << "Initial map:" << endl;
    for (const auto& [key, value] : nameMap){
        cout << "Key: " << key << " Records: " << value.print() << endl;
    }

    cout << "searching for savage1:" << endl;
    cout << nameMap.find("savage1")->second.print() << endl;
    nameMap.erase("savage1");

    cout << "Map after delete:" << endl;
    for (const auto& [key, value] : nameMap){
        cout << "Key: " << key << " Records: " << value.print() << endl;
    }

    cout << endl << "Scenario 1 end" << endl << endl;

    //Scenario 1 End

    //Map Scenario 2 begin
    cout << "Map scenario 2 begin: " << endl << endl;
    //create map for email search
    map<string, TwitterData> emailMap;

    //add twitter data thru iterative loop
    for (int i = 0; i < 5; ++i)
    {
        emailMap[twitter_data[i].getEmail()] = twitter_data[i];
    }

    //print out the values
    cout << "Map before remove: " << endl;
    for (const auto& [key, value] : emailMap)
    {
        cout << "Key: " << key << "Info: " << value.print() << endl;
    }

    //search for email
    cout << endl << "Searching with key kat@gmail.com..." << endl;
    //print account details assoc with email key
    cout << emailMap.find("kat@gmail.com")->second.print() << endl << endl;

    cout << "Removing account associated with that email..." << endl;

    //remove account assoc with key
    emailMap.erase("kat@gmail.com");

    //test print to verify remove
    cout << "Map after remove: " << endl;
    for (const auto& [key, value] : emailMap)
    {
        cout << "Key: " << key << "Info: " << value.print() << endl;
    }

    cout << endl << "Map scenario end: " << endl;
    //Map Scenario 2 end

    return 0;
}
