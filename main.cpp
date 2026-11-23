
#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

int main (){
    cpr::Url URL{
    "http://www.dnd5eapi.co/api/"
     "monsters/giant-spider"
    };


    cpr::Response Res{cpr::Get(URL)};



   cout<<"Status"<<Res.status_code<<'\n';

    json Doc= json::parse(Res.text);

    cout<<Doc.at("name").get<string>()<<'\n';
    cout <<Doc.at("desc").get<string>()<<'\n';
    cout<<Doc.at("type").get<string>()<<'\n';    
    cout<<Doc.at("strength").get<int>()<<'\n';


}
